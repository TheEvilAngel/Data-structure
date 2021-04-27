#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
	char s[100];
	int count;
	struct node* next;
};
typedef struct node Node;
typedef struct node* Nodeptr;
Nodeptr p, q, f, before;

FILE* in;
char word[100],reword[100];

int is_alpha(char ch) {
	if (ch <= 'z' && ch >= 'a')
		return 1;
	else if (ch <= 'Z' && ch >= 'A')
		return 2;
	else
		return 0;
}
int searchword() {
	before = NULL;
	for (p = f; p!=NULL; before=p, p = p->next) {
		if (strcmp(q->s, p->s) < 0) {
			break;
		}
		else if (strcmp(q->s, p->s) == 0)
			return 1;
	}
	return 0;
}
int insertword() {
	if (p == f) {
		q->next = f;
		f = q;
	}
	else {
		q->next = p;
		before->next = q;
	}
	return 0;
}
int main()
{
	in = fopen("article.txt", "r");
	if (in == NULL) {
		printf("can't open file\n");
		return 1;
	}
	
	while (fscanf(in, "%s", word) != EOF) {
		int i = 0,j = 0;
		while (word[i] != '\0') {
			if (is_alpha(word[i]) != 0) {
				for (j = 0; is_alpha(word[i+j])!=0; j++) {
					reword[j] = tolower(word[i + j]);
				}
				reword[j] = '\0';
				i += j;
				q = (Nodeptr)malloc(sizeof(Node));
				if (q) {
					strcpy(q->s, reword);
					q->count = 1;
					q->next = NULL;
				}
				if (f == NULL) {
					p = f = q;
				}
				else {
					if (searchword() == 1) {
						p->count++;
						free(q);
					}
					else {
						insertword();
					}
				}
			}
			else {
				i++;
			}
		}
	}

	for (p = f; p!=NULL; p = p->next) {
		printf("%s %d\n", p->s, p->count);
	}
	return 0;
}