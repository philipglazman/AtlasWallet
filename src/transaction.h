/**
 * @brief Keeps track of transactions (sent/recieved). 
 * 
 */

#ifndef _TRANSACTION_H
#define _TRANSACTION_H
#include "stdafx.h"

class transaction {
    public:
        transaction();
        ~transaction();

        // bool payToPublicKeyHash(bc::payment_address destinationAddress);

        // Returns balance of wallet. (total utxo)
        unsigned int getutxoSum() const { return m_utxoSum; };

        // Returns balance of x bitcoin address.
        unsigned int getBalance(bc::wallet::payment_address a_address);

    protected:
    private:
        
        // UTXO Balance
        unsigned int m_utxoSum;


        // get list of blocks associated with this transaction
        // call bloom filter.
        // get list of utxo.
};

#endif