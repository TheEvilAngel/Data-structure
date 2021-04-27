#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define EXIT   0
#define TYPEIN 1
#define SEARCH 2
#define DELETE 3

typedef struct data {
	char author[25];
	char name[55];
	char pub[35];
	char date[15];
}data;
data book[505];
FILE* in, * out;
int i, j, oper, sum;
char str[55];

int cmp(const void* p1, const void* p2) {
	return strcmp((*(data*)p1).name, (*(data*)p2).name);
}

int main()
{
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
	while (fscanf(in, "%s", book[i].name) != EOF) {
		fscanf(in, "%s", book[i].author);
		fscanf(in, "%s", book[i].pub);
		fscanf(in, "%s", book[i].date);
		i++;
	}
	sum = i;
	qsort(book, sum, sizeof(book[0]), cmp);

	while (1) {
		scanf("%d", &oper);
		if (oper == EXIT) {
			for (i = 0; i < sum; i++)
				fprintf(out, "%-50s%-20s%-30s%-10s\n", book[i].name, book[i].author, book[i].pub, book[i].date);
			break;
		}
		if (oper == TYPEIN) {
			scanf("%s %s %s %s", book[sum].name,book[sum].author,book[sum].pub,book[sum].date);
			sum++;
			qsort(book, sum, sizeof(book[0]), cmp);
		}
		if (oper == SEARCH) {
			scanf("%s", str);
			for (i = 0; i < sum; i++) {
				if (strstr(book[i].name, str) != NULL) {
					printf("%-50s%-20s%-30s%-10s\n", book[i].name, book[i].author, book[i].pub, book[i].date);
				}
			}
		}
		if (oper == DELETE) {
			scanf("%s", str);
			for (i = 0; i < sum; i++) {
				if (strstr(book[i].name, str) != NULL) {
					for (j = i; j < sum; j++) {
						book[j] = book[j + 1];
					}
					sum--;
					i--;
				}
			}
		}
	}
}