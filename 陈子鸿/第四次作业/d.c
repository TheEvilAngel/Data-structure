#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INSERT  1
#define DELET   2
#define UNDO    3
#define END    -1
struct data {
	int op;
	int pos;
	int n;
	char s[512];
}stack[1000];

char save[1000];
int op, pos, n;
char s[512];

int top=-1;
int isEmpty() {
	return top == -1;
}
int isFull() {
	return top == 1000 - 1;
}
void push(int op,int pos,int n,char s[]) {
	if (isFull()) {
		exit(1);
	}
	else {
		stack[++top].op = op;
		stack[top].pos = pos;
		stack[top].n = n;
		strcpy(stack[top].s, s);
	}
}
void pop() {
	if (isEmpty()) {
		op = -1;
	}
	else {
		op = stack[top].op;
		pos = stack[top].pos;
		n = stack[top].n;
		strcpy(s, stack[top--].s);
	}
}

void insert() {
	char tmp[512];
	memset(tmp, '\0', 512);
	strcpy(tmp, &save[pos]);
	save[pos] = '\0';
	strcat(save, s);
	strcat(save, tmp);
}

void delet() {
	int i;
	int sl = strlen(save);
	for (i = pos; i+n<sl; i++) {
		save[i] = save[i + n];
	}
	save[i] = '\0';
}

int main()
{
	int i,num;
	gets(save);
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d %d %s", &stack[i].op, &stack[i].pos, stack[i].s);
		stack[i].n = strlen(stack[i].s);
	}
	top = num - 1;
	while (1) {
		memset(s, '\0', 512);
		scanf("%d", &op);
		switch(op) {
			case INSERT:
				scanf("%d %s", &pos, s);
				n = strlen(s);
				push(op, pos, n, s);
				insert();	
				break;
			case DELET: 
				scanf("%d %d", &pos, &n);
				strncpy(s, &save[pos], n);
				push(op, pos, n, s);
				delet();	
				break;
			case UNDO: 
				pop();
				if (op == 1)
					delet();
				else if(op == 2)
					insert();
				break;
			case END:
				puts(save);
				return 0;
		}
	//	puts(save);
	}
	return 0;
}