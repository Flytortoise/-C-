#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 30
typedef struct node
{
	char data;
	struct node *lchild,*rchild;
}BSTree;

void Preorder(BSTree *p)
{
	BSTree *stack[MAXSIZE];
	int i = 0;
	stack[0] = NULL;
	while(p != NULL || i > 0)
	{
		if(p != NULL)
		{
			printf("%3c",p->data);
			stack[++i] = p;
			p = p->lchild;
		}
		else
		{
			p = stack[i--];
			p = p->rchild;
		}
	}
}

void Inorder(BSTree *p)
{
	BSTree *stack[MAXSIZE];
	int i = 0;
	stack[0] = NULL;
	while(i >= 0)
	{
		if(p != NULL)
		{
			stack[++i] = p;
			p = p->lchild;
		}
		else
		{
			p = stack[i--];
			printf("%3c",p->data);
			p = p->rchild;
		}

		if(p == NULL && i == 0)
		{
			break;
		}
	}
}

void Postorder(BSTree *p)
{
	BSTree *stack[MAXSIZE];
	int b[MAXSIZE], i = 0;
	stack[0] = NULL;
	do
	{
		if(p != NULL)
		{
			stack[++i] = p;
			b[i] = 0;
			p = p->lchild;
		}
		else
		{
			p = stack[i--];

			if(!b[i + 1])
			{
				stack[++i] = p;
				b[i] = 1;
				p = p->rchild;
			}
			else
			{
				printf("%3c",p->data);
				p = NULL;
			}
		}
	}while(p != NULL || i > 0);
}

void Createb(BSTree **p)
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

void main()
{
	BSTree *root;
	printf("Preorder entet bitree with '. .':\n");
	Createb(&root);
	printf("Preorder output :\n");
	Preorder(root);
	printf("\n");
	printf("Inorder output :\n");
	Inorder(root);
	printf("\n");
	printf("Postorder output :\n");
	Postorder(root);
	printf("\n");
} 