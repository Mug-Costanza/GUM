#include "blockchain.hpp"
#include "hashslingingSlasher.hpp"

Blockchain::Blockchain()
{
    if(blockchain.size() == 0)
    {
        std::vector <std::string> vec;
        vec.push_back("Genesis Block");
        
        std::string nonceString = "00000000000000";
    }
}

int Blockchain::addBlock(int index, std::string prevHash, std::string hash, std::string nonce, std::vector <std::string> &data)
{
    index = blockchain.size();
    prevHash = blockchain[blockchain.size() - 1].getHash();
    
    std::string dataString;
    
    for(int i = 0; i < data.size(); i++)
    {
        dataString += data[i] + ", ";
    }
    
    std::string input = std::to_string(index) + prevHash + dataString + nonce;
    
    std::cout << "New Block : " << index << std::endl;
    
    return index;
}

Block Blockchain::getBlock(int index)
{
    for(int i = 0; i < blockchain.size(); i++)
    {
        if(blockchain[i].getIndex() == index)
        {
            return blockchain[i];
        }
    }
    
    std::cout << "Block does not exist" << std::endl;
    
    throw;
}

std::string Blockchain::getBlockHash(Block block)
{
    return block.getHash();
}

int Blockchain::getNumOfBlocks()
{
    return blockchain.size();
}
