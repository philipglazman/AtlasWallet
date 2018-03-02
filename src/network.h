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
        int getFastestFee();
        int getHalfHourFee();
        int getHourFee();


    protected:

    private:

        struct feeEstimation
        {
            int fastestFee;
            int halfHourFee;
            int hourFee;
        };


        // Obelisk Client object. This object will use rpc to talk to Bitcoin network.
        bc::client::obelisk_client * m_client;
        feeEstimation * m_fees;
};

#endif