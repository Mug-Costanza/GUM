//std
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//Project Files
#include "hashslingingSlasher.hpp"
#include "block.hpp"
#include "blockchain.hpp"
#include "p2p.hpp"

void Init();

int main()
{
    Init();
    
    return 0;
}

void Init()
{
    int socket = createSocket(8080);

    if(socket != 0)
    {
        std::cout << "Failed to create socket." << std::endl;
    }
    
    //connectToPeer(socket, , 8080);
}
