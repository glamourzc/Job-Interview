#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
using namespace std;

#define MAXLINE 4096
int main(){
	int listenfd,connfd;
	struct sockaddr_in servaddr;
	char buff[4096];
	int n;

	listenfd = socket(AF_INET,SOCK_STREAM,0);
	if(listenfd == -1){
		cout<<"creat socket error:"<<strerror(errno)<<"errno:"<<errno<<")"<<endl;
		exit(0);
	}
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(6667);

	if(bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr))== -1){
		cout<<"creat socket error:"<<strerror(errno)<<"errno:"<<errno<<")"<<endl;
		exit(0);
	}

	if(listen(listenfd,10) == -1){
		cout<<"creat socket error:"<<strerror(errno)<<"errno:"<<errno<<")"<<endl;
		exit(0);
	}

	cout<<"=====waiting for client's request========"<<endl;
	while(1){
		connfd = accept(listenfd,(struct sockaddr*)NULL,NULL);
		if(connfd == -1){
			cout<<"creat socket error:"<<strerror(errno)<<"errno:"<<errno<<")"<<endl;
			continue;
		}
		n = recv(connfd,buff,MAXLINE,0);
		buff[n]='\0';
		printf("%s",buff);
		close(connfd);
	}
	close(listenfd);
	return 0;
}