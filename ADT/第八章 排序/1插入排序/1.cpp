//2017年6月12日 20:10:21
/*
	插入排序，递增
*/

#include <stdio.h>

#define MAXSIZE 30

typedef struct 
{
	int key;
	char data;
}RecordType;

void D_Insert(RecordType R[], int n)	//n为长度
{
	int i,j;
	for(i = 2; i <= n ; i++)
	{
		if(R[i].key < R[i - 1].key)
		{
			R[0] = R[i];
			j = i - 1;
			while(R[j].key > R[0].key)
			{
				R[j+1] = R[j];
				j--;
			}
			R[j+1] = R[0];
		}
	}

}

int main()
{
	int i = 1, j, x;
	RecordType R[MAXSIZE];
	printf("Input data of list (-1 stop) : \n");
	scanf("%d",&x);
	while(x != -1)
	{
		R[i].key = x;
		scanf("%d",&x);
		i++;
	}

	printf("Output data in list :\n");
	for(j = 1; j < i; j++)
	{
		printf("%4d",R[j].key);
	}
	printf("\n");
	printf("Sort.....\n");
	D_Insert(R, i - 1);
	printf("Output data in list after Sort : \n");
	for(j = 1; j < i; j++)
	{
		printf("%4d",R[j].key);
	}
	printf("\n");
	return 0;
}