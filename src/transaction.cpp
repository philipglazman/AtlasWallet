#include "stdafx.h"

Transaction::Transaction()
{
    network = new Network();
    unspent_output = new utxo();
    m_utxoSum = 0;
};

Transaction::~Transaction()
{
    delete network;
}

bc::chain::output Transaction::createOutputP2PKH(bc::wallet::payment_address a_address, unsigned long long a_satoshis)
{
    // Hash the Public Key of the Address. OP_DUP OP_HASH160 <PKH> OP_EQUALVERIFY OP_CHECKSIG
    bc::chain::script outputScript  = bc::chain::script().to_pay_key_hash_pattern(a_address.hash());

    bc::chain::output out(a_satoshis,outputScript);
    return out;
};

void Transaction::showTxOutput(bc::chain::output output)
{
    std::cout << "Sending Bitcoin: \nAmount: " << bc::encode_base10(output.value(), 8) << "BTC : Output Script: " << output.script().to_string(0) << std::endl;
};

void Transaction::showTxRaw(bc::chain::transaction a_transaction)
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
 */
int Transaction::calculateTxSize(int inputs, int outputs)
{
    // Conservative case, inputs are 181 bytes. Uncompressed public keys vary in size.
    // Outputs are 34 bytes.
    return inputs*181+outputs*34+10;
};

bool createMetaDataTx()
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

bc::endorsement createSignature(bc::chain::script a_lockingScript,bc::ec_secret a_privKey,bc::chain::transaction a_transaction)
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
}

/**
 * @brief Constructs P2PKH script transaction.
 * 
 * @param a_publicKey, public key address of bitcoin payment address to use.
 * @param a_privKey
 * @param a_destinationAddress 
 * @param a_satoshis 
 * @return true 
 * @return false 
 */
bool Transaction::P2PKH(bc::data_chunk a_publicKey, const bc::ec_secret a_privKey, bc::wallet::payment_address a_destinationAddress, unsigned long long a_satoshis)
{   
    // Fees
    // TODO: inputs will be variable.
    // TODO: fee/byte will be variable
    int estimatedBytes = calculateTxSize(1,2);
    int fees = estimatedBytes*30;

    //TODO: output to send should be output - fees.
    bc::chain::output output1 = createOutputP2PKH(a_destinationAddress,a_satoshis);

    // Display to user output amount and script.
    showTxOutput(output1);

    //Get UTXO to spend
    unspent_output -> find_utxo(1);
    bc::chain::output_point utxo(m_utxoMap.at(bc::wallet::payment_address("mmUbEcLMoJsaT6Uy3ZBkvF5i1AJ5xgmZpG")).first,0);
    int inputValue = m_utxoMap.at(bc::wallet::payment_address("mmUbEcLMoJsaT6Uy3ZBkvF5i1AJ5xgmZpG")).second;

    // Create Output to return change.
    bc::wallet::payment_address addy("mmUbEcLMoJsaT6Uy3ZBkvF5i1AJ5xgmZpG");
    bc::chain::output changeOutput = createOutputP2PKH(addy,inputValue-(a_satoshis+fees));
    
    // Locking Script using public key of utxo to spend.
    bc::chain::script lockingScript = bc::chain::script().to_pay_key_hash_pattern(bc::bitcoin_short_hash(a_publicKey));

    // Creating new input.
    bc::chain::input transactionInput = bc::chain::input();
    
    // Input will point to the output of the previous transaction.
    transactionInput.set_previous_output(utxo);
    transactionInput.set_sequence(0xffffffff);
    
    // Previous Locking Script.
    std::cout << "\nPrevious Locking Script: " << std::endl;
	std::cout << lockingScript.to_string(0xffffffff) << "\n" << std::endl;

    // Build the transaction.
    bc::chain::transaction tx = bc::chain::transaction();
    // Input.
    tx.inputs().push_back(transactionInput);
    // output.
    tx.outputs().push_back(output1);
    tx.outputs().push_back(changeOutput);

    // Show transaction.
    showTxRaw(tx);

    //broadcastTransaction(tx);
    return true;
};

/**
 * @brief Returns balanace of n payment address.
 * 
 * @param a_address, payment address.
 * @return unsigned long long 
 */
unsigned long long Transaction::getBalanceForAddress(bc::wallet::payment_address a_address)
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
            //bc::hash_digest test = row.output.hash();
            if (row.spend.hash() == bc::null_hash)
            {    
                utxo += row.value;

                utxo_hash = row.output.hash();
                std::cout << bc::encode_hash(utxo_hash) << std::endl;
                unspent_output -> add_transaction(row.value, utxo_hash, a_address);
                // uint32_t index = 0;
                // bc::chain::output_point utxo(utxo_hash, index);
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
 */
bc::chain::points_value Transaction::getUTXOs(bc::wallet::payment_address a_address, unsigned long long a_amount)
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
 */
bool Transaction::broadcastTransaction(bc::chain::transaction tx)
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
 */
bool Transaction::isAddressUsed(bc::wallet::payment_address a_address)
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
 */
bool Transaction::calculateBalance(bc::wallet::payment_address a_address)
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
        return false;
    }
};