#include "merkle.hpp"

Merkle::Merkle(std::string rootHash, std::string prevHash, std::string nonce) : rootHash(getRootHash()), hash(getHash()), prevHash(getPrevHash()), nonce(getNonce())
{
    rootNode.transHash = rootHash;
}

void Merkle::insertElement(Node node)
{
    
}

void Merkle::removeElement(int id)
{
    
}

Node Merkle::getNode(int id)
{
    for(int i = 0; i < nodechain.size(); i++)
    {
        if(nodechain[i].id == id)
        {
            return nodechain[i];
        }
    }
    
    Node returnNode;
    
    return returnNode;
}

int Merkle::getNumOfNodes()
{
    return nodechain.size();
}

std::string Merkle::getRootHash()
{
    return rootHash;
}

std::string Merkle::getHash()
{
    return hash;
}

std::string Merkle::getPrevHash()
{
    return prevHash;
}

std::string Merkle::getNonce()
{
    return nonce;
}

std::string Merkle::mk_RootHash()
{
    return rootHash;
}

void Merkle::newNode(Node node)
{
    
}
