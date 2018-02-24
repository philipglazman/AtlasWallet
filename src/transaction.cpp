#include "stdafx.h"

Transaction::Transaction()
{
    network = new Network();
    m_utxoSum = 0;
};

Transaction::~Transaction()
{
    delete network;
}

/**
 * @brief Vasic P2PKH transaction setup.
 * 
 * @param destinationAddress 
 * @param satoshis 
 * @return true 
 * @return false 
 */
bool Transaction::P2PKH(bc::wallet::payment_address destinationAddress, unsigned long long satoshis)
{ 
    // Create output script - OP_DUP OP_HASH160 <PKH> OP_EQUALVERIFY OP_CHECKSIG
    bc::chain::script outputScript = bc::chain::script().to_pay_key_hash_pattern(destinationAddress.hash());

    //decode_base10(satoshis, BTC, 8);
    
    bc::chain::output output1(satoshis, outputScript);
    std::cout << "\nAmount: " << bc::encode_base10(output1.value(), 8) << "BTC : Output Script: " << output1.script().to_string(0) << "\n" << std::endl;
    return true;
};

/**
 * @brief Returns balanace of n payment address.
 * 
 * @param a_address, payment address.
 * @return unsigned long long 
 */
unsigned long long Transaction::getBalance(bc::wallet::payment_address a_address)
{
    std::cout << a_address << std::endl;

    unsigned long long utxo = 0;

    // Connect to libbitcoin servers.
    bc::client::obelisk_client &rpc = network->connect();

    // Lambda callback function for getting utxo for addy.
    static const auto on_done = [&utxo](const bc::chain::history::list& rows)
    {
        // For each row in chain history, check for balance.
        for(const auto& row: rows)
        {
            //bc::hash_digest test = row.output.hash();
            if (row.spend.hash() == bc::null_hash)
            {    
                utxo += row.value;
                bc::hash_digest utxoHash = row.output.hash();
                uint32_t index = 0;
                bc::chain::output_point utxo(utxoHash, index);
                //std::string hashString 
                bc::encode_hash(utxoHash);
                std::cout << bc::encode_hash(utxoHash) << std::endl;
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