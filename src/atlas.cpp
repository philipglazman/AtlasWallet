/*
* Main program for Atlas.
g++ -std=c++11 -o wallet atlas.cpp wallet.cpp error.cpp $(pkg-config --cflags libbitcoin --libs libbitcoin libbitcoin-client)
*/

#include "stdafx.h"

int
main(int argc, char * argv[])
{
    // load config file, create new one if not available
    // If new config file create, suggest to user that they either check config.
    // if first time loading wallet, go through steps to creating HD keys
    // asynchronously check for utxo matching addresses

    // TODO add better entropy (mouse cursor mvmt?)
    // std::random_device engine;
    
    std::vector< std::string > wordList = {"scatter", "found", "issue", "friend", "front", "glare", "blanket", "mother", "frequent", "acid", "shaft", "loud"};
    Wallet wallet(wordList);
    wallet.showKeys();
}



