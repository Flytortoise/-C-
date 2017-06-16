//2017年6月16日 23:15:30
//希尔排序	????

#include <stdio.h>

#define MAXSIZE 30

typedef struct 
{
	int key;
	char data;
}RecordType;

void ShellInsert(RecordType R[], int n, int d)
{
	int i,j;
	for(i = d + 1; i <= n; i++)
	{
		if(R[i].key < R[i-d].key)
		{
			R[0] = R[i];
			for(j = i - d; j > 0 && R[0].key < R[j].key ; j -= d)
			{
				R[j+d] = R[j];
			}
			R[j+d] = R[0];
		}
	}
} 

void ShellSort(RecordType R[], int n)
{
	int d[10],t,k;
	printf("Please input increat number : \n");
	scanf("%d",&t);
	printf("Please input big to small number:\n");	//从大到小输入增长因子
	for(k = 0; k < t; k++)
	{
		scanf("%d",d+k);
	}

	for(k = 0; k < t; k++)
	{
		ShellInsert(R,n,d[k]);
	}
}

int main(int argc, char const *argv[])
{
	int i = 1, j,x;
	RecordType R[MAXSIZE] = {39,80,76,48,13,29,50,78,30,11,100,7,48,86};
	ShellSort(R,14);
	for(i = 1; i < 15; i++)
	{
		printf("%d ", R[i]);
	}
	printf("\n");

	return 0;
}