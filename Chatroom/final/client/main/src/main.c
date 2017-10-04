/***********************************
*函数名：main
*功能：链接服务器
*时间：2017年2月25日 13:36:09
************************************/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#define PORT 8000

int main(int argc, char *argv[])
{
    if(argc != 2)
	{
	    printf("请输入服务器ID !\n");
		exit(-1);
	}

	int client_sock;
	struct sockaddr_in serve_addr;

	client_sock = socket(AF_INET,SOCK_STREAM,0);	//创建客户端的套接字
	if(client_sock < 0)
	{
	    perror("Client_sock error!");
		exit(-1);
	}

	bzero(&serve_addr,sizeof(serve_addr));
	serve_addr.sin_family = AF_INET;
	serve_addr.sin_port = htons(PORT);
	serve_addr.sin_addr.s_addr = inet_addr(argv[1]);

	if(connect(client_sock,(struct sockaddr *)&serve_addr,sizeof(struct sockaddr_in)) < 0)		//链接服务器
    {
	    perror("Connect error!");
		exit(-1);
	}
    Start(client_sock);		//链接成功后执行后续操作

	return 0;
}
