#include "clientSocket.h"
#include "socketException.h"

ClientSocket::ClientSocket(const std::string host,const int port){
    if(!Socket::Create()){
        throw SocketException("could not create client socket.");
    }
    if(!Connect(host,port)){
        throw SocketException("could not connect to port");
    }
}

ClientSocket::~ClientSocket(){}

bool ClientSocket::Send(const std::string& message){
    return Socket::Send(static_cast<Socket&>(*this),message);//?????
}

int ClientSocket::Recieve(std::string& message){
    return Socket::Recieve(static_cast<Socket&>(*this),message);
}