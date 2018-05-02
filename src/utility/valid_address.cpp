#include "valid_address.hpp"
#include <string>
#include "/usr/local/include/openssl/sha.h"

bool valid_address::valid(std::string a_address)
{ 
    unsigned char dec[32], d1[SHA256_DIGEST_LENGTH], d2[SHA256_DIGEST_LENGTH];  
    
    return true;
}