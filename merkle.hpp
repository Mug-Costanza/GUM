#ifndef merkle_hpp
#define merkle_hpp

//std
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

////////////////////////
////////ROOT NODE///////
////////////////////////

struct Node
{
    int id;
    
    std::string transHash;
    
    struct Node *left = nullptr;
    struct Node *right = nullptr;
};

struct Merkle
{
public:
    Merkle(std::string hash, std::string prevHash, std::string nonce);
    
    std::string getHash();
    std::string getRootHash();
    std::string getPrevHash();
    std::string getNonce();
    
    int getNumOfNodes();
    
    Node rootNode;
    
    void newNode(Node node);
    std::string mk_RootHash();
    
    void insertElement(Node node);
    void removeElement(int id);
    Node getNode(int id);
    
private:
    std::string rootHash;
    std::string hash;
    std::string prevHash;
    std::string nonce;
    
    std::vector <Node> nodechain;
};

#endif /* merkle_hpp */
