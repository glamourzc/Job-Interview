#include "clientSocket.h"
#include "socketException.h"
#include <iostream>
using namespace std;
int main(){
    cout<<"Running Client..."<<endl;
    try{
        ClientSocket client("127.0.0.1",6666);
        string input;
        cin>>input;
        client.Send(input);
        string returnMessage;
        client.Recieve(returnMessage);
        cout<<returnMessage<<endl;
    }catch(SocketException& ex){
        cout<<"error:"<<ex.Description()<<endl;
    }
    return 0;
}