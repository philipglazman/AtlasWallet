#include "stdafx.h"
#include "transaction.h"

// bool transaction::payToPublicKeyHash(bc::payment_address destinationAddress, uint64_t satoshis)
// { 
//     script outputScript = script().to_pay_key_hash_pattern(destinationAddress.hash());
//     decode_base10(satoshis, BTC, 8)''
//     output output1(satoshis, outputScript);
//     std::cout << "\nAmount: " << encode_base10(output1.value(), 8) << "BTC : Output Script: " << output1.script().to_string(0) << "\n" << std::endl;
// }

unsigned int transaction::getBalance(bc::wallet::payment_address a_address)
{
    uint64_t utxo = 0;

    // Connect to libbitcoin servers.
    network::connect();

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

    // Get Blockchain history on this address.
    network::m_client->blockchain_fetch_history3(network::on_error, on_done, a_address);

    // Wait for history to be fetched.
	network::m_client->wait();

    return utxo;
};
