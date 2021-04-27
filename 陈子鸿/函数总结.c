#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX_LINE 100
/*	1.初始化
	2.'\0'
	3.越界访问
	4.\n && \n\t
	5.删除操作后（前一个=后一个）记得再次判断当前位置（i--）！！！！！！！！！！！！！
*/
#define tolower(c) (c>='A'&&c<='Z'?c-'A'+'a':c)			//宏定义
//读入结尾
while (getchar() != EOF);
while (scanf("%c") != EOF);
while (fgets() != NULL);
//初始化数组
memset(a, 0, sizeof(a));
memcpy(y, x, sizeof(x));	//把x中的元素复制到y中
//输出格式
%[-||+||0||#][字符宽度][.精度]type;
其中分别表示：左对齐、有符号数据前加符号、加入前导零、对进制数加前缀||对小数值加小数点;

//颠倒字符串
void rev(char s[]) {									
	int i, j;
	char temp;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}

}		

int str_str(char s[], char str[]);						//查找字符串首次出现的位置
void squeez(char s[], char c);							//删除s中的字符c
void replace(char s[], char str[], char str_new[]);		//用新字符串代替原式中指定字符串
void getin();											//注意字符串读入
void read();											//文件读入
void getnext(char T[], int next[])
{
	int i = 0, j = -1;
	next[0] = -1;
	while (T[i] != '\0') {
		if (j == -1 || T[i] == T[j]) { //i为后缀位置；j为前缀位置
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j]; //若字符不同，则j值回溯
	}
}
int KMPindex(char S[], char T[])
{
	int i = 0, j = 0, * next;

	next = (int*)malloc(sizeof(int) * (strlen(T) + 1));
	getnext(T, next);
	while (S[i] != '\0' && T[j] != '\0') {
		if (S[i] == T[j]) {
			i++;
			j++;
		}
		else
			(j == 0) ? i++ : (j = next[j]); 		//j回退到相应位置开始匹配，i值不变
	}
	free(next);
	if (T[j] == '\0') 	//匹配成功，返回匹配位置
		return  i - j;
	else
		return -1;
}

//顺序表
int searchElem(ElemType list[], int n, ElemType item);	//折半查找
int insertElem(int list[], int i, int item);			//插入元素
int deleteElem(int list[], int i);						//删除顺序表元素
//链表
//栈操作-141
void initStack();
int isEmpty(); 
int isFull();
void push(int s[], int elem);
int pop(int s[]);
//队操作,和上方类似




int str_str(char s[], char str[]) {
	int i, j, k;
	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; str[k] != '\0' && s[j] == str[k]; j++, k++);
		if (str[k] == '\0')
			return i;
	}
	return -1;
}

void squeez(char s[], char c) {
	int i, j;
	for (i = j = 0; s[i] != '\0'; i++) {
		if (s[i] != c)
			s[j++] = s[i];
		s[j] = '\0';
	}
}

void replace(char s[], char str[], char str_new[]) {
	int i, j, k;
	char temp[MAX_LINE];
	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; str[k] != '\0' && s[j] == str[k]; j++, k++);
		if (str[k] == '\0') {
			strcpy(temp, &s[i + strlen(str)]);
			for (j = i; j < i + strlen(str); j++) {
				s[i] = '\0';
			}
			strcat(s, str_new);
			strcat(s, temp);
		}
	}
}

void getin() {
	//字符输入注意换行符，尤其是第一行的换行符，输入n之后必须处理，建议每行输入结束gets一次。
	scanf("%d", &n);
	gets(laji);
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
			scanf("%c", &a[i][j]);
		gets(laji);
	}
}

void read() {
	FILE* in, * out;
	in = fopen("encrypt.txt", "r");
	out = fopen("output.txt", "w");
	if (in == NULL) {
		printf("can't open file\n");
		return 1;
	}
	if (out == NULL) {
		printf("can't open file\n");
		return 1;
	}
}





int searchElem(ElemType list[], int n, ElemType item) {
	int low = 0, hign = n - 1, mid;
	while (low <= high) {
		mid = (high + low) / 2;
		if (item < list[mid])
			high = mid - 1;
		else if (item > list[mid])
			low = mid + 1;
		else
			return (mid);
	}
	return low;
}

int insertElem(int list[], int i, int item) {
	int k;
	if (num == MAXSIZE || i<0 || i>num) {
		return -1;
	}
	for (k = num - 1; k >= i; k--) {
		list[k + 1] = list[k];
	}
	list[i] = item;
	num++;
	return 1;
}

int deleteElem(int list[], int i) {
	int k;
	if (num == 0 || i<0 || i>num - 1) {
		return -1;
	}
	for (k = i + 1; k < num; k++) {
		list[k - 1] = list[k];
	}
	num--;
	return 1;
}

//栈操作
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

//队操作
void initQueue() {
	front = 0;
	rear = MAXSIZE - 1;
	count = 0;
}
int isEmpty() {
	return count == 0;
}
int isFull() {
	return count == MAXSIZE;
}
void enQueue(ElemType queue[], ElemType item) {
	if (isFull())
		puts("Full queue!");
	else {
		rear = (rear + 1) % MAXSIZE;
		queue[rear] = item;
		count++;
	}
}
ElemType deQueue(ElemType queue[]) {
	ElemType e;
	if (isEmpty())
		puts("Empty queue");
	else {
		e = queue[front];
		count--;
		front = (front + 1) % MAXSIZE;
		return e;
	}
}