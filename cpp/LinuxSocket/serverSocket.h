#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include "socket.h"
#include <list>
#include <mutex>
#include <thread>
#include <iostream>

class ServerSocket:public Socket{
    public:
        ServerSocket();
        ServerSocket(const int port);
        virtual ~ServerSocket();

        void Accept(Socket& socket);

    private:
        static std::list<Socket*> clientSockets;
        static std::mutex mtx;
        static bool serviceFlag;

        void StartService();
        bool AcceptNewClient();
        void AddClient(Socket* scoket);
        static void DeleteClient(Socket* socket);
        static void ProcessMessage(Socket* socket);
        static void SendMsgToAllUsers(const std::string& message);
};

#endif