#include "stdafx.h"
#include "transaction.h"

bool transaction::payToPublicKeyHash(bc::payment_address destinationAddress, uint64_t satoshis)
{
    script outputScript = script().to_pay_key_hash_pattern(destinationAddress.hash());
    decode_base10(satoshis, BTC, 8)
    output output1(satoshis, outputScript);
    std::cout << "\nAmount: " << encode_base10(output1.value(), 8) << "BTC : Output Script: " << output1.script().to_string(0) << "\n" << std::endl;
}

