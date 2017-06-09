//2017年6月9日 22:11:17
//input : abc.d..e..fg...

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

typedef struct node
{
	char data;
	struct node * lchild, * rchild;
}BSTree;

typedef struct 
{
	BSTree *data[MAXSIZE];
	int rear,front;
}SeQueue;

void Init_SeQueue(SeQueue **q)	//循环队列初始化
{
	*q = (SeQueue *)malloc(sizeof(SeQueue));
	(*q)->front = 0;
	(*q)->rear = 0;
} 

int Empty_SeQueue(SeQueue *q)
{
	if(q->front == q->rear)	//空队
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void In_SeQueue(SeQueue *q, BSTree *x)
{
	if ((q->rear+1)%MAXSIZE == q->front)
	{
		printf("Queue is Full !!\n");
	}
	else
	{
		q->rear = (q->rear + 1) % MAXSIZE;
		q->data[q->rear] = x;
	}
}

void Out_SeQueue(SeQueue *q, BSTree **x)
{
	if (q->front == q->rear)
	{
		printf("Queue is empty!\n");
	}
	else
	{
		q->front = (q->front + 1) % MAXSIZE;
		*x = q->data[q->front];
	}
}

void Inorder(BSTree *p)		//中序遍历二叉树
{
	if(p != NULL)
	{
		Inorder(p->lchild);
		printf("%3c",p->data);
		Inorder(p->rchild);
	}
}

void Createb(BSTree **p)	//生成一棵二叉树
{	
	char ch;
	scanf("%c",&ch);
	if(ch != '.')
	{
		*p = (BSTree *)malloc(sizeof(BSTree));
		(*p)->data = ch;
		Createb(&(*p)->lchild);
		Createb(&(*p)->rchild);
	}
	else
	{
		*p = NULL;
	}
}

void Transleve(BSTree *t)	//层次遍历二叉树
{
	SeQueue *Q;
	BSTree *p;
	Init_SeQueue(&Q);	//队列初始化
	if(t != NULL)
	{
		printf("%2c",t->data);
	}
	In_SeQueue(Q,t);	//指向二叉树的根指针t入队
	while(!Empty_SeQueue(Q))	//队Q非空
	{
		Out_SeQueue(Q,&p);		//队头结点出队，并赋给p
		if(p->lchild != NULL)	//p有左孩子时
		{
			printf("%2c",p->lchild->data);
			In_SeQueue(Q,p->lchild);
		}

		if(p->rchild != NULL)	//p有右孩子时
		{
			printf("%2c",p->rchild->data);
			In_SeQueue(Q,p->rchild);
		}	
	}
}

void main()
{
	BSTree *root;
	printf("Preorder entet bitree with '. .' : \n");
	Createb(&root);		//建立一棵以root以根指针的二叉树
	printf("Inorder output : \n");
	Inorder(root);		//中序遍历二叉树
	printf("\n");
	Transleve(root);	//按层次遍历二叉树
	printf("\n");
}

