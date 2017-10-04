#ifndef PASS
#define PASS

#define ACC_SIZE 20
#define PASS_SIZE 20
#define ID_SIZE 5
#define BUFF_SIZE 100
#define SEND_SIZE 100
#define EXIT 6
#define SUCCESS 1

typedef struct online
{
	int action;
    int sock;
	int flag;
	int chat_flag;
	int send_flag;
	int off_line;
	char id[ID_SIZE];
    char name[ACC_SIZE];
	char password[PASS_SIZE];
	char buffer[BUFF_SIZE];
	char send[SEND_SIZE];
	struct online *next;
}Node,*pNode;


Node Pass(int);

#endif
