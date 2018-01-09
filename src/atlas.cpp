/*
* Main program for Atlas.
g++ -std=c++11 -o wallet atlas.cpp wallet.cpp error.cpp $(pkg-config --cflags libbitcoin --libs libbitcoin libbitcoin-client)
*/

#include "stdafx.h"
#include "Wallet.h"
#include "Error.h"
#include <random>

/**/
/*
int main(int argc, char * argv[])

NAME

        main(int argc, char * argv[]) - Main entry point for program

SYNOPSIS

        n/a

DESCRIPTION

        n/a

RETURNS

        n/a

AUTHOR

        Philip Glazman

DATE

        12/31/2017

*/
/**/
int
main(int argc, char * argv[])
{
    // load config file, create new one if not available
    // If new config file create, suggest to user that they either check config.
    // if first time loading wallet, go through steps to creating HD keys
    // asynchronously check for utxo matching addresses

    // TODO add better entropy (mouse cursor mvmt?)
    std::random_device engine;
    unsigned x = engine();
    std::cout << x << std::endl;
    bc::data_chunk entropyChunk = bc::data_chunk(16);
    bc::pseudo_random_fill(entropyChunk);
    Wallet wallet(entropyChunk);
    wallet.showKeys();
}



