#include <stdio.h>
#include <string.h>
#define is_num(c) ((c)>='0'&&(c)<='9'?1:0)

enum oper { EPT, ADD, MIN, MUL, DIV, MOD, LEFT, RIGHT };	//��������ȫ���������
int prior[] = { -1,0,0,1,1,1,2,2 };							//�����������һһ��Ӧ

typedef struct sys {
	int num;
	int sign;
	int datatype;			//1�����֣�2�Ƿ���
}SYS;
SYS back[10000000];			//��׺���ʽ
int backNum = 0;			//��ʼ��ʱ���׺���ʽΪ��

int stack[1000000];			//����һ��ջ��һ��ʼ��ŷ��š������ɺ�׺���ʽ��֮���������
int top, flag;				//ջ��غ���
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

int getNum(char ch) {				//���ַ�����Ϊ����
	int ret = ch - '0';
	char tmp;
	tmp = getchar();
	while (tmp >= '0' && tmp <= '9') {
		ret = ret * 10 + tmp - '0';
		tmp = getchar();
	}
	ungetc(tmp, stdin);				//��������ķ��ص������У���һ���ٶ�һ��
	return ret;
}

int getSign(char ch) {				//���������ֻ�
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
void operateSign(char ch) {			//����������ջ�ͳ�ջ
	int topSign = -1;
	int sign = getSign(ch);
	int laji;
	if (isEmpty(stack)) {			//ջ��ֱ����
		push(stack, sign);
		return;
	}
	topSign = stack[top];
	if (sign != RIGHT) {						//�������������
		if (prior[sign] > prior[topSign]) {			//Ҫ�ŵ����ȼ���
			push(stack, sign);
		}
		else {
			while (prior[sign] <= prior[topSign]) {	//Ҫ�ŵ����ȼ��ȸ���ջ
				if (topSign == LEFT) {				//�������������ţ�����Ϳ�ջһ����ֱ�ӽ���
					push(stack, sign);				
					return;
				}
				back[backNum].sign = pop(stack);	//���ǵĻ���һֱȡ��
				back[backNum++].datatype = 2;
				topSign = stack[top];
			}
			push(stack, sign);						//������ڴ���ķ�����ջ
		}
	}
	else {									//�����������
		while (topSign != LEFT) {					//ȡ������ֱ������������
			back[backNum].sign = pop(stack);
			back[backNum++].datatype = 2;
			topSign = stack[top];
		}
		laji = pop(stack);							//������ȡ������
	}

}
void compute(int sign) {				//���������
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
		if (is_num(ch)) {									//�������������
			op = getNum(ch);
			back[backNum].num = op;
			back[backNum++].datatype = 1;
		}
		else if (ch == ' ' || ch == '\n' || ch == '\t') {	//�������û�����
			continue;
		}
		else {
			operateSign(ch);
		}
	}
	while (!isEmpty()) {									//ȡ������Ԫ��
		back[backNum].sign = pop(stack);
		back[backNum++].datatype = 2;
	}
	//��׺���ʽ���
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