#include <stdio.h>
#include <string.h>
#include <stdlib.h>
enum track{A,B,C};

typedef struct data {
	int num;
	char dest[25];
	int dist;
}train;

train stack[3][100];
train desti[100];
train tmp;
int top[3] = { -1,-1,-1 };
int countPush;
int KMPindex(char S[], char T[]);
void getnext(char T[], int next[]);

int cmp(const void* p1, const void* p2) {
	train* a = (train*)p1;
	train* b = (train*)p2;
	return b->dist - a->dist;
}

void push(train elem, int track) {
	top[track]++;
	stack[track][top[track]].dist = elem.dist;
	stack[track][top[track]].num = elem.num;
}
void pop(int track) {
	tmp.dist = stack[track][top[track]].dist;
	tmp.num = stack[track][top[track]].num;
	top[track]--;
}
int main()
{
	int i, j, n_dest, n_train, now_dest=0, flag = 0, finish = 0, move = 0;
	scanf("%d", &n_dest);
	for (i = 0; i < n_dest; i++) {
		scanf("%s %d", desti[i].dest, &desti[i].dist);
	}
	qsort(desti, n_dest, sizeof(desti[0]), cmp);

	scanf("%d", &n_train);
	for (i = 0; i < n_train; i++) {
		scanf("%d %s", &tmp.num, tmp.dest);
		for (j = 0; KMPindex(tmp.dest, desti[j].dest) == -1; j++);
		tmp.dist = desti[j].dist;
		push(tmp, A);
	}
	for (i = 0; i < n_train; i++) {
		pop(A);
		push(tmp, B);
	}

	while (top[B] != -1) {
		for (flag = top[B];; flag--) {
			if (stack[B][flag].dist == desti[now_dest].dist) {
				if (flag == top[B])
					finish = 1;
				break;
			}
			if (flag == 0) {
				now_dest++;
				flag = top[B] + 1;
			}
		}
		move = top[B] - flag + 1;
		for (i = 0; i < move; i++) {
			pop(B);
			push(tmp, A);
			countPush++;
		}
		if (finish == 1) {
			finish = 0;
			continue;
		}
		else {
			pop(A);
			push(tmp, C);
			for (i = 0; i < move - 1; i++) {
				pop(A);
				push(tmp, B);
			}
			pop(C);
			push(tmp, A);
			countPush++;
		}
	}
	for (i = 0; i < n_train; i++) {
		printf("%04d ", stack[A][i].num);
	}
	printf("\n");
	printf("%d", countPush);
	return 0;
}

void getnext(char T[], int next[])
{
	int i = 0, j = -1;
	next[0] = -1;
	while (T[i] != '\0') {
		if (j == -1 || T[i] == T[j]) { //i为后缀位置；j为前缀位置
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j]; //若字符不同，则j值回溯
	}
}

int KMPindex(char S[], char T[])
{
	int i = 0, j = 0, * next;

	next = (int*)malloc(sizeof(int) * (strlen(T) + 1));
	getnext(T, next);
	while (S[i] != '\0' && T[j] != '\0') {
		if (S[i] == T[j]) {
			i++;
			j++;
		}
		else
			(j == 0) ? i++ : (j = next[j]); 		//j回退到相应位置开始匹配，i值不变
	}
	free(next);
	if (T[j] == '\0') 	//匹配成功，返回匹配位置
		return  i - j;
	else
		return -1;
}
