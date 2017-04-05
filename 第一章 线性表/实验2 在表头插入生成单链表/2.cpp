/*	内容：在表头插入元素建立一个单链表
	链表有误，输出与输入相反
	2016年9月8日 23:01:22*/


#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char data;	//data为结点的数据信息
	struct node *next;	//结点的指针域
}LNode;

LNode * CreatLinkList()	//在表头生成单链表2
{
	char x;
	LNode *head,*p;
	head = (LNode *)malloc(sizeof(LNode));
	head->next = NULL;
	printf("Input any char string:\n");
	scanf("%c",&x);
	while(x != '\n')
	{
		p = (LNode *)malloc(sizeof(LNode));	//创建新的结点
		p->data = x;		//输入数据
		p->next = head->next;		//将该结点的next指向头结点的下个结点
		head->next = p;			//将头结点再指向新生成的结点，插入完成
		scanf("%c",&x);
	}
	return head;
}

void main()
{
	LNode *h,*p;
	h = CreatLinkList();
	p = h->next;
	while(p != NULL)		//输出单链表
	{
		printf("%c ",p->data);
		p = p->next;
	}
	printf("\n");
}