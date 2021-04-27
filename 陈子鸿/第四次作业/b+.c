#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct data {
	char sign;
	int lineN;
}data;
data stack[300];
int top, flag, string[2], lineNum = 1, saveNum = 0, re;
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
	char word;
	while (1) {
		word = fgetc(in);
		if (word == EOF) {
			break;
		}
		if (word == '\n') {
			lineNum++;
		}
		if (word == '\"') {
			for (word = fgetc(in); word != '\"'; word = fgetc(in));
		}
		if (word == '\'') {
			for (word = fgetc(in); word != '\''; word = fgetc(in));
		}
		if (word == '/') {
			word = fgetc(in);
			if (word == '/') {
				for (word = fgetc(in); word != '\n'; word = fgetc(in));
				lineNum++;
				continue;
			}
			else if (word == '*') {
				while (1) {
					for (word = fgetc(in); word != '*'; word = fgetc(in)) {
						if (word == '\n') {
							lineNum++;
						}
					}
					word = fgetc(in);
					if (word == '/') {
						break;
					}
					else {
						ungetc(word, in);
					}
				}	
			}
		}
		if (word == '(') {
			save[saveNum++] = word;
			push(stack, word);
		}
		if (word == '{') {
			if (stack[top].sign == '(') {
				flag = 2;					//≥ˆœ÷≤ª∆•≈‰
				ch = '(';
				re = stack[top].lineN;
			}
			else {
				save[saveNum++] = word;
				push(stack, word);
			}
		}
		if (word == ')') {
			save[saveNum++] = word;
			if (isEmpty()) {
				flag = 2;
				ch = ')';
				re = lineNum;
			}
			if (stack[top].sign == '(') {
				re = pop(stack);
			}
			else {
				flag = 2;
				ch = ')';
				re = lineNum;
			}
		}
		if (word == '}') {
			save[saveNum++] = word;
			if (isEmpty()) {
				flag = 2;
				ch = '}';
				re = lineNum;
			}
			if (stack[top].sign == '{') {
				re = pop(stack);
			}
			else {
				flag = 2;
				ch = '}';
				re = lineNum;
			}
		}
		if (flag == 2) {
			printf("without maching \'%c\' at line %d", ch, re);
			break;
		}
	}
	if (!isEmpty() && flag != 2) {
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