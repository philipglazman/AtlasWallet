/**
 * @brief Keeps track of transactions (sent/recieved). 
 * 
 */

#ifndef _TRANSACTIONS_H
#define _TRANSACTIONS_H
#include "stdafx.h"

class Transactions {
    public:
        Transactions();
        ~Transactions();

        bool payToPublicKeyHash(bc::payment_address destinationAddress);

    protected:
    private:
        // get list of blocks associated with this transaction
        // call bloom filter.
        // get list of utxo.
};

#endif