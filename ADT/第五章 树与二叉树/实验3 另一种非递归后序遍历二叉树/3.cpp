#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 30

typedef struct node
{
	char data;
	struct node *lchild, *rchild;
}BSTree;

void Postorder1(BSTree *p)
{
	BSTree *stack[MAXSIZE],*q;
	int b,i = -1;
	do							//后续遍历
	{
		while(p != NULL)		//将所有左孩子入栈
		{
			stack[++i] = p;
			p = p->lchild;
		}

		q = NULL;
		b = 1;		//置以访问过的标志

		while(i >= 0 && b)	//栈非空，且当前栈顶结点的左子树已经遍历过
		{
			p = stack[i];
			if(p->rchild == q)		//没有右孩子，或者右孩子已经遍历过
			{
				printf("%3c",p->data);
				i--;
				q = p;
			}
			else				//当前栈顶有右孩子，所以先遍历其右孩子
			{	
				p = p->rchild;	
				b = 0;
			}
		}
	}while(i >= 0);
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
	printf("Make a tree :\n");
	Createb(&root);
	printf("Psotorder output :\n");
	Postorder1(root);
	printf("\n");

	system("pause");
}