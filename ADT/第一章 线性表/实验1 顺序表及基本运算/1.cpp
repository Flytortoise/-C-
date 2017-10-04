/* Ŀ�ģ��˽�����Ľṹ�ص㼰�йظ������˳���Ļ�������
   ���ݣ�����һ��˳�����˳�����г�ʼ�������롢ɾ���Ͳ�������
	2016��9��7�� 21:48:34	*/

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef struct
{
	int data[MAXSIZE];	//�洢˳����е�Ԫ��
	int len;			//˳���ı�
}SeqList;				//˳��������

SeqList * Init_SeqList()	//˳����ʼ��
{
	SeqList	*L;
	L = (SeqList*)malloc(sizeof(SeqList));
	L->len = 0;
	return L;
}

void CreatList(SeqList *L)	//����˳���
{
	int i;
	printf("Input length of List:");
	scanf("%d",&L->len);
	printf("Input elements of list:\n");
	for(i=1;i<L->len;i++)
		scanf("%d",&L->data[i]);
}

void Insert_SeqList(SeqList *L,int i,int x)		//��˳����в���Ԫ��
{
	int j;		
	if(L->len == MAXSIZE-1)	//����
		printf("The List is full!\n");
	else if(i<1 || i>L->len+1)		//����λ�÷Ƿ�
			printf("The position is invalid!\n");
		else
		{
			for(j=L->len;j>=i;j--)	//��an~ai˳�����һ��Ԫ��λ��
				L->data[j+1] = L->data[j];
			L->data[i] = x;
			L->len++;
		}
}

void Delete_SeqList(SeqList *L, int i)		//��˳�����ɾ��Ԫ��
{
	int j;
	if(L->len == 0)
		printf("The List is empt!\n");
	else if(i<1 || i>L->len)		//ɾ��λ�÷Ƿ�
			printf("The position is invalid!\n");
	else
	{
		for(j=i+1;j<L->len;j++)		//��ai+1~an˳��ǰ��һ��λ��ʵ�ֶ�ai��ɾ��
			L->data[j-1] = L->data[j];
		L->len--;
	}
}

int Location_SeqList(SeqList *L,int x)		//��˳����в���Ԫ�ز���
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
		printf("%4d",L->data[i]);	//����±�1��ʼ����
	printf("\n");
}

void main()
{
	SeqList *s;
	int i,x;
	s = Init_SeqList();	//��ʼ��
	printf("Creat List:\n");
	CreatList(s);		//����˳���
	printf("Output list:\n");
	print(s);			//�����������˳���
	printf("Input element and site of insert:\n");
	scanf("%d%d",&x,&i);	//����Ҫ�����Ԫ��x��λ��i
	Insert_SeqList(s,i,x);	//��Ԫ��X���뵽λ��i��
	printf("Output list:\n");
	print(s);				//���������˳���
	printf("Input element site of delete:\n");
	scanf("%d",&i);			//����ҪɾԪ�ص�λ��
	Delete_SeqList(s,i);	//ɾ��λ��i�ϵ�Ԫ��
	printf("Output list:\n");
	print(s);			//���ɾ�����˳���
	printf("Input element value if location:\n");
	scanf("%d",&x);		//����Ҫ���ҵ�Ԫ��x
	i = Location_SeqList(s,x);		//����
	printf("element %d site is %d\n",x,i);	//�����Ԫ�ص�λ��
}