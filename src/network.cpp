#include "stdafx.h"

/**
 * @brief Connect to testnet libbitcoin servers.
 * 
 * @return true, connection successful.
 * @return false, connection failed.
 */
bool network::connect()
{
    bc::client::connection_type connection = {};
	connection.retries = 3;
	connection.timeout_seconds = 8;
    // Connect to testnet.
	connection.server = bc::config::endpoint("tcp://testnet.libbitcoin.net:19091");
    
    m_client = new  bc::client::obelisk_client(connection);
    
    // Check if connection is working.
	if(!m_client->connect(connection)) 
    {
        return false;
	}

    else
    {
        return true;
    }
};