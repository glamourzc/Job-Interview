#include "socket.h"

#include <stdlib.h>
#include <memory.h>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>//?

Socket::Socket():m_sockfd(-1){
}

Socket::~Socket(){
    if(IsValid())
        close(m_sockfd);
}

//server function
bool Socket::Create(){
    m_sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(!IsValid())
        return false;
    return true;
}

bool Socket::Bind(const int port){
    if(!IsValid())
        return false;
    m_address.sin_family = AF_INET;
    m_address.sin_addr.s_addr = htonl(INADDR_ANY);
    m_address.sin_port = htons(port);

    int bindReturn = bind(m_sockfd,(struct sockaddr*)&m_address,sizeof(m_address));
    if(bindReturn == -1)
        return false;
    return true;
}

bool Socket::Listen() const{
    if(!IsValid())
        return false;
    
    int listenReturn = listen(m_sockfd,MAXCONNECTION);
    if(listenReturn == -1)
        return false;
    return true;
}

bool Socket::Accept(Socket& clientSocket) const{
    int clientSocketLength = sizeof(clientSocket.m_address);//这里为什么可以访问？
    clientSocket.m_sockfd = ::accept(m_sockfd,(struct sockaddr*)&clientSocket.m_address,(socklen_t *)&clientSocketLength);//??

    if(clientSocket.m_sockfd == -1)
        return false;
    return true;
}

//client function
bool Socket::Connect(const std::string& host,const int port){
    if(!IsValid())
        return false;
    m_address.sin_family = AF_INET;
    m_address.sin_addr.s_addr = inet_addr(host.c_str());
    m_address.sin_port = htons(port);

    int connectReturn = ::connect(m_sockfd,(struct sockaddr*)&m_address,sizeof(m_address));
    if(connectReturn == -1)
        return false;
    return true;
}

//Data Transmission
bool Socket::Send(Socket& socket,const std::string& message) const{
    int result =::send(socket.m_sockfd,message.c_str(),message.size(),MSG_NOSIGNAL);
    if(result == -1)
        return false;
    return true;
}

int Socket::Recieve(Socket& socket,std::string& message) const{
    char buffer[MAXRECEIVE+1];
    message.clear();
    memset(buffer,0,MAXRECEIVE+1);

    int numRecieve =::recv(socket.m_sockfd,buffer,MAXRECEIVE,0);
    if(numRecieve == -1){
        std::cout<<"error in Socket::Recieve"<<std::endl;
        return 0;
    }else if(numRecieve == 0){
        return 0;
    }else{
        message = buffer;
        return numRecieve;
    }
}

void Socket::SetNonBlocking(const bool flags){
    //TODO
}

bool Socket::IsValid() const{
    return m_sockfd != 1;
}