#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include "socket.h"
#include <string>

class ClientSocket:public Socket{
    public:
        ClientSocket(const std::string host,const int port);
        virtual ~ClientSocket();
        
        bool Send(const std::string& message);
        int Recieve(std::string& message);
};

#endif