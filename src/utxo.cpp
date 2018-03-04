#include "stdafx.h"

utxo::utxo()
{
    m_tx_output = new std::vector < std::tuple <m_satoshis, m_utxo_hash, m_satoshis> >;
};

void utxo::add_transaction(unsigned long long a_satoshis, bc::hash_digest a_utxo_hash, bc::wallet::payment_address a_address) const
{
    m_tx_output -> push_back( std::make_tuple(a_satoshis, a_utxo_hash, a_address));
}

unsigned long long utxo::get_value(bc::hash_digest a_utxo_hash)
{   
    return 1;
};