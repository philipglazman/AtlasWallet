/**
 * @brief Provides networking feature to wallet.
 * 
 */

#ifndef _NETWORK_H
#define _NETWORK_H

#include "stdafx.h"

class Network
{
    public:
        Network();
        ~Network();

        // Broadcast raw transaction to Bitcoin.
        bool broadcastTranaction();

        // Connect to Bitcoin network (libbitcion servers).
        // Returns address of obelisk_client.
        bc::client::obelisk_client& connect();

        // Disconnect from network.
        bool disconnect();

        // Get fee recommendations from bitcoinfees.earn.co
        void refreshFeeRecommendations();
        unsigned long long getFastestFee() const { return m_fees -> fastestFee; };
        unsigned long long getHalfHourFee() const { return m_fees -> halfHourFee; };
        unsigned long long getHourFee() const { return m_fees -> hourFee; };


    protected:

    private:

        struct feeEstimation
        {
            unsigned long long fastestFee;
            unsigned long long halfHourFee;
            unsigned long long hourFee;
        };


        // Obelisk Client object. This object will use rpc to talk to Bitcoin network.
        bc::client::obelisk_client * m_client;
        feeEstimation * m_fees;
};

#endif