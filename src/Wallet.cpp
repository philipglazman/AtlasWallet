#include "stdafx.h"
#include "Wallet.h"

Wallet::Wallet(const bc::data_chunk a_entropy)
{
    m_entropy = a_entropy;
    m_mnemonic = bc::wallet::create_mnemonic(m_entropy);
    m_seed = bc::to_chunk(bc::wallet::decode_mnemonic(m_mnemonic));
    m_privateKey = bc::wallet::hd_private(m_seed);
    m_publicKey = m_privateKey.to_public();
}

bc::wallet::hd_private Wallet::childPrivateKey(int index)
{
    return m_privateKey.derive_private(index);
}

bc::wallet::hd_public Wallet::childPublicKey(int index)
{
    return m_publicKey.derive_public(index);
}

bc::wallet::payment_address Wallet::childAddress(int index)
{
    return bc::wallet::ec_public(childPublicKey(index).point()).to_payment_address();
}

void Wallet::showPrivateKey()
{
    std::cout << m_privateKey.encoded() << std::endl;
}

void Wallet::showChildPrivateKey(int index)
{
    std::cout << childPrivateKey(index).encoded() << std::endl;
}

void Wallet::showAddress(int index)
{
    std::cout << childAddress(index).encoded() << std::endl;
}

void Wallet::showAllAddresses()
{
    //TODO cycle thru all addresses
    std::cout << "to do" << std::endl;
}

void Wallet::showMnemonicCodes()
{
    if(bc::wallet::validate_mnemonic(m_mnemonic))
    {
        std::string mnemonicString = bc::join(m_mnemonic);
        std::cout << "\n" << mnemonicString << std::endl;
 
    }else{
        std::cout << "mnemonic invalid!" << std::endl;
    }
}

void Wallet::showKeys()
{
    showMnemonicCodes();
    showPrivateKey();
    showChildPrivateKey(1);
    showAddress(1);
}