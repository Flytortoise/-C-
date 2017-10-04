/* 目的：了解混虚标的结构特点及有关概念，掌握顺序表的基本运算
   内容：创建一个顺序表，对顺序表进行初始化、插入、删除和查找运算
	2016年9月7日 21:48:34	*/

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef struct
{
	int data[MAXSIZE];	//存储顺序表中的元素
	int len;			//顺序表的表长
}SeqList;				//顺序表的类型

SeqList * Init_SeqList()	//顺序表初始化
{
	SeqList	*L;
	L = (SeqList*)malloc(sizeof(SeqList));
	L->len = 0;
	return L;
}

void CreatList(SeqList *L)	//创建顺序表
{
	int i;
	printf("Input length of List:");
	scanf("%d",&L->len);
	printf("Input elements of list:\n");
	for(i=1;i<L->len;i++)
		scanf("%d",&L->data[i]);
}

void Insert_SeqList(SeqList *L,int i,int x)		//在顺序表中插入元素
{
	int j;		
	if(L->len == MAXSIZE-1)	//表满
		printf("The List is full!\n");
	else if(i<1 || i>L->len+1)		//插入位置非法
			printf("The position is invalid!\n");
		else
		{
			for(j=L->len;j>=i;j--)	//把an~ai顺序后移一个元素位置
				L->data[j+1] = L->data[j];
			L->data[i] = x;
			L->len++;
		}
}

void Delete_SeqList(SeqList *L, int i)		//在顺序表中删除元素
{
	int j;
	if(L->len == 0)
		printf("The List is empt!\n");
	else if(i<1 || i>L->len)		//删除位置非法
			printf("The position is invalid!\n");
	else
	{
		for(j=i+1;j<L->len;j++)		//将ai+1~an顺序前移一个位置实现对ai的删除
			L->data[j-1] = L->data[j];
		L->len--;
	}
}

int Location_SeqList(SeqList *L,int x)		//在顺序表中查找元素查找
{
	int i=1;
	while (i < L->len && L->data[i] != x)
		i++;
	if(L->data[i] == x)
		return i;
	else 
		return 0;
}

void print(SeqList *L)
{
	int i;
	for(i=1;i<L->len;i++)
		printf("%4d",L->data[i]);	//表从下标1开始建立
	printf("\n");
}

void main()
{
	SeqList *s;
	int i,x;
	s = Init_SeqList();	//初始化
	printf("Creat List:\n");
	CreatList(s);		//建立顺序表
	printf("Output list:\n");
	print(s);			//输出所创建的顺序表
	printf("Input element and site of insert:\n");
	scanf("%d%d",&x,&i);	//输入要插入的元素x和位置i
	Insert_SeqList(s,i,x);	//将元素X插入到位置i上
	printf("Output list:\n");
	print(s);				//输出插入后的顺序表
	printf("Input element site of delete:\n");
	scanf("%d",&i);			//输入要删元素的位置
	Delete_SeqList(s,i);	//删除位置i上的元素
	printf("Output list:\n");
	print(s);			//输出删除后的顺序表
	printf("Input element value if location:\n");
	scanf("%d",&x);		//输入要查找的元素x
	i = Location_SeqList(s,x);		//查找
	printf("element %d site is %d\n",x,i);	//输出该元素的位置
}