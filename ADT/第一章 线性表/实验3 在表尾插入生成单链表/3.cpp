#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char data;
	struct node *next;
}LNode;

LNode *CreateLinkList()
{
	char x;
	LNode *head,*p ,*q;
	head = (LNode *)malloc(sizeof(LNode));
	head->next = NULL;
	p = head;
	q = p;
	printf("Input any char string : \n");
	scanf("%c",&x);
	while(x != '\n')
	{
		p = (LNode *)malloc(sizeof(LNode));
		p->data = x;
		p->next = NULL;
		q->next = p;
		q = p;
		scanf("%c",&x);
	}

	return head;
}

int main()
{
	LNode *h, *p;
	h = CreateLinkList();
	p = h->next;
	while(p != NULL)
	{
		printf("%c,",p->data);
		p = p->next;
	}
	printf("\n");

	return 0;
}