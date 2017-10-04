//代码有误！！2017年5月3日 23:10:13

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 30

typedef struct node
{
	char data;
	struct node * lchild, *rchild;
}BSTree;

char pred[MAXSIZE];
char ind[MAXSIZE];

int i = 0;
int j = 0;


void Preorder(BSTree *p)
{
	if(p != NULL)
	{
		pred[i++] = p->data;
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
}

void Inorder(BSTree *p)
{
	if(p != NULL)
	{
		Inorder(p->lchild);
		ind[j++] = p->data;
		Inorder(p->rchild);
	}
}

void Pre_In_order(char pred[], char ind[], int i, int j,int k, int h, BSTree **p)
{
				//i,j,k,h分别为当前子树先序遍历和中序遍历的下、上界
	int m;
	*p = (BSTree *)malloc(sizeof(BSTree));
	(*p)->data = pred[i];
	m = k;		//m指向ind数组所存储的中序遍历序列中第一个结点
	while(ind[m] != pred[i])	//找到根节点在中序遍历中所在的位置
	{
		m++;
	}

	if(m == k)	//若是中序遍历序列的第一个结点，则无左子树
	{
		(*p)->lchild = NULL;
	}
	else
	{
		Pre_In_order(pred,ind,i+1,i+m-k,k,m-1,&(*p)->lchild);
		//根据根节点划分出中序遍历序列的两个部分，继续构造左、右子树
	}

	if(m == h)
	{
		(*p)->rchild = NULL;
	}
	else
	{
		Pre_In_order(pred,ind,i+m-k+1,j,m+1,h,&(*p)->rchild);
	}
}

void Print_Inorder(BSTree *p)
{
	if(p != NULL)
	{
		Print_Inorder(p->lchild);
		printf("%3c",p->data);
		Print_Inorder(p->rchild);
	}
}

void Createb(BSTree**p)
{
	char ch;
	scanf("%c",&ch);
	if( ch != '.')
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
	BSTree *root, *root1;
	printf("Preorder entet bitree with '..' : \n");
	Createb(&root);
	printf("Inorder putput root :\n");
	Print_Inorder(root);
	printf("\n");

	Inorder(root);
	if(i > 0)
	{
		Pre_In_order(pred,ind,0,i-1,0,j-1,&root1);
	}
	printf("Inorder output root1:\n");
	Print_Inorder(root1);
	printf("\n");

	system("pause");
}