#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct DATA {
	char name[30];
	char tel[20];
	int id;
	int flag;
}data;
data stu[1000];
int cmp(const void* p1, const void* p2) {
	data* a = (data*)p1;
	data* b = (data*)p2;
	int prior = strcmp(a->name, b->name);
	if (prior != 0)
		return prior;
	else {
		a->flag = 1;
		b->flag = 1;
		return a->id - b->id;
	}		
}
int cmp1(const void* p1, const void* p2) {
	data* a = (data*)p1;
	data* b = (data*)p2;
	return strcmp(a->tel, b->tel);
}
int cmp2(const void* p1, const void* p2) {
	data* a = (data*)p1;
	data* b = (data*)p2;
	int prior = strcmp(a->name, b->name);
	if (prior != 0)
		return prior;
	else {
		return a->id - b->id;
	}
}
int main()
{
	int i, j, k, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s %s", &stu[i].name, &stu[i].tel);
		stu[i].id = i;
	}
	qsort(stu, n, sizeof(stu[0]), cmp);
	for (i = 0; i < n; i++) {
		if (!stu[i].flag) {
			printf("%s %s\n", stu[i].name, stu[i].tel);
		}
		else {
			for (k = i + 1; stu[k].flag != 0; k++);
			qsort(&stu[i], k - i, sizeof(stu[0]), cmp1);		//相同的排序到一起了
			for (j = i + 1; stu[j].flag != 0; j++) {
				if (strcmp(stu[j - 1].tel, stu[j].tel) == 0)
					stu[j].flag = -1;
			}
			qsort(&stu[i], k - i, sizeof(stu[0]), cmp2);		//按照原来的排序回去
			k = 0;
			for (j = i; stu[j].flag != 0; j++) {
				if (k == 0) {
					printf("%s %s\n", stu[j].name, stu[j].tel);
					k++;
				}
				else{
					if (stu[j].flag == -1)
						continue;
					else {
						printf("%s_%d %s\n", stu[j].name, k, stu[j].tel);
						k++;
					}
				}	
			}
			i = j - 1;
		}
		//printf("%s %s %d %d\n", stu[i].name, stu[i].tel, stu[i].id, stu[i].flag);
	}
	return 0;
}