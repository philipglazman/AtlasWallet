#ifndef _UTXO_H
#define _UTXO_H
#include "stdafx.h"

class utxo {
    public:
        utxo();
        ~utxo();

        // Fields.
        typedef unsigned long long m_satoshis;
        typedef bc::hash_digest m_utxo_hash;
        typedef bc::wallet::payment_address m_address;

        // Iterator
        typedef std::vector< std::tuple <m_satoshis, m_utxo_hash, m_address> >::const_iterator m_iterator;

        // UTXO object.
        typedef std::tuple <m_satoshis, m_utxo_hash, m_address> utxo_tuple;
        typedef std::vector < utxo_tuple > utxo_data;

        unsigned long long get_value(bc::hash_digest utxo_hash);
        
        // Adds an unspent transaction output.
        void add_transaction(unsigned long long a_satoshis, bc::hash_digest a_utxo_hash, bc::wallet::payment_address a_address) const;

        // Built list of utxo to be used in tx.
        utxo_data find_utxo(unsigned long long m_satoshis);

    protected:

    private:

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
        
        utxo_data * m_tx_output;

        void show_available_utxo();

        bool min_utxo();


};

#endif