#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct node
{
	int flag;
	union
	{
		char data;
		struct node *childlist;
	}val;
	struct node *next;
}lsnode, *plsnode;

plsnode Creatlist(char str[], plsnode head)
{
	plsnode pstack[SIZE], newnode , p = head;
	int top = -1, j = 0;

	while(str[j] != '\0')
	{
		if(str[j] == '(')
		{
			if(str[j + 1] != ')')
			{
				pstack[++top] = p;
				p->flag = 1;
				newnode = (lsnode *)malloc(sizeof(lsnode));
				p->val.childlist = newnode;
				p->next = NULL;
				p = p->val.childlist;
			}
			else
			{
				p->flag = 1;
				p->val.childlist = NULL;
				p->next = NULL;
				j++;
			}
		}
		else
		{
			if(str[j] == ',')
			{
				newnode = (lsnode *)malloc(sizeof(lsnode));

				p->next = newnode;
				p = p->next;
			}
			else
			{
				if(str[j] == ')')
				{
					p = pstack[top--];
					if(top == -1)
					{
						goto ll;
					}
				}
				else
				{
					p->flag = 0;
					p->val.data = str[j];
					p->next = NULL;
				}
			}
		}
		j++;
	}

ll: return head;
}

int CBLength(plsnode h)
{
	int n = 0;
	h = h->val.childlist;
	while(h != NULL)
	{
		n++;
		h = h->next;
	}

	return n;
}

int CBDepth(plsnode h)
{
	int max = 0, dep;
	if(h->flag == 0)
	{
		return 0;
	}

	h = h->val.childlist;
	if(h == NULL)
	{
		return 1;
	}

	while(h != NULL)
	{
		if(h->flag == 1)
		{
			dep = CBDepth(h);
			if(dep > max)
			{
				max = dep;
			}
		}

		h = h->next;
	}

	return max + 1;
}

void DispcB(plsnode h)
{
	if(h != NULL)
	{
		if(h->flag == 1)
		{
			printf("(");
			if(h->val.childlist == NULL)
			{
				printf(" ");
			}
			else
			{
				DispcB(h->val.childlist);
			}
		}
		else
		{
			printf("%c",h->val.data);
		}

		if(h->flag == 1)
		{
			printf(")");
		}

		if(h->next != NULL)
		{
			printf(",");
			DispcB(h->next);
		}
	}
}

void main()
{
	plsnode head = (lsnode *)malloc(sizeof(lsnode));
	char str[SIZE];
	printf("Please input List :\n");
	gets(str);
	head = Creatlist(str,head);
	DispcB(head);
	printf("\n");
	printf("Length of lists is %d\n",CBLength(head));
	printf("Depth of lists is %d\n", CBDepth(head));
}