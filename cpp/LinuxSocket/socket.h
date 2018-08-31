#ifndef SOCKET_H
#define SOCKET_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>

const int MAXCONNECTION = 5;
const int MAXRECEIVE = 500;

class Socket
{
    public:
        Socket();
        virtual ~Socket();

        //server function
        bool Create();
        bool Bind(const int port);
        bool Listen() const;
        bool Accept(Socket& clientSocket) const;

        //client function
        bool Connect(const std::string& host,const int port);
        
        //Data Transsmission
        static bool Send(Socket& socket,const std::string& message);
        static int Recieve(Socket& socket,std::string& message);

        void SetNonBlocking(const bool flag);//???
        bool IsValid() const;
        
        std::string GetAddress();
        int GetPort();

    private:
        int m_sockfd;
        struct sockaddr_in m_address;
};

#endif