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

        bool P2PKH(bc::wallet::payment_address destinationAddress, unsigned long long satoshis);

        // Returns balance of wallet. (total utxo)
        unsigned int getutxoSum() const { return m_utxoSum; };

        // Returns balance of n bitcoin address.
        unsigned long long getBalance(bc::wallet::payment_address a_address);

    protected:
    private:
        
        // UTXO Balance
        unsigned int m_utxoSum;

        // Network object.
        Network * network;


        // get list of blocks associated with this transaction
        // call bloom filter.
        // get list of utxo.
};

#endif