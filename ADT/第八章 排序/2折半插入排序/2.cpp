//2017年6月14日 22:36:35
//折半插入排序

#include <stdio.h>

#define MAXSIZE 30

typedef struct 
{
	int key;
	char data;
}RecordType;

void B_InsertSort(RecordType R[], int len)
{
	int i,j,low,high,mid;
	for (i = 2; i < len; i++)
	{
		R[0] = R[i];
		low = 1; 
		high = i - 1;
		while(low <= high)
		{
			mid = (low + high) / 2;
			if(R[0].key > R[mid].key)
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}

		for(j = i - 1; j >= high+1;j--)	//high+1为插入位置，剩下的后移
		{
			R[j+1] = R[j];
		}
		R[high+1] = R[0];
		/* code */
	}
}

int main(int argc, char const *argv[])
{
	int i = 1,j,x;
	RecordType R[MAXSIZE];
	printf("Input data of list (-1 stop):\n");

	scanf("%d",&x);
	while(x != -1)
	{
		R[i].key = x;
		scanf("%d",&x);
		i++;
	}

	printf("Output data in list\n");
	for(j = 1; j < i; j++)
	{
		printf("%d ", R[j].key);
	}
	printf("\nSort\n");

	B_InsertSort(R,i);
	printf("Output data in list\n");
	for(j = 1; j < i; j++)
	{
		printf("%d ", R[j].key);
	}
	printf("\n");
	return 0;
}