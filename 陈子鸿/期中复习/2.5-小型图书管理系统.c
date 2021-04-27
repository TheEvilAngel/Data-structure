#include <stdio.h>
#include <string.h>
#include <stdlib.h>
enum{OUT,ADD,SEA,DEL};
typedef struct data {
	char name[100];
	char ath[100];
	char pub[100];
	char data[100];
}data;
data book[505];
char str[100];

int cmp(const void* p1, const void* p2) {
	data* a = (data*)p1;
	data* b = (data*)p2;
	return strcmp(a->name, b->name);
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

int main()
{
	FILE* in, * out;
	in = fopen("books.txt", "r");
	out = fopen("ordered.txt", "w");
	if (in == NULL) {
		printf("can't open file\n");
		return 1;
	}
	if (out == NULL) {
		printf("can't open file\n");
		return 1;
	}

	int i = 0, op, sum, place, j = 0;
	for (i = 0; (fscanf(in, "%s%s%s%s", book[i].name, book[i].ath, book[i].pub, book[i].data)) != EOF; i++);
	sum = i;
	qsort(book, sum, sizeof(book[0]), cmp);
	while (1) {
		scanf("%d", &op);
		switch (op) {
			case OUT: 
				for (i = 0; i < sum; i++) {
					fprintf(out, "%-50s%-20s%-30s%-10s\n", book[i].name, book[i].ath, book[i].pub, book[i].data);
				}
				return 0;
			case ADD:
				scanf("%s%s%s%s", book[sum].name, book[sum].ath, book[sum].pub, book[sum].data);
				sum++;
				qsort(book, sum, sizeof(book[0]), cmp);
				break;
			case SEA:
				scanf("%s", str);
				for (i = 0; i < sum; i++) {
					place = KMPindex(book[i].name, str);
					if (place != -1) {
						printf("%-50s%-20s%-30s%-10s\n", book[i].name, book[i].ath, book[i].pub, book[i].data);
					}
				}
				break;
			case DEL:
				scanf("%s", str);
				for (i = 0; i < sum; i++) {
					place = KMPindex(book[i].name, str);
					if (place != -1) {
						for (j = i; j < sum; j++) {
							book[j] = book[j + 1];
						}
						sum--;	
						i--;
					}
				}
				break;
		}
		puts("");
		for (i = 0; i < sum; i++) {
			printf("%-50s%-20s%-30s%-10s\n", book[i].name, book[i].ath, book[i].pub, book[i].data);
		}
	}
	return 0;
}