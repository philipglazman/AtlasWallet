#include "stdafx.h"


/**
 * @brief Creates new wallet using user entropy (256 bits). 
 * 
 */
Wallet::Wallet()
{
    bc::wallet::word_list mnemonicSeed = generateMnemonicCode();

    m_seed = bc::to_chunk(bc::wallet::decode_mnemonic(mnemonicSeed));

    m_mnemonic = mnemonicSeed;

    // Master 256-bit Private Key.
    m_masterPrivateKey = bc::wallet::hd_private(m_seed,bc::wallet::hd_private::testnet);
    
    // Master 264-bit Public Key.
    m_masterPublicKey = m_masterPrivateKey.to_public();

    // Transactions object.
    transactions = new Transaction();
    m_address_index=1;
    set_address_index_to_last_unused_address();
}

/**
 * @brief Creates new wallet by import 12 word phrase.
 * 
 * @param a_mnemonicSeed, bc::wallet::word_list. List of 12 word seed phrase.
 */
Wallet::Wallet(const bc::wallet::word_list a_mnemonicSeed)
{
    // 512 bit seed is derived from mnemonic bits.
    m_seed = bc::to_chunk(bc::wallet::decode_mnemonic(a_mnemonicSeed));
    
    m_mnemonic = a_mnemonicSeed;

    // Master 256-bit Private Key.
    m_masterPrivateKey = bc::wallet::hd_private(m_seed,bc::wallet::hd_private::testnet);
    
    // Master 264-bit Public Key.
    m_masterPublicKey = m_masterPrivateKey.to_public();

    // Transactions object.
    transactions = new Transaction();
    m_address_index=1;
    set_address_index_to_last_unused_address();
}

/**
 * @brief Generates mnemonic bits using user machine's entropy. BIP-39 Standard.
 * 
 * @return bc::wallet::word_list. List of 12 words representing seed of wallet.
 */
bc::wallet::word_list
Wallet::generateMnemonicCode()
{
    // Store 128 bits for entropy.
    m_entropy = new std::vector<std::uint8_t>(16); 

    // Entropy is generated using local machine.
    bc::pseudo_random_fill(*m_entropy);

    // Entropy is included in bits to generate mnemonic words.
    bc::wallet::word_list mnemonicSeed =  bc::wallet::create_mnemonic(*m_entropy);

    delete m_entropy;

    return mnemonicSeed;

    // Create 512-bit seed using mnemonic code wirds and a_passphrase as Salt.
    // TODO - add ICU to library dependency to make it work with passphrase    
};

/**
 * @brief Selector for child private key at index n of keychain.
 * 
 * @param a_index, integer.
 * @return bc::wallet::hd_private 
 */
bc::wallet::hd_private
Wallet::childPrivateKey(int a_index)
{
    return m_masterPrivateKey.derive_private(a_index);
}

/**
 * @brief Selector for child public key at index n of keychain.
 * 
 * @param a_index, integer.
 * @return bc::wallet::hd_public 
 */
bc::wallet::hd_public
Wallet::childPublicKey(int a_index)
{
    return m_masterPublicKey.derive_public(a_index);
}

/**
 * @brief Return the Bitcoin Address (Base58 encoded address) at index n of keychain.
 * 
 * @param a_index, integer.
 * @return bc::wallet::payment_address 
 */
bc::wallet::payment_address Wallet::childAddress(int a_index)
{
    // Testnet payment address.
    return bc::wallet::payment_address(bc::wallet::ec_public(childPublicKey(a_index).point()), 0x6f);
}

/**
 * @brief Returns BIP-32 root key.
 * 
 * @return bc::wallet::hd_private 
 */
bc::wallet::hd_private Wallet::showPrivateKey()
{
    return m_masterPrivateKey.encoded();
}

/**
 * @brief Returns child private key at index n of keychain.
 * 
 * @param index 
 * @return bc::wallet::hd_private 
 */
bc::wallet::hd_private Wallet::showChildPrivateKey(int a_index)
{
    return childPrivateKey(a_index).encoded();
}

/**
 * @brief Return bitcoin address (Base58 encoded) at index n of keychain.
 * 
 * @param a_index 
 * @return bc::wallet::payment_address 
 */
bc::wallet::payment_address Wallet::getAddress(int a_index)
{
    return childAddress(a_index).encoded();
}

/**
 * @brief Outputs to console the list of mnemonic code phrases.
 * 
 */
void Wallet::showMnemonicCodes()
{
    // Validate the mnemonic phrase before sharing it with user.
    if(bc::wallet::validate_mnemonic(m_mnemonic))
    {
        std::string mnemonicString = bc::join(m_mnemonic);
        std::cout << mnemonicString << std::endl;
 
    }else{
        std::cout << "Mnemonic Invalid!" << std::endl;
    }
}

/**
 * @brief Shows relevant keys to the user in console.
 * 
 */
void Wallet::showKeys()
{
    showMnemonicCodes();
    std::cout << "BIP 32 Root Key: " << showPrivateKey() << std::endl;
    std::cout << "Address: " << getAddress(1) << std::endl;
    std::cout << "Address: " << getAddress(2) << std::endl;
}


void Wallet::set_address_index_to_last_unused_address()
{
    while(true)
    {
        if(transactions->calculateBalance(getAddress(m_address_index)))
        {
            m_address_index++;
        }
        else
        {
            break;
        }
    }
};

unsigned long long Wallet::getBalance() const
{
    return transactions->getBalance();
}

std::string Wallet::get_balance_as_string() const
{
    return bc::encode_base10(transactions->getBalance(),8);
};

void  Wallet::build_P2PKH(std::string a_address, unsigned long long a_satoshis)
{
    bc::wallet::payment_address address = bc::wallet::payment_address(a_address);
    bc::chain::transaction tx = transactions->P2PKH(a_address,a_satoshis);

    transactions->show_raw_tx(tx);
}

