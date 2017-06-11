//2017年6月11日 12:24:47
/*
	test: 4
		  1 3 5 7
	说明：数组形式，建立哈夫曼树


*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 40
#define MAXBIT 10	//哈夫曼编码的最大长度

typedef struct 
{
	int weight,parent,lchild,rchild;
}HNode;			//哈夫曼树结点类型

typedef struct 
{
	int weight;		//存储叶子结点权重
	int bit[MAXBIT];	//存储该叶子结点的哈夫曼编码
	int start;		//指示数组bit中哈夫曼编码的开始位置
}HCode;			//哈夫曼编码类型
	
void HuffTree(HNode Huff[], int n)		//生成哈夫曼树，n为叶子结点个数
{
	int i,j,m1,m2,x1,x2;
	for (i = 0; i < 2 *n - 1; ++i)		//初始化
	{
		Huff[i].weight = 0;
		Huff[i].parent = -1;
		Huff[i].lchild = -1;
		Huff[i].rchild = -1;
	}

	printf("Input 1 ~ n value of leaf : \n");
	for ( i = 0; i < n; ++i)		//输入n个叶子结点的权值
	{
		scanf("%d",&Huff[i].weight);
	}

	for(i = 0; i < n - 1; i++)	//构造哈夫曼树并生成该树的n-1个分支结点
	{
		m1 = m2 = 32767;
		x1 = x2 = 0;

		for(j = 0; j < n + i ; j++)		//选取最小和次小两个权值结点并将其序号送x1和x2
		{
			if(Huff[j].parent == -1 && Huff[j].weight < m1)
			{
				m2 = m1;
				x2 = x1;
				m1 = Huff[j].weight;
				x1 = j;
			}
			else if(Huff[j].parent == -1 && Huff[j].weight < m2)
			{
				m2 = Huff[j].weight;
				x2 = j;
			}
		}
		//将找出的两棵子树合并成为一棵
		Huff[x1].parent = n + i;		//两棵子树的双亲结点序号为n+i
		Huff[x2].parent = n + i;
		Huff[n + i].weight = Huff[x1].weight + Huff[x2].weight;
		Huff[n + i].lchild = x1;
		Huff[n + i].rchild = x2;
	}

	printf("Huff weight lchild rchild prent\n");
	for(i = 0; i < 2 * n - 1; i++)		//输出哈夫曼树信息
	{
		printf("%3d %5d %10d %10d %10d\n",i,Huff[i].weight,Huff[i].lchild,Huff[i].rchild,Huff[i].parent);
	}
}

void HUffmanCode()		//生成哈夫曼编码
{
	HNode HuffNode[MAXSIZE];	//MAXSIZE为二叉树所有结点的最大个数，MAXSIZE/2为叶子结点的最大个数
	HCode HuffCode[MAXSIZE/2],cd;
	int i,j,c,p,n;
	printf("Input numbers of leadf:\n");	//n为叶子结点的个数
	scanf("%d",&n);
	HuffTree(HuffNode,n);			//建立哈夫曼树
	for(i = 0; i < n; i++)			//求每个结点的哈夫曼编码
	{
		HuffCode[i].weight = HuffNode[i].weight;		//保存叶子结点的权值
		cd.start = MAXBIT - 1;		//存放分支编码从数组cd.bit最后一个元素的位置开始向前
		c = i;						//c为叶子结点在数组HuffNode中的序号
		p = HuffNode[c].parent;
		while(p != -1)				//从叶子结点开始沿双亲链直到根节点，根节点的双亲值为-1
		{
			if(HuffNode[p].lchild == c)	//双亲的左孩子序号为c
			{
				cd.bit[cd.start] = 0;	//该分支编码为0
			}
			else
			{
				cd.bit[cd.start] = 1;	//该分支编码为1
			}

			cd.start--;					//向前移动一个位置准备存放下一个分支编码
			c = p;						//c移至其双亲结点序号
			p = HuffNode[c].parent;		//p再定位于c的双亲结点序号
		}

		for(j = cd.start + 1; j < MAXBIT; j++)		//保存该叶子结点字符的哈夫曼编码
		{
			HuffCode[i].bit[j] = cd.bit[j];
		}
		HuffCode[i].start = cd.start;		//保存该编码在数组bit中的起始位置
	}

	printf("HuffCode weight bit \n");		//输出数组HuffCode的有关信息
	for(i = 0; i< n; i++)					//输出各叶子结点对应的哈夫曼编码
	{
		printf("%5d%8d   ",i,HuffCode[i].weight );
		for(j = HuffCode[i].start + 1; j < MAXBIT; j++)
		{
			printf("%d",HuffCode[i].bit[j]);
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	HUffmanCode();	//生成哈夫曼编码
	return 0;
}