#include "stdafx.h"

/**
 * @brief Construct a new utxo::utxo object
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
utxo::utxo()
{
    m_tx_output = new std::vector < std::tuple <m_satoshis, m_utxo_hash, m_address> >;
};

/**
 * @brief Destroy the utxo::utxo object
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
utxo::~utxo()
{
    delete m_tx_output;
};

/**
 * @brief Adds a transaction to the utxo map.
 * 
 * @param a_satoshis 
 * @param a_utxo_hash 
 * @param a_address 
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
void utxo::add_transaction(unsigned long long a_satoshis, bc::hash_digest a_utxo_hash, bc::wallet::payment_address a_address) const
{
    m_tx_output -> push_back( std::make_tuple(a_satoshis, a_utxo_hash, a_address));
}

/**
 * @brief Returns value of a transaction hash.
 * 
 * @param a_utxo_hash 
 * @return unsigned long long 
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
unsigned long long utxo::get_value(bc::hash_digest a_utxo_hash)
{   
    //@TODO - update
    return 1;
};


// bool compare_utxo(const utxo_tuple& lhs, const utxo_tuple& rhs)
// {
//     return std::get<0>(lhs) <  std::get<0>(rhs);
// };



void utxo::show_available_utxo()
{
    for(const auto&tx : *m_tx_output)
    {
        std::cout << "Payment Address: " << std::get<2>(tx) << " Value: " << std::get<0>(tx) << " UTXO Hash: " << bc::encode_hash(std::get<1>(tx)) << std::endl;
    };
};

// finds the minimum utxo to satisfy need
// returns stack of utxos which conntains tuple of payment address, utxo hash, and value
utxo::utxo_data utxo::find_utxo(unsigned long long a_satoshis)
{
    // Used to sum each utxo value
    unsigned long long value = 0;
    utxo_data utxo_to_return;

    // Sort vector in ascending order (min to max) according to utxo value.
    std::sort(m_tx_output->begin(), m_tx_output->end(),compare_utxo());

    show_available_utxo(); 

    for(const auto&tx : *m_tx_output)
    {
        if(value > a_satoshis)
        {
            break;
        }
        utxo_to_return.push_back(tx);
        value += std::get<0>(tx);
    };

    return utxo_to_return;
};
// get utxo based on what to spend - get lowest 