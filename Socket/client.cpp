#include <winSock2.h>
#pragma comment(lib, "ws2_32.lib")
#include <iostream>
#include <string.h>
#include <stdlib.h>
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
	SOCKET clientfd;
 
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
	int ret;
	ret = connect(socketfd,(struct sockaddr *)&server_addr,sizeof(server_addr));
	if(ret == -1)
	{
		cout<<"connect error";
		return -1;
	}
	cout<<"connect sucessfully...\n";
		
	int writecnt = 0;
	char writebuff[20];
	while(1)
	{
		cin>>writebuff;
		writecnt = send(socketfd,writebuff,sizeof(writebuff),0);
		if(writecnt == -1)
		{
			cerr<<"write error"<<endl;
		}
		if(strcmp(writebuff,"end") == 0)
		{
			break;
		}
		cout<<writebuff<<endl;
		memset(writebuff,0,20);
	}
	system("pause");
	closesocket(socketfd);
	return 0;
}

