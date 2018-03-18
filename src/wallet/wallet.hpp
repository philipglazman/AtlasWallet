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
    bc::wallet::payment_address getAddress(int a_index);

    // Show mnemonic codes.
    void showMnemonicCodes();

    // Returns public key at index n of keychain.
    bc::wallet::hd_public childPublicKey(int index);

    // Returns private key at index n of keychain.
    bc::wallet::hd_private childPrivateKey(int a_index);

    // Debug Helper - reveals all keys to output.
    void showKeys();

protected:
    
private:
    // 128 bit entropy.
    std::vector<std::uint8_t> * m_entropy;

    // 512 bit seed.
    std::vector<std::uint8_t> m_seed;
    
    // List of 12 words used for wallet creation.
    bc::wallet::word_list m_mnemonic;

    // 256 bits - Master private key - m
    bc::wallet::hd_private m_masterPrivateKey;

    // 264 bits - Master public key - M
    bc::wallet::hd_public m_masterPublicKey;

    // Creates the Mnemonic Code Words.
    bc::wallet::word_list generateMnemonicCode();
 

    // Returns address at index n of keychain.
    bc::wallet::payment_address childAddress(int index);

    // Debug Helper - Reveals Private Key to output.
    bc::wallet::hd_private showPrivateKey();

    // Debbug Helper - Reveals private key at index n in keychain to output.
    bc::wallet::hd_private showChildPrivateKey(int index);  
};

#endif