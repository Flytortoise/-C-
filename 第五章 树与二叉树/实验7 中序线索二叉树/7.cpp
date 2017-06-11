//2017年6月10日 17:16:29
//test: abc.d..e..fg...

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char data;
	int ltag,rtag;		//线索标记
	struct node *lchild, *rchild;
}TBTree;

TBTree *pre; 	//全局变量

void Thread(TBTree *p)
{
	 if(p != NULL)
	 {
	 	Thread(p->lchild);		//中序线索化，先对左孩子线索化
	 	if(p->lchild == NULL)	//若左孩子不存在啊，则进行前驱线索
	 	{
	 		p->lchild = pre;
	 		p->ltag = 1;
	 	}
	 	else			//左孩子存在
	 	{
	 		p->ltag = 0;
	 	}

	 	if(pre->rchild == NULL)		//此时p递归回上一层，让前驱pre指向后续p
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

TBTree *CreaThread(TBTree *b)	//建立中序线索二叉树
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
		root->lchild = b;	//以root的lchild指针指向的二叉树根节点*b
		pre = root;			//*pre是*b的前驱
		Thread(b);			//对二叉树进行中序线索化
		pre->rchild = root;		//加入头指针线索
		pre->rtag = 1;
		root->rchild = pre;		//头结点的rchild指针线索化为指向最后一个结点
	}

	return root;		//返回线索化后指向二叉树的头结点的指针
}

void Inorder(TBTree *b)		//中序遍历中序线索二叉树
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
		p = p->rchild;		//无后继线索，则p指向右孩子结点
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
	Createb(&root);		//建立一棵以root为根指针的二叉树
	printf("Preorder output : \n");
	Preorder(root);		//先序遍历二叉树
	printf("\n");
	p = CreaThread(root);		//中序线索化
	printf("Inorder output : \n");
	Inorder(p);		//中序遍历中序线索二叉树
	printf("\n");

	return 0;
}