/**
 * @brief Provides networking feature to wallet.
 * 
 */

#ifndef _NETWORK_H
#define _NETWORK_H

#include "stdafx.h"

namespace network
{
    // Connect to Bitcoin network (libbitcion servers).
    bool connect();

    // Exception Handling lambda function for network calls.
    static const auto on_error = [](const bc::code ec) 
    {
		Error::RecordError(std::string("Error connecting to bitcoin network."));
	};

    // Broadcast raw transaction to Bitcoin.
    bool broadcastTranaction();

    // Obelisk Client object. This object will use rpc to talk to Bitcoin network.
    static bc::client::obelisk_client * m_client;


}

#endif