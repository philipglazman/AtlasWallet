#include "stdafx.h"
#include "BloomFilter.h"
#include "Error.h"

/**/
/*
BloomFilter::bloomFilterHash()
NAME
BloomFilter::bloomFilterHash()
SYNOPSIS
void BloomFilter::bloomFilterHash()
DESCRIPTION
Creates hash for bloom filter.
RETURNS
Returns murmur3 hash.
AUTHOR
Philip Glazman
DATE
1/11/2018
*/
/**/
void BloomFilter::bloomFilterHash()
{
    //nHashNum * 0xFBA4C795 + nTweak
    int murmurSeed = 0xFBA4C795 + m_nTweak;
    //TODO import murmur3 from hash.h (Bitcoin/Bitcoin)
}