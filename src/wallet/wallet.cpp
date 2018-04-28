#include "stdafx.h"


/**
 * @brief Creates new wallet using user entropy (256 bits). 
 * 
 * @author Philip Glazman
 * @date 4/28/18
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
 * 
 * @author Philip Glazman
 * @date 4/28/18
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
 * 
 * @author Philip Glazman
 * @date 4/28/18
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
 * 
 * @author Philip Glazman
 * @date 4/28/18
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
 * 
 * @author Philip Glazman
 * @date 4/28/18
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
 * 
 * @author Philip Glazman
 * @date 4/28/18
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
 * 
 * @author Philip Glazman
 * @date 4/28/18
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
 * 
 * @author Philip Glazman
 * @date 4/28/18
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
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
bc::wallet::payment_address
Wallet::getAddress(int a_index)
{
    return childAddress(a_index).encoded();
}

/**
 * @brief Outputs to console the list of mnemonic code phrases.
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
void
Wallet::showMnemonicCodes()
{
    // Validate the mnemonic phrase before sharing it with user.
    if(bc::wallet::validate_mnemonic(m_mnemonic))
    {
        std::string mnemonicString = bc::join(m_mnemonic);
        std::cout << mnemonicString << std::endl;
 
    }else{
        std::cout << "Mnemonic Invalid!" << std::endl;
    }
};

/**
 * @brief Shows relevant keys to the user in console. Used for debugging.
 * @author Philip Glazman
 * @date 4/28/18
 */
void
Wallet::showKeys()
{
    showMnemonicCodes();
    std::cout << "BIP 32 Root Key: " << showPrivateKey() << std::endl;
    std::cout << "Address: " << getAddress(1) << std::endl;
    std::cout << "Address: " << getAddress(2) << std::endl;
};

/**
 * @brief Sets the current address index to the last unused address. Prevents address reuse.
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
void
Wallet::set_address_index_to_last_unused_address()
{
    while(true)
    {
        // Check if the given address was used.
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

/**
 * @brief Returns balance as unsigned long long.
 * 
 * @return unsigned long long represents balance value of wallet. 
 * @author Philip Glazman
 * @date 4/28/18
 */
unsigned long long
Wallet::getBalance() const
{
    return transactions->getBalance();
}

/**
 * @brief Returns balance as string.
 * 
 * @return std::string string that represents balance value of wallet.
 * @author Philip Glazman
 * @date 4/28/18
 */
std::string
Wallet::get_balance_as_string() const
{
    return bc::encode_base10(transactions->getBalance(),8);
};

/**
 * @brief Creates a P2PKH transaction
 * 
 * @param a_address string Address to send value to.
 * @param a_satoshis unsigned long long Satoshi value to send.
 * @author Philip Glazman
 * @date 4/28/18
 */
void
Wallet::build_P2PKH(std::string a_address, unsigned long long a_satoshis)
{
    // Build tx.
    bc::wallet::payment_address address = bc::wallet::payment_address(a_address);
    bc::chain::transaction tx = transactions->P2PKH(a_address,a_satoshis);
    
    // Show tx.
    // @TODO - return tx. 
    transactions->show_raw_tx(tx);
};

/**
 * @brief 
 * 
 * @return std::vector< Transaction::m_tx > 
 * 
 * @author Philip Glazman
 * date 4/28/18
 */
std::vector< Transaction::m_tx >
Wallet::get_transaction_history()
{
    return transactions->get_transaction_history();
}