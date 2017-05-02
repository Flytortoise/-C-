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
	do							//��������
	{
		while(p != NULL)		//������������ջ
		{
			stack[++i] = p;
			p = p->lchild;
		}

		q = NULL;
		b = 1;		//���Է��ʹ��ı�־

		while(i >= 0 && b)	//ջ�ǿգ��ҵ�ǰջ�������������Ѿ�������
		{
			p = stack[i];
			if(p->rchild == q)		//û���Һ��ӣ������Һ����Ѿ�������
			{
				printf("%3c",p->data);
				i--;
				q = p;
			}
			else				//��ǰջ�����Һ��ӣ������ȱ������Һ���
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