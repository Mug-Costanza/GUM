#ifndef blockchain_hpp
#define blockchain_hpp

//Project Files
#include "block.hpp"

struct Blockchain
{
public:
    Blockchain();
    
    int addBlock(int index, std::string prevHash, std::string hash, std::string nonce, std::vector <std::string> &data);
    Block getBlock(int index);
    std::string getBlockHash(Block block);
    int getNumOfBlocks();
    
private:
    std::vector <Block> blockchain;
};

#endif /* blockchain_hpp */
