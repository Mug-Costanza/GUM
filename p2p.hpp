#ifndef p2p_hpp
#define p2p_hpp

//std
#include <iostream>
#include <string>

//Linux networking
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

int createSocket(int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    
        if (sock < 0)
        {
            std::cerr << "Failed to create the socket." << std::endl;
            return -1;
        }
    
    struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_addr.s_addr = INADDR_ANY;
        server_address.sin_port = htons(port);

        if (bind(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
        {
            std::cerr << "Failed to bind the socket." << std::endl;
            return -1;
        }

        
        if (listen(sock, 5) < 0)
        {
            std::cerr << "Failed to listen for incoming connections." << std::endl;
            return -1;
        }
    
    return sock;
}

bool connectToPeer(int sock, std::string ip_address, int port)
{
    struct sockaddr_in peer_address;
    peer_address.sin_family = AF_INET;
    peer_address.sin_port = htons(port);
    
    if (inet_pton(AF_INET, ip_address.c_str(), &peer_address.sin_addr) <= 0)
    {
        std::cerr << "Invalid IP address" << std::endl;
        return false;
    }

    if (connect(sock, (struct sockaddr *) &peer_address, sizeof(peer_address)) < 0) {
        std::cerr << "Failed to connect to peer" << std::endl;
        return false;
    }

    return true;
}

#endif /* p2p_hpp */
