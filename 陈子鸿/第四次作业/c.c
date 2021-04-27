#include <stdio.h>
#include <string.h>
#define is_num(c) ((c)>='0'&&(c)<='9'?1:0)

enum oper{EPT,ADD,MIN,MUL,DIV,MOD,LEFT,RIGHT};
int prior[] = { -1,0,0,1,1,1,2,2 };

typedef struct sys {
	int num;
	char sign;
	int datatype;			//1ÊÇÊý×Ö£¬2ÊÇ·ûºÅ
}SYS;
SYS back[10000000];
int backNum = 0;

char stack[1000000];
int stackNum[100000];
int top,flag;
void initStack() {
	top = -1;
}
int isEmpty() {
	return top == -1;
}
int isFull() {
	return top == 1000000 - 1;
}
void push(char s[], char elem) {
	if (isFull()) {
		flag = 1;
	}
	else {
		s[++top] = elem;
	}
}
char pop(char s[]) {
	if (isEmpty()) {
		flag = 1;
	}
	else {
		return s[top--];
	}
	return 0;
}
void pushNum(int s[], int elem) {
	if (isFull()) {
		flag = 1;
	}
	else {
		s[++top] = elem;
	}
}
char popNum(int s[]) {
	if (isEmpty()) {
		flag = 1;
	}
	else {
		return s[top--];
	}
	return 0;
}

int getNum(char ch) {
	int ret = ch - '0';
	char tmp;
	tmp = getchar();
	while (tmp >= '0' && tmp <= '9') {
		ret = ret * 10 + tmp - '0';
		tmp = getchar();
	}
	ungetc(tmp, stdin);
	return ret;
}

int getSign(char ch) {
	switch (ch) {
	case'+':return ADD;
	case'-':return MIN;
	case'*':return MUL;
	case'/':return DIV;
	case'%':return MOD;
	case'(':return LEFT;
	case')':return RIGHT;
	default:return EPT;
	}
}
void operateSign(char ch) {
	int topSign=-1;
	int sign = getSign(ch);
	char laji;
	if (isEmpty(stack)) {
		push(stack, ch);
		return;
	}
	topSign = getSign(stack[top]);
	if (sign != RIGHT) {
		if (prior[sign] > prior[topSign]) {
			push(stack, ch);
		}
		else {
			while (prior[sign] <= prior[topSign]) {
				if(topSign == LEFT) {
					push(stack, ch);
					return;
				}
				back[backNum].sign = pop(stack);
				back[backNum++].datatype = 2;
				topSign = getSign(stack[top]);
			}
			push(stack, ch);
		}
	}
	else {
		while (topSign != LEFT) {
			back[backNum].sign = pop(stack);
			back[backNum++].datatype = 2;
			topSign = getSign(stack[top]);
		}
		laji = pop(stack);
	}
	
}
void compute(char sign) {
	int numl, numr, ret=0, s;
	numr = popNum(stackNum);
	numl = popNum(stackNum);
	s=getSign(sign);
	switch (s) {
	case ADD:ret = numl + numr; break;
	case MIN:ret = numl - numr;	break;
	case MUL:ret = numl * numr; break;
	case DIV:ret = numl / numr;	break;
	case MOD:ret = numl % numr; break;
	}
	pushNum(stackNum, ret);
}
int main()
{
	int i,op;
	char ch;
	initStack();
	while ((ch = getchar()) != '=') {
		if (is_num(ch)) {
			op = getNum(ch);
			back[backNum].num = op;
			back[backNum++].datatype = 1;
		}
		else if(ch==' '||ch=='\n'||ch=='\t'){
			continue;
		}
		else {
			operateSign(ch);
		}
	}
	while (!isEmpty()) {
		back[backNum].sign = pop(stack);
		back[backNum++].datatype = 2;
	}
	for (i = 0; i < backNum; i++) {
		if (back[i].datatype == 1) {
			pushNum(stackNum, back[i].num);
		}
		else {
			compute(back[i].sign);
		}
	}
	printf("%d", stackNum[top]);
	return 0;
}