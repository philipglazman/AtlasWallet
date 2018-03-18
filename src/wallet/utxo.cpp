#include "stdafx.h"

utxo::utxo()
{
    m_tx_output = new std::vector < std::tuple <m_satoshis, m_utxo_hash, m_address> >;
};

void utxo::add_transaction(unsigned long long a_satoshis, bc::hash_digest a_utxo_hash, bc::wallet::payment_address a_address) const
{
    m_tx_output -> push_back( std::make_tuple(a_satoshis, a_utxo_hash, a_address));
}

unsigned long long utxo::get_value(bc::hash_digest a_utxo_hash)
{   
    return 1;
};


// bool compare_utxo(const utxo_tuple& lhs, const utxo_tuple& rhs)
// {
//     return std::get<0>(lhs) <  std::get<0>(rhs);
// };

struct compare_utxo
{
    typedef unsigned long long m_satoshis;
    typedef bc::hash_digest m_utxo_hash;
    typedef bc::wallet::payment_address m_address;
    typedef std::tuple <m_satoshis, m_utxo_hash, m_address> utxo_tuple;

    // Returns smallest utxo.
    bool operator()(const utxo_tuple &lhs, const utxo_tuple &rhs) const
    {
        return std::get<0>(lhs) < std::get<0>(rhs);
    }
};

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