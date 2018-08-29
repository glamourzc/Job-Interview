#include "serverSocket.h"
#include "socketException.h"

ServerSocket::ServerSocket(const int port){
    if(!Socket::Create()){
        throw SocketException("could not create server socket.");
    }

    if(!Socket::Bind(port)){
        throw SocketException("could not bind to port.");
    }

    if(!Socket::Listen()){
        throw SocketException("could not listen to socket.");
    }
}

ServerSocket::~ServerSocket(){}

void ServerSocket::Accept(Socket& socket){
    if(!Socket::Accept(socket)){
        throw SocketException("could not accept socket.");
    }
}
