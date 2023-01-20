#ifndef block_hpp
#define block_hpp

//std
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

//Project files
#include "merkle.hpp"

struct Block
{
public:
    Block(int index, std::string prevHash, std::string hash, std::string nonce, std::vector <std::string> data);
    
    int getIndex();
    std::string getPrevHash();
    std::string getHash();
    std::string getNonce();
    std::vector <std::string> getData();
    
private:
    int index;
    std::string prevHash, hash, nonce;
    std::vector <std::string> data;
    //Merkle merkleRoot;
};

#endif /* block_hpp */
