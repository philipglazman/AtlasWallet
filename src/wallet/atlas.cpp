/*
* Main program for Atlas.
g++ -std=c++11 -o atlaswallet atlas.cpp wallet.cpp error.cpp transaction.cpp ../network/network.cpp utxo.cpp $(pkg-config --cflags libbitcoin --libs libbitcoin libbitcoin-client libcurl jsoncpp)
*/

#include "stdafx.h"

int
main(int argc, char * argv[])
{
    // TODO add better entropy (mouse cursor mvmt?)
    // std::random_device engine;
    
    // Load wallet.
    std::vector< std::string > wordList = {"scatter", "found", "issue", "friend", "front", "glare", "blanket", "mother", "frequent", "acid", "shaft", "loud"};
    // Wallet object.
    Wallet wallet(wordList);

    // Reveal keys.
    wallet.showKeys();

    // Transactions object;
    Transaction transactions;

    // Check balance.
    int addressIndex = 1;
    while(true)
    {
        if(transactions.calculateBalance(wallet.getAddress(addressIndex)))
        {
            addressIndex++;
        }
        else
        {
            break;
        }
    };

    std::cout << addressIndex << std::endl;
    std::cout << transactions.getBalance() << std::endl;

    bc::wallet::payment_address addy = wallet.getAddress(1);
    bc::wallet::payment_address destinationAddy = wallet.getAddress(3);
    bc::data_chunk publicKey = bc::to_chunk(wallet.childPublicKey(1).point());
    transactions.P2PKH(publicKey,wallet.childPrivateKey(1).secret(),destinationAddy, 1000000);

    // // Fees
    // Network net;
    // net.refreshFeeRecommendations();

};



