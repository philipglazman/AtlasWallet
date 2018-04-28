/**
 * @brief Keeps track of transactions (sent/recieved). 
 * 
 */

#ifndef _TRANSACTION_H
#define _TRANSACTION_H
#include "stdafx.h"
#include "utxo.hpp"
#include "../network/network.hpp"

class Transaction {
    public:
        Transaction();
        ~Transaction();

        // Tuple holding a spent/unspent transaction.
        // <0> - value transacted
        // <1> - hash of transaction
        // <2> - block height of transaction
        typedef std::tuple<unsigned long long,bc::hash_digest,int> m_tx;

        // Constructs P2PKH script.
        bc::chain::transaction P2PKH(bc::wallet::payment_address a_destinationAddress, unsigned long long a_satoshis);

        // Broadcasts transaction to network.
        bool broadcastTransaction(bc::chain::transaction tx);

        // Returns balance of wallet. (total utxo)
        unsigned long long getBalance() const;

        // Returns balance of n bitcoin address.
        unsigned long long getBalanceForAddress(bc::wallet::payment_address a_address);

        // Calculate the total balance of the wallet. 
        // Atlas.cpp calls this function while true is returned. True means that the address has a balance.
        // Returning false means the last address does not have a balance so thats the last index used.
        bool calculateBalance(bc::wallet::payment_address a_address);

        // Checks if given payment address has enough utxo to pay the provided # of satoshis.
        bc::chain::points_value getUTXOs(bc::wallet::payment_address Addy, unsigned long long amount);

        // Show raw transaction in hex.
        void show_raw_tx(bc::chain::transaction a_transaction);

        std::vector< m_tx > get_transaction_history() const;
        
    protected:

    private:

        // UTXO vector holding tuple of utxo.
        // <0> - value of transaction
        // <1> - hash of transaction
        // <2> - payment address recieving transaction
        typedef std::vector < std::tuple <unsigned long long, bc::hash_digest, bc::wallet::payment_address> > m_utxo;

        // Vector holds all transactions assocated with addresses.
        std::vector< m_tx > m_transactions;

        // Network object.
        Network * network;

        // Utxo object.
        utxo * unspent_output;
        
        static bool compare_block_height(const m_tx &a, const m_tx &b);

        void show_transaction_history();

        // Calculates the size in bytes of the transaction. Uses primitive formula. 
        // TODO: Need more dynamic way to test. (including regression tests)
        int calculateTxSize(int inputs, int outputs);

        unsigned long long calculate_tx_fee(int estimated_tx_size);

        // Creates output for P2PKH transaction.
        bc::chain::output createOutputP2PKH(bc::wallet::payment_address a_address, unsigned long long a_satoshis);

        // Show output for transaction output.
        void showTxOutput(bc::chain::output output);

        // UTXO Balance
        unsigned long long m_utxoSum;

        // Hashmap of utxo 
        // Key -> payment_address
        // Value -> Pair ( utxo_hash , available balance )
        std::unordered_map <bc::wallet::payment_address,std::pair<bc::hash_digest, unsigned long long>> m_utxoMap;

        // Checks if the given address is used.
        bool isAddressUsed(bc::wallet::payment_address a_address);

};

#endif
