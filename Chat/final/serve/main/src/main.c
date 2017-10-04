/***********************************
*函数名：main
*功能：接收客户端
*时间：2017年2月25日 13:35:58
************************************/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#include "Start.h"
#include "Pass.h"

#define SERVE_IP "192.168.1.189"	//服务器IP
#define PORT 8000		//端口号

pNode head;

int main()
{
    int on;
	int serve_sock;
	int client_sock;
	int sockaddr_len;
	pthread_t client_tidp;
	struct sockaddr_in serve_addr;
	struct sockaddr_in client_addr;

	head = (pNode)malloc(sizeof(Node));		//在线用户链表的头结点
	if(head == NULL)
	{
	    printf("Head malloc error !\n");
		exit(-1);
	}
	bzero(head,sizeof(Node));
	head->next = NULL;

    sockaddr_len = sizeof(struct sockaddr);
    serve_sock = socket(AF_INET,SOCK_STREAM,0);	//创建服务器套接字，遵循TPC协议
	if(serve_sock < 0)
	{
	    perror("Serve_sock error!");
		exit(-1);
	}

	on = 1;
	if(setsockopt(serve_sock,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on)) < 0)
	{
	    perror("Setsockopt error !");
		exit(-1);
	}			//使服务器可以多次绑定

    bzero(&serve_addr,sizeof(serve_addr));
	serve_addr.sin_family = AF_INET;	
	serve_addr.sin_port = htons(PORT);	
	serve_addr.sin_addr.s_addr = inet_addr(SERVE_IP);

	if(bind(serve_sock,(struct sockaddr *)&serve_addr,sockaddr_len) < 0 )
	{
        perror("Bind error!");
		exit(-1);
	}			//绑定套接字

	if(listen(serve_sock,5) < 0)		//设置监听器
	{
	    perror("Listen error !");
		exit(-1);
	}

	while(1)		//重复接收客户端
	{	    
    	bzero(&client_addr,sizeof(client_addr));
		if((client_sock = accept(serve_sock,(struct sockaddr *)&client_addr,&sockaddr_len)) < 0)
		{
		    perror("Accept error !");
			exit(-1);
		}			//接收客户端

		printf("Accept success :%s\n",inet_ntoa(client_addr.sin_addr.s_addr));	//打印接收到的客户端IP地址
		if(pthread_create(&client_tidp,NULL,Start,(void *)&client_sock) != 0)	//创建线程，单独为客户端工作
		{
		    perror("Pthread_create error!");
			exit(-1);
		}
	}

    return 0;
}
