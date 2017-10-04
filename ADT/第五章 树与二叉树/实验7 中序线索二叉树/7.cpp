//2017��6��10�� 17:16:29
//test: abc.d..e..fg...

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char data;
	int ltag,rtag;		//�������
	struct node *lchild, *rchild;
}TBTree;

TBTree *pre; 	//ȫ�ֱ���

void Thread(TBTree *p)
{
	 if(p != NULL)
	 {
	 	Thread(p->lchild);		//�������������ȶ�����������
	 	if(p->lchild == NULL)	//�����Ӳ����ڰ��������ǰ������
	 	{
	 		p->lchild = pre;
	 		p->ltag = 1;
	 	}
	 	else			//���Ӵ���
	 	{
	 		p->ltag = 0;
	 	}

	 	if(pre->rchild == NULL)		//��ʱp�ݹ����һ�㣬��ǰ��preָ�����p
	 	{
	 		pre->rchild = p;
	 		pre->rtag = 1;
	 	}
	 	else
	 	{
	 		pre->rtag = 0;
	 	}

	 	pre = p;
	 	Thread(p->rchild);
	 }
}

TBTree *CreaThread(TBTree *b)	//������������������
{
	TBTree *root;
	root = (TBTree *)malloc(sizeof(TBTree));
	root->ltag = 0;
	root->rtag = 1;
	if(b == NULL)
	{
		root->lchild = root;
	}
	else
	{
		root->lchild = b;	//��root��lchildָ��ָ��Ķ��������ڵ�*b
		pre = root;			//*pre��*b��ǰ��
		Thread(b);			//�Զ�������������������
		pre->rchild = root;		//����ͷָ������
		pre->rtag = 1;
		root->rchild = pre;		//ͷ����rchildָ��������Ϊָ�����һ�����
	}

	return root;		//������������ָ���������ͷ����ָ��
}

void Inorder(TBTree *b)		//���������������������
{
	TBTree *p;
	p = b->lchild;
	while(p != b)
	{
		while(p->ltag == 0)
		{
			p = p->lchild;
		}
		printf("%3c",p->data);

		while(p->rtag == 1 && p->rchild != b)
		{
			p = p->rchild;
			printf("%3c",p->data);
		}
		p = p->rchild;		//�޺����������pָ���Һ��ӽ��
	}
}

void Preorder(TBTree *p)
{
	if(p != NULL)
	{
		Preorder(p->lchild);
		printf("%c",p->data);
		Preorder(p->rchild);
	}
}

void Createb(TBTree **p)
{
	char ch;
	scanf("%c",&ch);
	if(ch != '.')
	{
		*p = (TBTree *)malloc(sizeof(TBTree));
		(*p)->data = ch;
		Createb(&(*p)->lchild);
		Createb(&(*p)->rchild);		
	}
	else
	{
		*p = NULL;
	}
}

int main()
{ 
	TBTree *root, *p;
	printf("Preorder entet bitree with '..' : \n");
	Createb(&root);		//����һ����rootΪ��ָ��Ķ�����
	printf("Preorder output : \n");
	Preorder(root);		//�������������
	printf("\n");
	p = CreaThread(root);		//����������
	printf("Inorder output : \n");
	Inorder(p);		//���������������������
	printf("\n");

	return 0;
}