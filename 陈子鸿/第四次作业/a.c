#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int top, op, num, flag=0;
int s[MAX];

void initStack() {
	top = -1;
}
int isEmpty() {
	return top == -1;
}
int isFull() {
	return top == MAX - 1;
}
void push(int s[], int elem) {
	if (isFull()) {
		flag = 1;
	}
	else {
		s[++top] = elem;
	}
}
int pop(int s[]) {
	if (isEmpty()) {
		flag = 1;
	}
	else {
		return s[top--];
	}
	return 0;
}

int main()
{
	initStack();
	while (1) {
		scanf("%d", &op);
		switch (op) {
		case -1:
			return 0;
		case 1:
			scanf("%d", &num);
			push(s, num);
			if (flag == 1) {
				printf("error ");
				flag = 0;
			}
			break;
		case 0:
			num = pop(s);
			if (flag == 1) {
				printf("error ");
				flag = 0;
			}
			else
				printf("%d ", num);
			break;
		}
	}
	return 0;
}