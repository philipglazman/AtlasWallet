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

        // Constructs P2PKH script.
        bool P2PKH(bc::data_chunk a_publicKey, const bc::ec_secret a_privKey, bc::wallet::payment_address a_destinationAddress, unsigned long long a_satoshis);

        // Broadcasts transaction to network.
        bool broadcastTransaction(bc::chain::transaction tx);

        // Returns balance of wallet. (total utxo)
        unsigned long long getBalance() const { return m_utxoSum; };

        // Returns balance of n bitcoin address.
        unsigned long long getBalanceForAddress(bc::wallet::payment_address a_address);

        // Calculate the total balance of the wallet. 
        // Atlas.cpp calls this function while true is returned. True means that the address has a balance.
        // Returning false means the last address does not have a balance so thats the last index used.
        bool calculateBalance(bc::wallet::payment_address a_address);

        // Checks if given payment address has enough utxo to pay the provided # of satoshis.
        bc::chain::points_value getUTXOs(bc::wallet::payment_address Addy, unsigned long long amount);

    protected:

    private:
        
        // Calculates the size in bytes of the transaction. Uses primitive formula. 
        // TODO: Need more dynamic way to test. (including regression tests)
        int calculateTxSize(int inputs, int outputs);

        // Creates output for P2PKH transaction.
        bc::chain::output createOutputP2PKH(bc::wallet::payment_address a_address, unsigned long long a_satoshis);

        // Show output for transaction output.
        void showTxOutput(bc::chain::output output);

        // Show raw transaction in hex.
        void showTxRaw(bc::chain::transaction a_transaction);

        // UTXO Balance
        unsigned long long m_utxoSum;

        // Hashmap of utxo 
        // Key -> payment_address
        // Value -> Pair ( utxo_hash , available balance )
        std::unordered_map <bc::wallet::payment_address,std::pair<bc::hash_digest, unsigned long long>> m_utxoMap;

        // Network object.
        Network * network;

        // Utxo object.
        utxo * unspent_output;


        // Checks if the given address is used.
        bool isAddressUsed(bc::wallet::payment_address a_address);

};

#endif
