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

bool Transaction::P2PKH(bc::wallet::payment_address destinationAddress, unsigned long long satoshis)
{ 
    // Create output script.
    bc::chain::script outputScript = bc::chain::script().to_pay_key_hash_pattern(destinationAddress.hash());

    //decode_base10(satoshis, BTC, 8);
    
    bc::chain::output output1(satoshis, outputScript);
    std::cout << "\nAmount: " << bc::encode_base10(output1.value(), 8) << "BTC : Output Script: " << output1.script().to_string(0) << "\n" << std::endl;
    return true;
};

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
            if (row.spend.hash() == bc::null_hash)
                utxo += row.value;
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
