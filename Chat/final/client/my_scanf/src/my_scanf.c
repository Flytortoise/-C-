//自写版本
//2017年2月8日 08:56:38
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>

#define SUCCESS 1

char my_getchar()
{
    struct termios tm,tm_old;
	int fd = STDIN_FILENO;
	char c;
	if(tcgetattr(fd,&tm) < 0)
	{
	    perror("tcgetatter error !");
		exit(-1);
	}

	tm_old = tm;
	cfmakeraw(&tm);
	if(tcsetattr(fd,TCSANOW,&tm) < 0)
	{
	    perror("tcsetatter tm error!");
		exit(-1);
	}

	c = fgetc(stdin);

	if(tcsetattr(fd,TCSANOW,&tm_old) < 0)
	{
	    perror("tcsetatter tm_old error!");
		exit(-1);
	}

	return c;
}

int my_scanf(char s[],int len)
{
    int i;
	for(i = 0; i < len - 1; i++)
	{
	    __fpurge(stdin);
	    s[i] = my_getchar();

		if(s[i] == 127 && i == 0)
		{
		    i--;
			continue;
		}

		if(s[i] == '\n' || s[i] == '\r')
		{
		    s[i] = '\0';
			break;
		}
		else
		{
			if(s[i] == 127 && i > 0)
			{
		    	printf("\b \b");
				i = i - 2;
			}
			else
			{
			    printf("*");
			}
		}
	}

	s[len - 1] = '\0';
	printf("\n");

	return SUCCESS;
}


void me_scanf(char *str)
{
    int i = 0;
	str[i] = getchar();
	while(str[i] != '\n')
	{
	    i++;
	    str[i] = getchar();
	}

	str[i] = '\0';


}
