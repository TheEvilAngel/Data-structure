#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct data {
	char s[50];
	int cnt;
};
struct data save[10000000];
char word[50],reword[50];
FILE* IN;
int cmp(const void* p1, const void* p2) {
	return strcmp((*(struct data*)p1).s, (*(struct data*)p2).s);
}
int is_alpha(char ch) {
	if (ch <= 'z' && ch >= 'a')
		return 1;
	else if (ch <= 'Z' && ch >= 'A')
		return 2;
	else
		return 0;
}
int main()
{
	int i=0,j=0,k=0;
	IN = fopen("article.txt", "r");
	if (IN == NULL) {
		printf("can't open file\n");
		return 1;
	}
	while (fscanf(IN, "%s", word) != EOF) {
		i = 0;
		while (word[i] != '\0') {
			if (is_alpha(word[i]) != 0) {
				for (j = 0; is_alpha(word[i + j]) != 0; j++) {
					reword[j] = tolower(word[i + j]);
				}
				reword[j] = '\0';
				i += j;
				save[k].cnt = 1;
				strcpy(save[k++].s, reword);
			}
			else {
				i++;
			}
		}
	}
	qsort(save, k, sizeof(save[0]), cmp);

	for (i = 0; i < k; i++) {
		if (strcmp(save[i].s, save[i + 1].s) == 0 && i!=k-1) {
			save[i + 1].cnt += save[i].cnt;
		}
		else {
			printf("%s %d\n", save[i].s, save[i].cnt);
		}
	}
	return 0;
}