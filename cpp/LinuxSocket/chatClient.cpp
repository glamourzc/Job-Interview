#include "clientSocket.h"
#include "socketException.h"
#include <iostream>
#include <thread>
using namespace std;

ClientSocket client("127.0.0.1",6666);

void read(){
    while(1){
        try
        {
            string returnMessage;
            client.Recieve(returnMessage);
            cout<<returnMessage<<endl;
        }catch(SocketException& ex){
            cout<<"error:"<<ex.Description()<<endl;
            break;
        }
    }
}

void write(){
    while(1){
        try
        {
            string input;
            cin>>input;
            client.Send(input);
        }catch(SocketException& ex){
            cout<<"error:"<<ex.Description()<<endl;
            break;
        }
    }
}
int main(){
    cout<<"Running Client:"<<endl;
    thread r(read);
    thread w(write);
    
    r.join();
    w.join();

    cout<<"user exit\n";
    return 0;
}