//2017年6月16日 22:58:05
//分块查找，先找到合适的范围，再遍历顺序查找

#include <stdio.h>

#define MAXSIZE 30

typedef struct 
{
	int key;
	char data;
}SeqList;

typedef struct 
{
	int key;	//用于存放块内最大关键字的值
	int link;	//用于指向块的起始位置
}IdxType;		//索引表元素类型

int IdxSearch(IdxType I[], int m, SeqList R[], int k)
{
	int low = 0,high = m-1,mid,i,j;
	while(low <= high)
	{
		mid = (low+high)/2;
		if(I[mid].key >= k)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

//	if(low < m)	//没啥用，注释掉也能用
	{
		i = I[low + 1].link - 1;
		j = I[low].link;
		while(R[i].key != k && i >= j)
		{
			i--;
		}

		if(i >= j)
		{
			return i;
		}
	}

	return -1;
}


int main(int argc, char const *argv[])
{
	int i;
	IdxType I[4] = {18,0,38,4,71,9,90,11};
	SeqList R[16] = {18,' ',6,' ',10,' ',11,' ',21,' ',31,' ',20,' ',38,' ',19,' ',60,' ',71,' ',75,' ',88,' ',73,' ',79,' ',90,' '};

	i = IdxSearch(I,4,R,38);
	if(i > -1)
	{
		printf("Site of 38 is %d\n",i );		
	}	
	else
	{
		printf("No find 38\n");
	}

	i = IdxSearch(I,4,R,26);
	if(i > -1)
	{
		printf("Site of 26 is %d\n",i );		
	}	
	else
	{
		printf("No find 26\n");
	}
	return 0;
}