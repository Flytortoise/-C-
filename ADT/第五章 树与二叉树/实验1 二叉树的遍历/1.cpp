#include <stdio.h>
#include <stdlib.h>

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

void Inorder(BSTree *p)
{
	if(p != NULL)
	{
		Inorder(p->lchild);
		printf("%3c",p->data);
		Inorder(p->rchild);
	}
}

void Postorder(BSTree *p)
{
	if(p != NULL)
	{
		Postorder(p->lchild);
		Postorder(p->rchild);
		printf("%3c",p->data);
	}
}

void Created(BSTree **p)
{
	char ch;
	scanf("%c",&ch);
	if(ch != '.')
	{
		*p = (BSTree *)malloc(sizeof(BSTree));
		(*p)->data = ch;
		Created(&(*p)->lchild);
		Created(&(*p)->rchild);
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
	Created(&root);
	printf("Preorder output :\n");
	Preorder(root);
	printf("\n");
	printf("Inorder output :\n");
	Inorder(root);
	printf("\n");
	printf("Postorder output:\n");
	Postorder(root);
	printf("\n");
}