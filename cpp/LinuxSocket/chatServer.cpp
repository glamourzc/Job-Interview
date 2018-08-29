#include "serverSocket.h"
#include "socketException.h"
#include <iostream>
using namespace std;

int main(){
    cout<<"Running Server..."<<endl;
    try{
        ServerSocket server(6666);
        while(1){
            Socket newSocket;
            server.Accept(newSocket);

            try{
                
                string message;
                server.Recieve(newSocket,message);
                cout<<message<<endl;

                server.Send(newSocket,message);
            }catch(SocketException&){}
        }
    }catch(SocketException& ex){
        cout<<ex.Description()<<endl;
    }
    return 0;
}