/**
 * @brief Keeps track of transactions (sent/recieved). 
 * 
 */

#ifndef _TRANSACTIONS_H
#define _TRANSACTIONS_H

#include "stdafx.h"
#include "wallet.h"

class Transactions : public Wallet {
    public:
        Transactions();
        ~Transactions();
    protected:
    private:
        // get list of blocks associated with this transaction
        // call bloom filter.
        // get list of utxo.
};

#endif