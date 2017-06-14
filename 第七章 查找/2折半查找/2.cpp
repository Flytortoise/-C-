//2017年6月14日 22:28:31
//折半查找

#include <stdio.h>

#define MAXSIZE 30

typedef struct 
{
	int key;
	char data;
}SeqList;

int BinSearch(SeqList R[], int n, int k)
{
	int low = 0,  high = n - 1, mid;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if( R[mid].key == k)
		{
			return mid;
		}
		else if(R[mid].key < k)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	return -1;
}

int main(int argc, char const *argv[])
{

	int i;
	SeqList R[MAXSIZE];
	for (i = 0; i < 13; ++i)
	{
		R[i].key = i * 2;
		/* code */
	}

	printf("Search 20 in Seqlist\n");

	i = BinSearch(R, 12, 20);
	if(i != -1)
	{
		printf("Position of 20 in Seqlist is %d\n",i);
	}
	else
	{
		printf("No found 20 in Seqlist\n");
	}

	printf("Search 21 in Seqlist\n");

	i = BinSearch(R, 12, 21);
	if(i != -1)
	{
		printf("Position of 21 in Seqlist is %d\n",i);
	}
	else
	{
		printf("No found 21 in Seqlist\n");
	}
	
	return 0;
}
