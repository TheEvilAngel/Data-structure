#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data {
	int xhead, yhead;
	int xtail, ytail;
	int len;
}DATA;
DATA line[105];
int n;

int deleteElem(DATA list[], int i) {
	int k;
	if (n == 0 || i<0 || i>n - 1) {
		return -1;
	}
	for (k = i + 1; k < n; k++) {
		list[k - 1] = list[k];
	}
	n--;
	return 1;
}

int cmp(const void* p1, const void* p2) {
	return (*(DATA*)p1).xhead - (*(DATA*)p2).xhead;
}
int main()
{
	int i, j, max=0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d%d%d", &line[i].xhead, &line[i].yhead, &line[i].xtail, &line[i].ytail);
		line[i].len = 1;
	}
	qsort(line, n, sizeof(line[0]), cmp);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (line[i].xtail == line[j].xhead && line[i].ytail == line[j].yhead) {
				line[i].xtail = line[j].xtail;
				line[i].ytail = line[j].ytail;
				line[i].len += line[j].len;
				deleteElem(line, j);
				j--;
			}
		}
	}
	for (i = 1; i < n; i++) {
		if (line[i].len > line[max].len) {
			max = i;
		}
	}
	printf("%d %d %d", line[max].len, line[max].xhead, line[max].yhead);
	return 0;
}