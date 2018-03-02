#include "stdafx.h"


Network::Network()
{
    m_client = NULL;
    m_fees = new feeEstimation;
}

Network::~Network()
{
    delete m_client;
    delete m_fees;
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

// from stackoverflow
std::size_t callback(const char* in, std::size_t size, std::size_t num, std::string* out)
{
    const std::size_t totalBytes(size * num);
    out->append(in, totalBytes);
    return totalBytes;
};


void Network::refreshFeeRecommendations()
{
    // Instantiate curl objects.
    CURL *curl;
    CURLcode res;
    std::string buffer;
    
    // Init curl.
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl)
    {
        // Request fee recommendations from bitcoinfees.earn.com (trusted recommendation).
        // TODO: internal free recommendation tool.
        curl_easy_setopt(curl, CURLOPT_URL, "https://bitcoinfees.earn.com/api/v1/fees/recommended");
        
        // Timeout after 10 seconds.
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);
        
        std::unique_ptr<std::string> httpData(new std::string());
        
        // Response.
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());
        res = curl_easy_perform(curl);

        // Error checking.
        if(res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else
        {
            Json::Value jsonData;
            Json::Reader jsonReader;

            // Parse JSON.
            if (jsonReader.parse(*httpData, jsonData))
            {
                std::cout << "Successfully parsed JSON data" << std::endl;
                std::cout << "\nJSON data received:" << std::endl;
                std::cout << jsonData.toStyledString() << std::endl;

                // Load fees into feeEstimation struct.
                m_fees -> fastestFee = jsonData["fastestFee"].asUInt64();
                m_fees -> halfHourFee = jsonData["halfHourFee"].asUInt64();
                m_fees -> hourFee = jsonData["hourFee"].asUInt64();
            };
        };

        // Clean-up. 
        curl_easy_cleanup(curl);
    };

    // Clean-up
    curl_global_cleanup();

};