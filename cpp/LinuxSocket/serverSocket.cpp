#include "serverSocket.h"
#include "socketException.h"
#include <iostream>


std::list<Socket*> ServerSocket::clientSockets;
std::mutex ServerSocket::mtx;
bool ServerSocket::serviceFlag = true;

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
    StartService();

}

ServerSocket::~ServerSocket(){
    for(auto i:clientSockets){
        delete (i);
    }
}

void ServerSocket::Accept(Socket& socket){
    if(!Socket::Accept(socket)){
        throw SocketException("could not accept socket.");
    }
}

void ServerSocket::StartService(){
    while(serviceFlag){
        if(clientSockets.size() >= static_cast<unsigned int>(MAXCONNECTION))
            serviceFlag = false;
        else  serviceFlag = AcceptNewClient();
    }
}

bool ServerSocket::AcceptNewClient(){
    Socket* clientSocket = new Socket;
    Accept(*clientSocket);
    AddClient(clientSocket);
    try{
        std::thread tm(ProcessMessage,clientSocket);
        tm.detach();
    }catch(const std::system_error& e){
        std::cout<<e.code()<<":"<<e.what()<<std::endl;
        return false;
    }
    return true;
}
void ServerSocket::AddClient(Socket* scoket){
    mtx.lock();

    clientSockets.push_back(scoket);
    std::cout<<"Now "<<clientSockets.size()<<" Users."<<std::endl;
    std::cout<<"New User:" << scoket->GetAddress()<<" "<<scoket->GetPort()<<std::endl;
    
    mtx.unlock();
}

void ServerSocket::DeleteClient(Socket* socket){
    mtx.lock();

    std::list<Socket*>::iterator iter;
    for(iter = clientSockets.begin();iter != clientSockets.end();iter++){
        if((*iter)->GetAddress() == socket->GetAddress() 
            && (*iter)->GetPort() == socket->GetPort())
            {
                delete (*iter);
                clientSockets.erase(iter);
                std::cout<<"Delete successful.\n";
                break;
            }
    }
    mtx.unlock();
}

void ServerSocket::ProcessMessage(Socket* socket){
    std::string message;
    while(serviceFlag){
        Recieve(*socket,message);
        if(message == "exit"){
            Send(*socket,"user_exit");
            DeleteClient(socket);
            break;
        }else{
            SendMsgToAllUsers(message);
        }
    }

}

void ServerSocket::SendMsgToAllUsers(const std::string& message){
    for(auto i:clientSockets)
        Send(*i,message);
}