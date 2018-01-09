/*
Contains core features of wallet. 
Seed creation, Address creation, storage.
*/
#ifndef _WALLET_H      
#define _WALLET_H

#include "stdafx.h"

class Wallet
{
public:
    // creates wallet using user entropy (256 bits)
    Wallet();

    // creates wallet from 12 phrase mneumonic phrases
    Wallet(const bc::wallet::word_list m_mneomnicSeed);

    ~Wallet() {}

    void createMnemonicCodeWords();

    bc::wallet::hd_private childPrivateKey(int index);

    bc::wallet::hd_public childPublicKey(int index);

    bc::wallet::payment_address childAddress(int index);

    void showPrivateKey();

    void showChildPrivateKey(int index);

    void showAddress(int index);

    void showAllAddresses();

    void showMnemonicCodes();

    void showKeys();
    
private:
    bc::data_chunk m_entropy;
    bc::data_chunk m_seed;
    bc::wallet::word_list m_mnemonic;
    bc::wallet::hd_private m_privateKey;
    bc::wallet::hd_public m_publicKey;
};

#endif