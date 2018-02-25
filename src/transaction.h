/**
 * @brief Keeps track of transactions (sent/recieved). 
 * 
 */

#ifndef _TRANSACTION_H
#define _TRANSACTION_H
#include "stdafx.h"

class Transaction {
    public:
        Transaction();
        ~Transaction();

        bool P2PKH(bc::data_chunk a_publicKey, const bc::ec_secret a_privKey, bc::wallet::payment_address a_destinationAddress, unsigned long long a_satoshis);

        bool broadcastTransaction(bc::chain::transaction tx);

        // Returns balance of wallet. (total utxo)
        unsigned int getutxoSum() const { return m_utxoSum; };

        // Returns balance of n bitcoin address.
        unsigned long long getBalance(bc::wallet::payment_address a_address);

        bc::chain::points_value getUTXOs(bc::wallet::payment_address Addy, unsigned long long amount);

    protected:

    private:
        
        // UTXO Balance
        unsigned int m_utxoSum;

        // Hashmap of utxo 
        // Key -> payment_address
        // Value -> Pair ( utxo_hash , available balance )
        std::unordered_map <bc::wallet::payment_address,std::pair<bc::hash_digest, unsigned long long>> m_utxoMap;

        // Network object.
        Network * network;


        // get list of blocks associated with this transaction
        // call bloom filter.
        // get list of utxo.
};

#endif