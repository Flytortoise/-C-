/*	���ݣ��ڱ�ͷ����Ԫ�ؽ���һ��������
	������������������෴
	2016��9��8�� 23:01:22*/


#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char data;	//dataΪ����������Ϣ
	struct node *next;	//����ָ����
}LNode;

LNode * CreatLinkList()	//�ڱ�ͷ���ɵ�����2
{
	char x;
	LNode *head,*p;
	head = (LNode *)malloc(sizeof(LNode));
	head->next = NULL;
	printf("Input any char string:\n");
	scanf("%c",&x);
	while(x != '\n')
	{
		p = (LNode *)malloc(sizeof(LNode));	//�����µĽ��
		p->data = x;		//��������
		p->next = head->next;		//���ý���nextָ��ͷ�����¸����
		head->next = p;			//��ͷ�����ָ�������ɵĽ�㣬�������
		scanf("%c",&x);
	}
	return head;
}

void main()
{
	LNode *h,*p;
	h = CreatLinkList();
	p = h->next;
	while(p != NULL)		//���������
	{
		printf("%c ",p->data);
		p = p->next;
	}
	printf("\n");
}