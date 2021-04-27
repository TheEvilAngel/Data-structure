#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

struct list
{
	int x;
	int y;
	int len;
	int bx;
	int by;
}lis[200];

struct node_point
{
	int x1;
	int y1;
	int x2;
	int y2;
}node[200];

int cmp(const void* p1, const void* p2)
{
	struct node_point temp_1 = *(struct node_point*)p1;
	struct node_point temp_2 = *(struct node_point*)p2;
	return temp_1.x1 - temp_2.x1;
}

int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d%d%d%d", &node[i].x1, &node[i].y1, &node[i].x2, &node[i].y2);
	}
	qsort(node, num, sizeof(node[0]), cmp);
	int lon = 0, tx, ty;
	int flag;
	for (int i = 0; i < num; i++)
	{
		flag = 0;
		for (int j = 0; j < lon; j++)
		{
			if (node[i].x1 == lis[j].x && node[i].y1 == lis[j].y)
			{
				lis[j].x = node[i].x2;
				lis[j].y = node[i].y2;
				lis[j].len++;
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			lon++;
			lis[lon - 1].x = node[i].x2;
			lis[lon - 1].y = node[i].y2;
			lis[lon - 1].bx = node[i].x1;
			lis[lon - 1].by = node[i].y1;
			lis[lon - 1].len = 1;
		}
	}
	int max = -1;
	for (int i = 0; i < lon; i++)
	{
		if (lis[i].len > max)
		{
			max = lis[i].len;
			tx = lis[i].bx;
			ty = lis[i].by;
		}
	}
	printf("%d %d %d", max, tx, ty);

}