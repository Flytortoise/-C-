//2017年6月11日 09:53:09
/*test : 
	8
	7 19 2 6 32 3 21 10
说明：先生成升序单链表，然后取出前两个作为树结点的左右孩子，该结点的值为两个孩子之和，再将该
	  结点插入到单链表中，当单链表处理完毕，则生成哈夫曼树
	  哈夫曼编码：左孩子编号为0，右孩子为1。后序遍历哈夫曼树，打上编号。
	  			  因为叶子结点是最初输入的权值，所以，遍历到叶子结点时，输出一长串的编码

*/
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 30

typedef struct node
{
	char data;
	struct node *lchild, *rchild;
	struct node *next;	//
}BSTree_Link;

BSTree_Link *CreateLinkList(int n)		//根据叶子结点的权值生成一个升序单链表
{
	BSTree_Link *link, *q, *p, *s;
	int i;
	link = (BSTree_Link *)malloc(sizeof(BSTree_Link));	//头结点
	s = (BSTree_Link *)malloc(sizeof(BSTree_Link));		//第一个结点

	scanf("%d",&s->data);
	s->lchild = NULL;
	s->rchild = NULL;
	s->next = NULL;
	link->next = s;

	for(i = 2; i <= n; i++)
	{
		s = (BSTree_Link *)malloc(sizeof(BSTree_Link));
		scanf("%d",&s->data);
		s->lchild = NULL;
		s->rchild = NULL;
		q = link;
		p = q->next;
		while(p != NULL)		
		{
			if(s->data > p->data)	//查找插入位置
			{
				q = p;
				p = p->next;
			}
			else			
			{
				q->next = s;
				s->next = p;
				break;				
			}
		}

		if(s->data > q->data)	//跳出循环，说明s的值比连表中的值都大，放在表尾
		{
			q->next = s;
			s->next = p;
		}
	
	}

	return link;
}

void print(BSTree_Link *h)	//打印单链表
{
	BSTree_Link *p;
	p = h->next;
	while(p != NULL)
	{
		printf("%d  ",p->data);
		p = p->next;
	}

	printf("\n");
}

BSTree_Link *HuffTree(BSTree_Link *link)		//生成哈夫曼树
{	
	BSTree_Link *p, *q, *s;
	while(link->next != NULL)		//遍历单链表
	{
		p = link->next;		//取出第一个结点
		q = p->next;		//取出第二个结点
		link->next = q->next;	//将这两个结点从链表中去除，此处应该检查q是否为null
		s = (BSTree_Link *)malloc(sizeof(BSTree_Link));	//树的结点
		s->data = p->data + q->data;
		s->lchild = p;	//左孩子小，右孩子大
		s->rchild = q;
		q = link;
		p = q->next;
		while(p != NULL)		//将s插入到链表中
		{
			if(s->data > p->data)
			{
				q = p;
				p = p->next;
			}
			else
			{
				q->next = s;
				s->next = p;
				break;
			}
		}

		if(q != link && s->data > q->data)	//表尾处理
		{
			q->next = s;
			s->next = p;
		}
	}

	return s;
}

void Inorder(BSTree_Link *p)
{
	if(p != NULL)
	{
		Inorder(p->lchild);
		printf("%d ",p->data);
		Inorder(p->rchild);
	}
}

void Preorder(BSTree_Link *p)
{
	if(p != NULL)
	{
		printf("%d ",p->data);
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
}

void HuffCode(BSTree_Link *p)
{
	BSTree_Link *stack[MAXSIZE], *q;
	int b, i = -1, j = 0, k, code[MAXSIZE];
	do 									//后序遍历二叉树，并输出哈夫曼编码
	{
		while(p != NULL)				//将*p的所以左分支上的左孩子入栈
		{
			if(p->lchild == NULL && p->rchild == NULL)		//叶子结点
			{
				printf("key = %3d, code : ",p->data);		//输出叶子结点信息
				for(k = 0; k < j; k++)				//输出哈夫曼编码
				{
					printf("%d",code[k]);
				}
				printf("\n");
				j--;
			}
			stack[++i] = p;		//此时右叶子结点也会入栈
			p = p->lchild;
			code[j++] = 0;		//左孩子为0，右孩子为1
		}

		q = NULL;
		b = 1;				//置已访问过的标记
		while(i >= 0 && b)		//栈不为空，因当前栈顶结点的左子树已经遍历过
		{
			p = stack[i];
			if(p->rchild == q)		//无右孩子，或者已经访问过，排除右叶子结点，将右叶子结点直接出栈
			{
				i--;		//出栈
				j--;
				q = p;
			}
			else			//有右孩子且没有访问过
			{
				p = p->rchild;		//转为右孩子，此时可以变为右叶子结点
				code[j++] = 1;		//右孩子置位1
				b = 0;		//标记
			}
		}
	}while(i >= 0);
}

int main()
{
	BSTree_Link * root;
	int n;
	printf("Input number of keys\n");	//输入叶子结点的个数
	scanf("%d",&n);
	printf("Input keys : \n");		//输入n个叶子结点的权值
	root = CreateLinkList(n);		//根据权值生成一个升序的单链表
	printf("OutputList :\n");		//输出生成的单链表
	print(root);
	root = HuffTree(root);			//生成哈夫曼树
	printf("Inorder output HuffTree : \n");
	Inorder(root);
	printf("\n");
	printf("Preorder output HuffTree : \n");
	Preorder(root);
	printf("\n");
	printf("Output Code of HuffTree : \n");
	HuffCode(root);			//哈夫曼编码
	return 0;
}