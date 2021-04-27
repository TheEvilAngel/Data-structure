#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	char inich;
	struct node* next;
};
typedef struct node Node;
typedef struct node* Nodeptr;
Nodeptr keyList, p, q;
int vis[150];
char password[150];
char tmp[40];
char textch;
void creatList();

int main()
{
	creatList();
	FILE* in, * out;
	in = fopen("in.txt", "r");
	out = fopen("in_crpyt.txt", "w");
	if (in == NULL) {
		printf("can't open file\n");
		return 1;
	}
	if (out == NULL) {
		printf("can't open file\n");
		return 1;
	}
	while ((textch = fgetc(in)) != EOF) {
		if (textch <= 126 && textch >= 32) {
			fprintf(out, "%c", password[(int)textch]);
		}
		else {
			fprintf(out, "%c", textch);
		}
	}
	return 0;
}

void creatList() {
	int i, move=0;
	char headch;
	Nodeptr before = NULL;
	gets(tmp);
	for (i = 0; tmp[i] != '\0'; i++) {
		if (vis[(int)tmp[i]] == 1)
			continue;
		vis[(int)tmp[i]] = 1;
		q = (Nodeptr)malloc(sizeof(Node));
		q->inich = tmp[i];
		q->next = NULL;
		if (keyList == NULL) {
			keyList = p = q;
		}
		else {
			p->next = q;
			p = q;
		}
	}
	for (i = 32; i <= 126; i++) {
		if (vis[i] == 1)
			continue;
		vis[i] = 1;
		q = (Nodeptr)malloc(sizeof(Node));
		q->inich = i;
		q->next = NULL;
		p->next = q;
		p = q;
	}
	/*for (p = keyList; p->next != keyList; p = p->next) {
		printf("%c", p->inich);
	}
	puts("");*/
	
	p->next = keyList;
	before = p;
	p = keyList;
	headch = p->inich;
	while (p->next != p) {
		move = (int)p->inich;
		before->next = p->next;
		free(p);
		p = before->next;
		for (i = 1; i < move; i++) {
			before = p;
			p = p->next;
		}
		password[move] = p->inich;
	}
	password[(int)p->inich] = headch;
	/*for (i = 32; i <= 126; i++) {
		printf("%c", password[i]);
	}*/
}