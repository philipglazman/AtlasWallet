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

    protected:
    
    private:
        // Obelisk Client object. This object will use rpc to talk to Bitcoin network.
        bc::client::obelisk_client * m_client;
};

#endif