/***********************************
*函数名：Pass
*功能：用户登录
*时间：2017年2月25日 13:52:45
************************************/

#include <stdio.h>
#include <strings.h>
#include "interface.h"		//登录界面
#include "Pass.h"	
#include "my_scanf.h"		//密码保护


Node Pass(int client_sock)
{
	int i = 1;
    Node pass;		//返回的信息
	while(1)
	{	
		while(i == 1)
		{
			system("clear");
    		interface_pass();	//打印一次用户登录界面
			i--;
		}

		printf("请输入要执行的操作:");
		scanf("%d",&pass.action);
		if(pass.action == 1)		//登录操作
		{
		    printf("帐号:");
			scanf("%s",pass.id);
			printf("密码:");
			my_scanf(pass.password,PASS_SIZE);		//输入保护密码
			write(client_sock,&pass,sizeof(pass));	//发送给服务器进行处理
		}
		else
		{
		    if(pass.action == 2)	//注册操作
			{
	   		 	printf("用户名:");
				scanf("%s",pass.name);
				printf("密码:");
				scanf("%s",pass.password);		//注册不进行密码保护
				write(client_sock,&pass,sizeof(pass));
			}
			else		//退出操作
			{
			    write(client_sock,&pass,sizeof(pass));
				return pass;		//退出直接返回
			}
		}
	
		read(fd[0],&pass,sizeof(pass));		//读取服务器处理后的结果
		system("clear");
		interface_pass();
		switch(pass.action)
		{
		    case 1:
		    {
				printf("登录成功!\n");
				return pass;
			}break;
	
			case 2:
			{
				printf("密码错误!\n");
			}break;
	
			case 3:
			{
				printf("帐号未注册!\n");
			}break;
	
			case 4:
			{
				printf("帐号已存在!\n");
			}break;
	
			case 5:
			{
				printf("注册成功!\n");
				printf("您的帐号为:%s\n",pass.id);
			}break;

			case 6:
			{
			    printf("已在线，请勿重复登录!\n");
			}break;
		}
	}	
}
