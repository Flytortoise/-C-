#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 30

typedef struct node
{
	char data;
	struct node *lchild, *rchild;
}BSTree;

void Preorder(BSTree *p)
{
	if(p != NULL)
	{
		printf("%3c",p->data);
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
}

BSTree *Search(BSTree *p, char x)
{
	BSTree *stack[MAXSIZE];
	int i = 0;
	stack[0] = NULL;
	while(i > 0)
	{
		if(p != NULL)
		{
			if(p->data == x)
			{
				return p;
			}
			else
			{
				stack[++i] = p;
				p = p->lchild;
			}
		}
		else
		{
			p = stack[i--];
			p = p->rchild;
		}

		if(p == NULL && i == 0)
		{
			break;
		}
	}

	return NULL;
}

int Countleaf(BSTree *bt)
{
	if(bt == NULL)
	{
		return 0;
	}
	
	if(bt->lchild == NULL && bt->rchild == NULL)
	{
		return 1;
	}

	return (Countleaf(bt->lchild) + Countleaf(bt->rchild));
}

int Depth(BSTree *p)
{
	int lchild,rchild;

	if(p == NULL)
	{
		return 0;
	}
	else
	{
		lchild = Depth(p->lchild);
		rchild = Depth(p->rchild);

		return lchild > rchild ? (lchild + 1) : (rchild + 1);
	}
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
	BSTree *root, *p;
	char x;
	printf("Preorder entet bitree with '. .' :\n");
	Createb(&root);
	printf("Preorder output :\n");
	Preorder(root);
	printf("\n");
	getchar();
	printf("Input element of Search : \n");
	scanf("%d",&x);
	p = Search(root,x);
	if(p == NULL)
	{	
		printf("No found !\n");
	}
	else
	{
		printf("Element Searched is %c\n",p->data);
	}

	printf("leaf of tree is %d\n",Countleaf(root));
	printf("Depth of tree is %d\n",Depth(root));

	system("pause");
}