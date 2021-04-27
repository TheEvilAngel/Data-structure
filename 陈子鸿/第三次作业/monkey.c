#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
 #include <string.h>
#include <stdlib.h>

struct list
{
	int x;
	int y;
	int len;
}lis[200];

struct node_point
{
	int x1;
	int y1;
	int x2;
	int y2;
}node[200];

int cmp(const void*p1, const void*p2 )
{
	struct node_point temp_1 = *(struct node_point*)p1;
	struct node_point temp_2 = *(struct node_point*)p2;
	return temp_1.x1 - temp_2.x1;
}
int num;
int main()
{
	scanf("%d",&num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d%d%d%d",&node[i].x1, &node[i].y1, &node[i].x2, &node[i].y2, );
	}
	qsort(node, num, sizeof(a[0]), cmp);
	for (int i = 0; i < num; i++)
	{
		printf("%d\n",node[i].x1);
	}

}