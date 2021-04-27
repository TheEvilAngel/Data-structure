#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct data {
	char sign;
	int lineN;
}data;
data stack[300];
int top, flag, string[2], lineNum=1, saveNum=0, re;
int type = 0, j;
char line[306], save[300];

void initStack() {
	top = -1;
}
int isEmpty() {
	return top == -1;
}
int isFull() {
	return top == 205 - 1;
}
void push(data s[], char elem) {
	if (isFull()) {
		flag = -1;
	}
	else {
		s[++top].sign = elem;
		s[top].lineN = lineNum;
	}
}
char pop(data s[]) {
	if (isEmpty()) {
		flag = -1;
	}
	else {
		return s[top--].lineN;
	}
	return 0;
}
int main()
{
	FILE* in;
	in = fopen("example.c", "r");
	if (in == NULL) {
		printf("can't open file\n");
		return 1;
	}
	char ch = '\0';
	int i = 0;
	initStack();
	while (fgets(line, 300, in) != NULL) {	
		for (i = 0; line[i] != '\0'; i++) {
			if (string[j] == 0) {
				if (line[i] == '*' && line[i + 1] == '/') {
					flag = 0;
				}
				if (line[i] == '/') {
					if (line[i + 1] == '/') {
						break;
					}
					if (line[i + 1] == '*') {
						flag = 1;
					}
				}
				if (flag == 1)
					continue;
			}
			if (line[i] == '\"') {
				j = 0;
				if (string[j + 1] != -1)
					string[j] = ~string[j];
				else
					j = 1;
			}
			if (line[i] == '\'') {
				j = 1;
				if (string[j - 1] != -1)
					string[j] = ~string[j];
				else
					j = 0;
			}
			if (string[j] == -1) {
				continue;
			}
				

			if (line[i] == '(') {
				save[saveNum++] = line[i];
				push(stack, line[i]);
			}
			if (line[i] == '{') {
				if (stack[top].sign == '(') {
					flag = 2;					//≥ˆœ÷≤ª∆•≈‰
					ch = '(';
					re = stack[top].lineN;
					break;
				}
				else {
					save[saveNum++] = line[i];
					push(stack, line[i]);
				}
			}
			if (line[i] == ')') {
				save[saveNum++] = line[i];
				if (isEmpty()) {
					flag = 2;
					ch = ')';
					re = lineNum;
					break;
				}
				if (stack[top].sign == '(') {
					re = pop(stack);
				}
				else {
					flag = 2;
					ch = ')';
					re = lineNum;
					break;
				}
			}
			if (line[i] == '}') {
				save[saveNum++] = line[i];
				if (isEmpty()) {
					flag = 2;
					ch = '}';
					re = lineNum;
					break;
				}
				if (stack[top].sign == '{') {
					re = pop(stack);
				}
				else {
					flag = 2;
					ch = '}';
					re = lineNum;
					break;
				}
			}
		}
		if (flag == 2) {
			printf("without maching \'%c\' at line %d", ch, re);
			break;
		}
		lineNum++;
	}
	if (!isEmpty() && flag!=2) {
		printf("without maching \'%c\' at line %d", stack[top].sign, stack[top].lineN);
	}
	else {
		if (flag != 2) {
			for (i = 0; i < saveNum; i++) {
				printf("%c", save[i]);
			}
		}
	}
	
	return 0;
}