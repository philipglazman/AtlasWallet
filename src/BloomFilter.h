/*
Contains bloom filter implementation following BIP-37.
Bloom filter provides plausible-deniability privacy.
*/
#ifndef _BLOOMFILTER_H      
#define _BLOOMFILTER_H

#include "stdafx.h"

class BloomFilter
{
public:
    BloomFilter();
    ~BloomFilter();

    //filterLoad();
    //filterAdd();
    //filterClear();

private:
    // Maximum number of bytes allowed in a filter.
    const uint8_t m_maxBytes[36000];
    // Maximum number of hash functions allowed in a filter.
    const uint32_t m_maxHashFunctions = 50;
    // Setting nFlags to zero to notify peers that we do not want them to modify our filter.
    const uint8_t m_nFlags = 0;
    // A random value to add to the seed value in the hash function used by the bloom filter.
    // TODO - Change zero to some random seed value.
    const uint32_t m_nTweak = 0;

    // More nFlags.
    const unsigned int BLOOM_UPDATE_NONE = 0;
    const unsigned int BLOOM_UPDATE_ALL = 1;
    const unsigned int BLOOM_UPDATE_P2PUBKEY_ONLY = 2

};

#endif