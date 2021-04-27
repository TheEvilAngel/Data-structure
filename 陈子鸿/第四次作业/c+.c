#include <stdio.h>
#include <string.h>
#define is_num(c) ((c)>='0'&&(c)<='9'?1:0)

enum oper { EPT, ADD, MIN, MUL, DIV, MOD, LEFT, RIGHT };	//将操作符全部变成数字
int prior[] = { -1,0,0,1,1,1,2,2 };							//和上面操作符一一对应

typedef struct sys {
	int num;
	int sign;
	int datatype;			//1是数字，2是符号
}SYS;
SYS back[10000000];			//后缀表达式
int backNum = 0;			//开始的时候后缀表达式为空

int stack[1000000];			//定义一个栈：一开始存放符号——生成后缀表达式；之后用与计算
int top, flag;				//栈相关函数
void initStack() {
	top = -1;
}
int isEmpty() {
	return top == -1;
}
int isFull() {
	return top == 1000000 - 1;
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

int getNum(char ch) {				//将字符串变为数字
	int ret = ch - '0';
	char tmp;
	tmp = getchar();
	while (tmp >= '0' && tmp <= '9') {
		ret = ret * 10 + tmp - '0';
		tmp = getchar();
	}
	ungetc(tmp, stdin);				//将最后读入的返回到输入中，下一次再读一遍
	return ret;
}

int getSign(char ch) {				//将符号数字化
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
void operateSign(char ch) {			//操作符号入栈和出栈
	int topSign = -1;
	int sign = getSign(ch);
	int laji;
	if (isEmpty(stack)) {			//栈空直接入
		push(stack, sign);
		return;
	}
	topSign = stack[top];
	if (sign != RIGHT) {						//如果不是右括号
		if (prior[sign] > prior[topSign]) {			//要放的优先级高
			push(stack, sign);
		}
		else {
			while (prior[sign] <= prior[topSign]) {	//要放的优先级比高于栈
				if (topSign == LEFT) {				//如果左边是左括号（情况和空栈一样，直接进）
					push(stack, sign);				
					return;
				}
				back[backNum].sign = pop(stack);	//不是的话就一直取出
				back[backNum++].datatype = 2;
				topSign = stack[top];
			}
			push(stack, sign);						//最后将正在处理的符号入栈
		}
	}
	else {									//如果是右括号
		while (topSign != LEFT) {					//取出所有直到遇见左括号
			back[backNum].sign = pop(stack);
			back[backNum++].datatype = 2;
			topSign = stack[top];
		}
		laji = pop(stack);							//左括号取出丢掉
	}

}
void compute(int sign) {				//计算操作数
	int numl, numr, ret = 0;
	numr = pop(stack);
	numl = pop(stack);
	switch (sign) {
	case ADD:ret = numl + numr; break;
	case MIN:ret = numl - numr;	break;
	case MUL:ret = numl * numr; break;
	case DIV:ret = numl / numr;	break;
	case MOD:ret = numl % numr; break;
	}
	push(stack, ret);
}
int main()
{
	int i, op;
	char ch;
	initStack();
	while ((ch = getchar()) != '=') {				
		if (is_num(ch)) {									//如果读入是数字
			op = getNum(ch);
			back[backNum].num = op;
			back[backNum++].datatype = 1;
		}
		else if (ch == ' ' || ch == '\n' || ch == '\t') {	//读入的是没意义的
			continue;
		}
		else {
			operateSign(ch);
		}
	}
	while (!isEmpty()) {									//取出所有元素
		back[backNum].sign = pop(stack);
		back[backNum++].datatype = 2;
	}
	//后缀表达式完成
	for (i = 0; i < backNum; i++) {
		if (back[i].datatype == 1) {
			push(stack, back[i].num);
		}
		else {
			compute(back[i].sign);
		}
	}
	printf("%d", stack[top]);
	return 0;
}