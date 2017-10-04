/***********************************
*函数名：Select_func
*功能：各功能入口函数
*时间：2017年2月25日 14:34:11
************************************/

#include <stdio.h>
#include <signal.h>

#include "func.h"
#include "Pass.h"

extern int fd[2];
extern int move;
int Select_func(int client_sock,int *flag,char *name)
{
	Node user;

	printf("请输入要执行的操作:\n");
	scanf("%d",&user.action);
	if(move == 0)		//如果被踢出，改变标志位
	{
	    user.action = -1;
	}
	write(client_sock,&user,sizeof(user));
	switch(user.action)
	{
		case -1:
		{
		    return 0;		//被踢出直接返回
		}break;

	    case 1:
		{
		    Look(client_sock);		//查看在线用户
		}break;

	    case 2:
		{
		    Chat(client_sock);		//私聊
		}break;

	    case 3:
		{
		    All_Chat(client_sock);		//群聊
		}break;

	    case 4:
		{
		    Fast(client_sock);		//发送快捷消息
		}break;

	    case 5:
		{
		    Face(client_sock);		//发送表情
		}break;

	    case 6:
		{
		    Change_name(client_sock);		//更改用户名
		}break;

	    case 7:
		{
		    Change_passwd(client_sock);		//更改密码
		}break;

	    case 8:
		{
		    interface_main(name);		//查看帮助
		}break;

	    case 9:
		{
			File(client_sock);
		}break;

	    case 10:
		{
		    return Exit_Log();		//退出登录
		}break;

	    case 11:
		{
		    Exit(flag);			//退出聊天室
		}break;

		case 12:
		{
		    Save();			//查看聊天记录
		}break;

		default :
		{
			printf("请输入正确的指令!!\n");
		}
	}

	return 0;
}


//超级用户功能
int Select_func2(int client_sock,int *flag,char *name)
{
	Node user;

	printf("请输入要执行的操作:");
	scanf("%d",&user.action);
	write(client_sock,&user,sizeof(user));
	switch(user.action)
	{
	    case 1:
		{
		    Look(client_sock);
		}break;

	    case 2:
		{
		    Chat(client_sock);
		}break;

	    case 3:
		{
		    All_Chat(client_sock);
		}break;

	    case 4:
		{
		    Fast(client_sock);
		}break;

	    case 5:
		{
		    Face(client_sock);
		}break;

	    case 6:
		{
		    Change_name(client_sock);
		}break;

	    case 7:
		{
		    Change_passwd(client_sock);
		}break;

	    case 8:
		{
		    interface_main2(name);
		}break;

	    case 9:
		{
			File(client_sock);
		}break;

	    case 10:
		{
		    return Exit_Log();
		}break;

	    case 11:
		{
		    Exit(flag);
		}break;

		case 12:
		{
		    Save();
		}break;

	    case 13:
		{
		    Remove(client_sock);		//踢出用户
		}break;

	    case 14:
		{
		    OffChat(client_sock);		//禁言
		}break;

	    case 15:
		{
		    OnChat(client_sock);		//解除禁言
		}break;
		default :
		{
			printf("请输入正确的指令!!\n");
		}
	}

	return 0;
}
