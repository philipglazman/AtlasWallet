/**
 * @brief Contains core features of the wallet. Seed creation, address creation, storage.
 * 
 */

#ifndef _WALLET_H      
#define _WALLET_H

#include "stdafx.h"

class Wallet
{
public:
    // Creates new wallet using user entropy (256 bits).
    Wallet();

    // Creates existing wallet by importing 12 word phrases.
    Wallet(const bc::wallet::word_list a_mneomnicSeed);

    // Destructor.
    ~Wallet() {}

    // Show bitcoin address at index.
    bc::wallet::payment_address showAddress(int index);

    // Show mnemonic codes.
    void showMnemonicCodes();

    // Debug function to get all keys.
    void showKeys();

protected:
    
private:
    // 128 bit entropy.
    std::vector<std::uint8_t> * m_entropy;

    // 512 bit seed.
    std::vector<std::uint8_t> m_seed;
    
    // List of 12 words used for wallet creation.
    bc::wallet::word_list m_mnemonic;

    // Master private key.
    bc::wallet::hd_private m_masterPrivateKey;

    // Master public key.
    bc::wallet::hd_public m_masterPublicKey;

    // Creates the Mnemonic Code Words.
    bc::wallet::word_list generateMnemonicCode();
 
    bc::wallet::hd_private childPrivateKey(int index);

    bc::wallet::hd_public childPublicKey(int index);

    bc::wallet::payment_address childAddress(int index);

    bc::wallet::hd_private showPrivateKey();

    bc::wallet::hd_private showChildPrivateKey(int index);  
};

#endif