// stdafx.h : include file for standard system include files

/*
TO
compile as g++ -c stdafx.h -o stdafx.h.gch
g++ -c stdafx.h -o stdafx.h.gch -std=c++11 -lboostsystem -lbitcoin
*/

#pragma once

// TODO: add additional headers to the program
// Libbitcoin
#include <bitcoin/bitcoin.hpp>
#include <bitcoin/client.hpp>

// STL
#include <string.h>
#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <iomanip>
#include <random>
#include <unordered_map>
#include <sstream>
#include <stack>

// Utilities 
#include <curl/curl.h>
#include <json/json.h>

// Boost Libraries
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/asio.hpp>

// Atlas Headers
#include "error.hpp"
#include "../network/network.hpp"
#include "../script/script.hpp"
#include "../script/operation.hpp"
#include "Wallet.hpp"
#include "utxo.hpp"
#include "transaction.hpp"

// Crypto Libraries
#include <openssl/ripemd.h>
#include <openssl/sha.h>