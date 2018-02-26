#include "stdafx.h"


Network::Network()
{
    m_client = NULL;
}

Network::~Network()
{
    delete m_client;
}

/**
 * @brief Returns obelisk client pointer that allows rpc calls to be done.
 * 
 * @return bc::client::obelisk_client& 
 */
bc::client::obelisk_client& Network::connect()
{
    // Testnet connection details.
    bc::client::connection_type connection = {};
	connection.retries = 3;
	connection.timeout_seconds = 8;
	connection.server = bc::config::endpoint("tcp://testnet.libbitcoin.net:19091");
    
    // Initialize obelisk.
    m_client = new bc::client::obelisk_client(connection);

    // Check if connection is working.
	if(m_client->connect(connection)) 
    {
        std::cout << "Connected to Libbitcoin.net" << std::endl;
        return *m_client;
	}
    else
    {
        Error::RecordError(std::string("Error connecting to bitcoin network."));
        // should probably return something else.
        return *m_client;
    }
};

bool Network::disconnect()
{
    std::cout << "Disconnected from Libbitcoin.net" << std::endl;
    delete m_client;
    m_client = NULL;
};

void Network::refreshFeeRecommendations()
{
    boost::system::error_code ec;
    boost::asio::io_service svc;
    boost::asio::ip::tcp::socket sock(svc);
    
    // Send request.
    std::string request("GET https://bitcoinfees.earn.com/api/v1/fees/recommended HTTP/1.1\r\n\r\n");
    sock.send(boost::asio::buffer(request));
    
    // Read response.
    std::string response;
    do {
        char buf[1024];
        size_t bytes_transferred = sock.receive(boost::asio::buffer(buf), {}, ec);
        if (!ec) response.append(buf, buf + bytes_transferred);
    } while (!ec);

    // print and exit
    std::cout << "Response received: '" << response << "'\n";
};