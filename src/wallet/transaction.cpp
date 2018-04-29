#include "stdafx.h"

/**
 * @brief Construct a new Transaction:: Transaction object
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
Transaction::Transaction()
{
    network = new Network();
    unspent_output = new utxo();
    
    m_utxoSum = 0;
};

/**
 * @brief Destroy the Transaction:: Transaction object
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
Transaction::~Transaction()
{
    delete network;
    delete unspent_output;
}

/**
 * @brief Creates output for a P2PKH transaction.
 * 
 * @param a_address bc::wallet::payment_address address that owns output
 * @param a_satoshis unsigned long long value of output
 * @return bc::chain::output 
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
bc::chain::output
Transaction::createOutputP2PKH(bc::wallet::payment_address a_address, unsigned long long a_satoshis)
{
    // Hash the Public Key of the Address. OP_DUP OP_HASH160 <PKH> OP_EQUALVERIFY OP_CHECKSIG
    bc::chain::script outputScript  = bc::chain::script().to_pay_key_hash_pattern(a_address.hash());

    // to_pay_key_hash_pattern creates an operation::list. Assignment constructor makes assigns it to outputScript.
    bc::chain::output output(a_satoshis,outputScript);

    return output;
};

/**
 * @brief Shows the transaction output.
 * 
 * @param output bc::chain::output output point
 *  
 * @author Philip Glazman
 * @date 4/28/18
 */
void
Transaction::showTxOutput(bc::chain::output output)
{
    std::cout << "Sending Bitcoin: \nAmount: " << bc::encode_base10(output.value(), 8) << "BTC : Output Script: " << output.script().to_string(0) << std::endl;
};

/**
 * @brief Outputs raw transaction into hex.
 * 
 * @param a_transaction
 * 
 * @author Philip Glazman
 * @date 4/28/18 
 */
void
Transaction::show_raw_tx(bc::chain::transaction a_transaction)
{
    std::cout << "Raw Transaction: " << std::endl;
	std::cout << bc::encode_base16(a_transaction.to_data()) << std::endl;
}

/**
 * @brief Creates an approximate size of the transaction in bytes using the number of inputs and outputs.
 * 
 * @param inputs, integer. Number of inputs in the transaction.
 * @param outputs, integer. Number of outputs in the transaction.
 * @return int, Number of bytes.
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
int
Transaction::calculateTxSize(int inputs, int outputs)
{
    // Conservative case, inputs are 181 bytes. Uncompressed public keys vary in size.
    // Outputs are 34 bytes.
    return inputs*181+outputs*34+10;
};

/**
 * @brief Calculates transaction fee for a given transaction size.
 * 
 * @param estimated_tx_size int size of the transaction in bytes.
 * @return unsigned long long 
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
unsigned long long
Transaction::calculate_tx_fee(int estimated_tx_size)
{
    // Refresh fee recommendations.
    network->refreshFeeRecommendations();

    // Satoshis/Bytes * Bytes
    unsigned long long fees = (unsigned long long)(estimated_tx_size * network->getHourFee());

    return fees;
};

/**
 * @brief Create a Meta Data Tx object
 * 
 * @return true 
 * @return false 
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
bool
createMetaDataTx()
{
    // OP Return tx
    std::string messageString = "helloworld";
    bc::data_chunk data(80);
    auto source = bc::make_safe_deserializer(data.begin(),data.end());
    auto sink = bc::make_unsafe_serializer(data.begin());
    sink.write_string(messageString);
    const auto nullData = source.read_bytes(80);
    std::cout << "Message: " << std::endl;
	std::cout << bc::encode_base16(nullData) << std::endl;
    bc::chain::output output2 = bc::chain::output();
    output2.set_script(bc::chain::script(bc::chain::script().to_null_data_pattern(nullData)));
    output2.set_value(0);
    return true;
};

/**
 * @brief Create a Signature object
 * 
 * @param a_lockingScript 
 * @param a_privKey 
 * @param a_transaction 
 * @return bc::endorsement 
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
bc::endorsement
createSignature(bc::chain::script a_lockingScript,bc::ec_secret a_privKey,bc::chain::transaction a_transaction)
{
    bc::endorsement signature;

    if(a_lockingScript.create_endorsement(signature, a_privKey, a_lockingScript, a_transaction, 0u, bc::machine::all))
	{
		std::cout << "Signature: " << std::endl;
		std::cout << bc::encode_base16(signature) << "\n" << std::endl; 
        return signature;
	}
    else
    {
        Error::RecordError(std::string("Cannot create signature endorsement."));
        Error::DisplayErrors();
    }
};

/**
 * @brief Constructs P2PKH script transaction.
 * 
 * @param a_publicKey, public key address of bitcoin payment address to use.
 * @param a_privKey
 * @param a_destinationAddress 
 * @param a_satoshis 
 * @return true 
 * @return false 
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
bc::chain::transaction
Transaction::P2PKH(bc::wallet::payment_address a_destinationAddress, unsigned long long a_satoshis)
{   
    unsigned long long input_value = 0;
    unsigned long long change_value = 0;

    // Start building Transaction.
    // Instantiate the transaction object.
    bc::chain::transaction tx = bc::chain::transaction();

    // Set transaction version.
    // uint32_t version = 1u;
    // tx.set_version(version);

    // Find unspent output.
    m_utxo utxo_to_spend = unspent_output -> find_utxo(a_satoshis);

    // Create inputs.
    // For each input, point to unspent transaction output.
    for( const auto &utxo : utxo_to_spend)
    {
        // Create input.
        bc::chain::input input = bc::chain::input();
        bc::hash_digest utxo_hash = std::get<1>(utxo);
        bc::chain::output_point previous_output(utxo_hash,0);

        input.set_previous_output(previous_output);
        input.set_sequence(0xffffffff);
        tx.inputs().push_back(input);

        input_value += std::get<0>(utxo);
    };

    change_value = input_value - a_satoshis;

    // Find recommended fee.
    int estimated_tx_bytes = calculateTxSize(tx.inputs().size(), 2); 
    unsigned long long fees = calculate_tx_fee(estimated_tx_bytes);

    // Subtract fees from the change.
    if( change_value - fees > 0)
    {
        change_value -= fees;
        std::cout << "fees to send: " <<fees << "change value" << change_value <<std::endl;
        bc::wallet::payment_address change_address= std::get<2>(utxo_to_spend[0]);
        tx.outputs().push_back(createOutputP2PKH(change_address,change_value));
    }
    // If fees are greater than change, make change 0.
    else if (change_value - fees <= 0)
    {
        change_value = 0;
    }

    // Create output.
    tx.outputs().push_back(createOutputP2PKH(a_destinationAddress,a_satoshis));

    // Return transaction.
    return tx;
};

/**
 * @brief Constructs P2PKH script transaction.
 * 
 * @param a_publicKey, public key address of bitcoin payment address to use.
 * @param a_privKey
 * @param a_destinationAddress 
 * @param a_satoshis 
 * @param a_fees
 * @return true 
 * @return false 
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
bc::chain::transaction
Transaction::P2PKH(bc::wallet::payment_address a_destinationAddress, unsigned long long a_satoshis, unsigned long long a_fees)
{   
    unsigned long long input_value = 0;
    unsigned long long change_value = 0;

    // Start building Transaction.
    // Instantiate the transaction object.
    bc::chain::transaction tx = bc::chain::transaction();

    // Set transaction version.
    // uint32_t version = 1u;
    // tx.set_version(version);

    // Find unspent output.
    m_utxo utxo_to_spend = unspent_output -> find_utxo(a_satoshis);

    // Create inputs.
    // For each input, point to unspent transaction output.
    for( const auto &utxo : utxo_to_spend)
    {
        // Create input.
        bc::chain::input input = bc::chain::input();
        bc::hash_digest utxo_hash = std::get<1>(utxo);
        bc::chain::output_point previous_output(utxo_hash,0);

        input.set_previous_output(previous_output);
        input.set_sequence(0xffffffff);
        tx.inputs().push_back(input);

        input_value += std::get<0>(utxo);
    };

    change_value = input_value - a_satoshis;

    // Find recommended fee.
    int estimated_tx_bytes = calculateTxSize(tx.inputs().size(), 2); 
    unsigned long long fees = estimated_tx_bytes * a_fees;

    // Subtract fees from the change.
    if( change_value - fees > 0)
    {
        change_value -= fees;
        std::cout << "fees to send: " <<fees << "change value" << change_value <<std::endl;
        bc::wallet::payment_address change_address= std::get<2>(utxo_to_spend[0]);
        tx.outputs().push_back(createOutputP2PKH(change_address,change_value));
    }
    // If fees are greater than change, make change 0.
    else if (change_value - fees <= 0)
    {
        change_value = 0;
    }

    // Create output.
    tx.outputs().push_back(createOutputP2PKH(a_destinationAddress,a_satoshis));

    // Return transaction.
    return tx;
};

/**
 * @brief Returns balanace of n payment address.
 * 
 * @param a_address, payment address.
 * @return unsigned long long 
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
unsigned long long
Transaction::getBalanceForAddress(bc::wallet::payment_address a_address)
{

    unsigned long long utxo = 0;
    bc::hash_digest utxo_hash;

    // Connect to libbitcoin servers.
    bc::client::obelisk_client &rpc = network->connect();

    // Lambda callback function for getting utxo for addy.
    static const auto on_done = [this, &utxo,&a_address,&utxo_hash](const bc::chain::history::list& rows)
    {
        // For each row in chain history, check for balance.
        for(const auto& row: rows)
        {
              
            // Unspent transaction output.
            if (row.spend.hash() == bc::null_hash)
            {    
                utxo += row.value;

                utxo_hash = row.output.hash();
                std::cout << bc::encode_hash(utxo_hash) << std::endl;
                unspent_output -> add_transaction(row.value, utxo_hash, a_address);
                
            }

            // Spent transaction output.
           
            {

                if(row.spend.hash() != bc::null_hash)
                {
                    m_transactions.push_back(std::make_tuple(row.value,row.spend.hash(),row.spend_height));
                }
                if(row.output.hash() != bc::null_hash)
                {
                    m_transactions.push_back(std::make_tuple(row.value,row.output.hash(),row.output_height));
                }
                
            }
        }
    };

    static const auto on_error = [](const bc::code ec) 
    {
        Error::RecordError(std::string("Error connecting to bitcoin network."));
    };

    // Get Blockchain history on this address.
    rpc.blockchain_fetch_history3(on_error, on_done, a_address);

    // Wait for history to be fetched.
    rpc.wait();
    
    network -> disconnect();


    m_utxoMap[a_address] = std::make_pair(utxo_hash, utxo);
    // Return utxo for a_address.
    return utxo;
};

/**
 * @brief 
 * 
 * @param a_address, payment address to check UTXO for. 
 * @param a_amount, minimum value of satoshis needed in UTXO.
 * @return bc::chain::points_value 
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
bc::chain::points_value
Transaction::getUTXOs(bc::wallet::payment_address a_address, unsigned long long a_amount)
{
    // Connect to libbitcoin servers.
    bc::client::obelisk_client &rpc = network->connect();
 
    bc::chain::points_value val1;
    static const auto on_done = [&val1](const bc::chain::points_value& vals) {
 
        std::cout << "Success: " << vals.value() << std::endl;
        val1 = vals;
         
 
    };
 
    static const auto on_error = [](const bc::code& ec) {
 
        std::cout << "Error Code: " << ec.message() << std::endl;
 
    };
 
    rpc.blockchain_fetch_unspent_outputs(on_error, on_done, a_address, a_amount, bc::wallet::select_outputs::algorithm::greedy);
     
    rpc.wait();
    
    network -> disconnect();
     
    //return allPoints;
    return val1;
};

/**
 * @brief Broadcasts transaction to the network.
 * 
 * @param tx 
 * @return true 
 * @return false 
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
bool
Transaction::broadcastTransaction(bc::chain::transaction tx)
{
    // Connect to libbitcoin servers.
    bc::client::obelisk_client &rpc = network->connect();
 
    static const auto on_done = [](const bc::code& ec) {

		std::cout << "Success: " << ec.message() << std::endl;

	};

    static const auto on_error = [](const bc::code& ec) {

		std::cout << "Error Code: " << ec.message() << std::endl;

	};

    rpc.transaction_pool_broadcast(on_error, on_done, tx);
     
    rpc.wait();
    
    network -> disconnect();

    return true;
};

/**
 * @brief Checks if the given payment address has recieved any bitcoin in its history.
 * 
 * @param a_address, address to check.
 * @return true, payment address has recieved bitcoin.
 * @return false, payment address has never recieved bitcoin.
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
bool
Transaction::isAddressUsed(bc::wallet::payment_address a_address)
{
    // Satoshis recieved.
    unsigned long long recieved = 0;

    // Connect to libbitcoin servers.
    bc::client::obelisk_client &rpc = network->connect();

    // Lambda callback function for getting utxo for addy.
    static const auto on_done = [&recieved](const bc::chain::history::list& rows)
    {
        // For each row in chain history, check for balance.
        for(const auto& row: rows)
        {  
            recieved += row.value;
        }
    };

    static const auto on_error = [](const bc::code ec) 
    {
        Error::RecordError(std::string("Error connecting to bitcoin network."));
    };

    // Get Blockchain history on this address.
    rpc.blockchain_fetch_history3(on_error, on_done, a_address);

    // Wait for history to be fetched.
    rpc.wait();
    
    network -> disconnect();

    // If address recieved any bitcoin, than it is used.
    if(recieved > 0)
    {
        return true;
    }
    else
    {
        return false;
    }

};

/**
 * @brief Calculates the balance of the wallet. Atlas calls this function until false is returned.
 * 
 * @param a_address, payment address to check if address is used, and add any existing balance.
 * @return true, address is used.
 * @return false, address is not used.
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
bool
Transaction::calculateBalance(bc::wallet::payment_address a_address)
{
    std::cout << "Checking balance for " << a_address << std::endl;

    // Check if address is used.
    if(isAddressUsed(a_address))
    {
        // Get balance for the address. Add it to the sum.
        m_utxoSum += getBalanceForAddress(a_address);
        return true;
    }
    else
    {
        show_transaction_history();
        return false;
    }
};

/**
 * @brief Selector for current balance of utxo.
 * 
 * @return unsigned long long 
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
unsigned long long 
Transaction::getBalance() const
{
    return m_utxoSum;
};

/**
 * @brief Get the transaction history.
 * 
 * @return std::vector< m_tx > 
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
std::vector< Transaction::m_tx >
Transaction::get_transaction_history() const
{
    return m_transactions;
};

/**
 * @brief Shows each transaction in transaction history.
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
void
Transaction::show_transaction_history()
{
    std::sort(m_transactions.begin(),m_transactions.end(),compare_block_height);

    for(int i = 0; i < m_transactions.size(); i++)
    {
        std::cout << std::get<0>(m_transactions[i]) << bc::encode_hash(std::get<1>(m_transactions[i])) << std::get<2>(m_transactions[i]) << std::endl;
    }
};

/**
 * @brief Comparator function for comparing block height between two transactions. Used for sorting.
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 * 
 * @author Philip Glazman
 * @date 4/28/2018
 */
bool
Transaction::compare_block_height(const m_tx &a, const m_tx &b)
{
    return std::get<2>(a) > std::get<2>(b);
};