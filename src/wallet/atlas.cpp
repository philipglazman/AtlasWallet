/*
* Main program for Atlas.
g++ -std=c++11 -o atlaswallet atlas.cpp wallet.cpp error.cpp transaction.cpp ../network/network.cpp utxo.cpp $(pkg-config --cflags libbitcoin --libs libbitcoin libbitcoin-client libcurl jsoncpp)
*/

#include "stdafx.h"

int
main(int argc, char * argv[])
{
    // Load wallet.
    std::vector< std::string > wordList = {"scatter", "found", "issue", "friend", "front", "glare", "blanket", "mother", "frequent", "acid", "shaft", "loud"};
    // Wallet object.
    Wallet wallet(wordList);

    // Reveal keys.
    // wallet.showKeys();

    // Transactions object;
    // Transaction transactions;

    // // Check balance.
    // // int addressIndex = 1;
    // // while(true)
    // // {
    // //     if(transactions.calculateBalance(wallet.getAddress(addressIndex)))
    // //     {
    // //         addressIndex++;
    // //     }
    // //     else
    // //     {
    // //         break;
    // //     }
    // // };

    // // wallet.set_address_index_to_last_unused_address();
    // std::cout<<wallet.getBalance()<<std::endl;
    // std::cout<<wallet.get_balance_as_string()<<std::endl;

    // std::cout<<wallet.getAddress(1).is_address()<<std::endl;

    // std::cout << addressIndex << std::endl;
    // std::cout << transactions.getBalance() << std::endl;

    // bc::wallet::payment_address addy = wallet.getAddress(1);
    // bc::wallet::payment_address destinationAddy = wallet.getAddress(3);
    // bc::data_chunk publicKey = bc::to_chunk(wallet.childPublicKey(1).point());
    // wallet.build_P2PKH("mmUbEcLMoJsaT6Uy3ZBkvF5i1AJ5xgmZpG",1000000);
    // transactions.P2PKH(destinationAddy, 1000000);

    // // Fees
    // Network net;
    // net.refreshFeeRecommendations();

};



