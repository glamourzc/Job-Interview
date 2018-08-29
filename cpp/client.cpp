#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
using namespace std;

#define MAXLINE 4096

int main(int argc,char ** argv){
	int sockfd,n;
	char sendline[4096];
	struct sockaddr_in servaddr;
	
	if(argc !=2){
		printf("useage: ./client <ipaddress>\n");
		exit(0);
	}

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd == -1){
		cout<<"creat socket error:"<<strerror(errno)<<"errno:"<<errno<<")"<<endl;
		exit(0);
	}

	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(6667);
	servaddr.sin_addr.s_addr = inet_addr(argv[1]);
	
	if(connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr)) == -1){
		cout<<"creat socket error:"<<strerror(errno)<<"errno:"<<errno<<")"<<endl;
		exit(0);
	}

	cout<<"send msg to server:"<<endl;
	fgets(sendline,4096,stdin);
	if(send(sockfd,sendline,strlen(sendline),0) ==-1){
		cout<<"creat socket error:"<<strerror(errno)<<"errno:"<<errno<<")"<<endl;
		exit(0);		
	}
	close(sockfd);
	return 0;
}