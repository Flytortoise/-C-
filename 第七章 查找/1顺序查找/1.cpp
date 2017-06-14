//2017年6月12日 19:44:51
/*	顺序查找
*/

#include <stdio.h>

#define MAXSIZE 30

typedef struct 
{
	int key;	//
	char data;	//其他数据
}SeqList;

int SeqSearch(SeqList R[], int n, int k)	//n为长度，k为要查找的值
{
	int i = n;
	R[0].key = k;
	while(R[i].key != k)
		i--;
	return i;
}

int main(int argc, char const *argv[])
{
	int i = 1, j, k, x;
	SeqList R[MAXSIZE];
	printf("Input data of list (-1 stop) : \n");
	scanf("%d",&x);
	while(x != -1)
	{
		R[i].key = x;
		scanf("%d",&x);
		i++;
	}
	printf("Input data of list (-1 stop) : \n");
	for (j = 1; j < i; j++)
	{
		printf("%4d", R[j].key);
	}
	printf("\n");
	printf("Search data in SeqList, Input data(-1 stop) : \n");

	scanf("%d",&x);
	while(x != -1)
	{
		k = SeqSearch(R,i,x);
		if(k > 0)
		{
			printf("Position of %d in SeqList is %d\n",x,k);
		}
		else
		{
			printf("No found %d in SeqList !\n", x);
		}
		printf("Search data in SeqList, Input data(-1 stop) : \n");

		scanf("%d",&x);
	}
	return 0;
}