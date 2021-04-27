#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data {
	int xhead, yhead;
	int xtail, ytail;
	int len;
}DATA;
DATA line[105];
DATA tmp;
int num;

int searchElem(DATA list[], int n, DATA item) {
	int low = 0, high = n - 1, mid;
	while (low <= high) {
		mid = (high + low) / 2;
		if (item.xhead < list[mid].xhead)
			high = mid - 1;
		else if (item.xhead > list[mid].xhead)
			low = mid + 1;
		else
			return (mid);
	}
	return low;
}

int deleteElem(DATA list[], int i) {
	int k;
	if (num == 0 || i<0 || i>num - 1) {
		return -1;
	}
	for (k = i + 1; k < num; k++) {
		list[k - 1] = list[k];
	}
	num--;
	return 1;
}

int insertElem(DATA list[], int i, DATA item) {
	int k;
	if (num == 105 || i<0 || i>num) {
		return -1;
	}
	for (k = num - 1; k >= i; k--) {
		list[k + 1] = list[k];
	}
	list[i] = item;
	num++;
	return 1;
}

int main()
{
	int i=0, j, n, flag=0, point=0, max=0;
	scanf("%d", &n);
	while(n--) {
		scanf("%d%d%d%d", &tmp.xhead, &tmp.yhead, &tmp.xtail, &tmp.ytail);
		for (i = 0; i < num; i++) {
			if (tmp.xhead == line[i].xtail && tmp.yhead == line[i].ytail) {
				flag = 1;
				line[i].xtail = tmp.xtail;
				line[i].ytail = tmp.ytail;
				line[i].len++;
				break;
			}
		}
		if (flag == 0) {
			point = searchElem(line, num, tmp);
			insertElem(line, point, tmp);
			line[point].len = 1;
		}
		flag = 0;
	}

	for (i = 0; i < num - 1; i++) {
		for (j = 0; j < num - 1; j++) {
			if (line[i].xtail == line[j].xhead && line[i].ytail == line[j].yhead) {
				line[i].xtail = line[j].xtail;
				line[i].ytail = line[j].ytail;
				line[i].len += line[j].len;
				deleteElem(line, j);
				j--;
			}
		}
	}
	for (i = 1; i < num; i++) {
		if (line[i].len > line[max].len) {
			max = i;
		}
	}
	printf("%d %d %d", line[max].len, line[max].xhead, line[max].yhead);
	return 0;
}