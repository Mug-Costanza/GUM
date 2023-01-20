#ifndef hashslingingSlasher_hpp
#define hashslingingSlasher_hpp

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <openssl/sha.h>

std::string hash(std::string block)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, block.c_str(), block.size());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    
    return ss.str();
}


#endif /* hashslingingSlasher_hpp */
