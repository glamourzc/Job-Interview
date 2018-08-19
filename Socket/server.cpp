#include <winSock2.h>
#pragma comment(lib, "ws2_32.lib")
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define MYPORT 6666
#define MYADDR "127.0.0.1"
 
int main()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	wVersionRequested = MAKEWORD(2,2);
 
	if(WSAStartup(wVersionRequested,&wsaData) != 0)
	{
		return 1;
	}
	if(wsaData.wVersion != wVersionRequested)
	{
		WSACleanup();
		return 1;
	}
	SOCKET socketfd;
	int len;
	socketfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(socketfd == INVALID_SOCKET)
	{
		cout<<"create error";
		return -1;
	}
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(MYPORT);
	server_addr.sin_addr.s_addr = inet_addr(MYADDR);
	int opt = 1;
	int ret;
	ret = setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt));
	if (ret == SOCKET_ERROR)
	{
		cout<<"error with code = "<<WSAGetLastError()<<endl;
		exit(1);
	}
	cout<<"socket successfully"<<endl;
	
	ret = bind(socketfd,(struct sockaddr *)&server_addr,sizeof(server_addr));
	if(ret == -1)
	{
		cout<<"bind error"<<endl;
		return -1;
	}
	cout<<"bind sucessfully...\n";
 
	ret = listen(socketfd,10);
	if(ret == -1)
	{
		cout<<"listen error"<<endl;
		return -1;
	}
	cout<<"listen sucessfully...\n";
 
	int clientfd = 0;
	len = sizeof(server_addr);
	clientfd = accept(socketfd,(struct sockaddr *)&client_addr,&len);
	if(clientfd == INVALID_SOCKET)
	{
		cout<<"accept error"<<endl;
		return -1;
	}
	cout<<"accept sucessully...\n";
	cout<<inet_ntoa(client_addr.sin_addr)<<" "<<ntohs(client_addr.sin_port)<<endl;
 
	int recvcnt = 0;
	char recvbuff[20];
	while(1)
	{
		recvcnt = recv(clientfd,recvbuff,sizeof(recvbuff),0);
 
		if(recvcnt == SOCKET_ERROR)
		{
			cerr<<"read error"<<endl;
			break;
		}
		if(recvcnt == 0)
		{
			cout<<"client close"<<endl;
			break;
		}
		cout<<recvbuff<<endl;
		if(strcmp(recvbuff,"end") == 0)
		{
			break;
		}
		memset(recvbuff,0,20);
	}
	closesocket(clientfd);
	closesocket(socketfd);
	return 0;
}

