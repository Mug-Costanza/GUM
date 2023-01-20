#include "block.hpp"

Block::Block(int index, std::string prevHash, std::string hash, std::string nonce, std::vector <std::string> data) : index(getIndex()), prevHash(getPrevHash()), hash(getHash()), data(getData()), nonce(nonce)
{
    std::cout << "Initializing Block; Index : " << std::to_string(index) << ", Hash : " << hash << "." << std::endl;
}

int Block::getIndex()
{
    return index;
}

std::string Block::getPrevHash()
{
    return prevHash;
}

std::string Block::getHash()
{
    return hash;
}

std::string Block::getNonce()
{
    return nonce;
}

std::vector <std::string> Block::getData()
{
    return data;
}
