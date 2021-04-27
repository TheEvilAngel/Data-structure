#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX_LINE 100
/*	1.��ʼ��
	2.'\0'
	3.Խ�����
	4.\n && \n\t
	5.ɾ��������ǰһ��=��һ�����ǵ��ٴ��жϵ�ǰλ�ã�i--����������������������������
*/
#define tolower(c) (c>='A'&&c<='Z'?c-'A'+'a':c)			//�궨��
//�����β
while (getchar() != EOF);
while (scanf("%c") != EOF);
while (fgets() != NULL);
//��ʼ������
memset(a, 0, sizeof(a));
memcpy(y, x, sizeof(x));	//��x�е�Ԫ�ظ��Ƶ�y��
//�����ʽ
%[-||+||0||#][�ַ����][.����]type;
���зֱ��ʾ������롢�з�������ǰ�ӷ��š�����ǰ���㡢�Խ�������ǰ׺||��С��ֵ��С����;

//�ߵ��ַ���
void rev(char s[]) {									
	int i, j;
	char temp;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}

}		

int str_str(char s[], char str[]);						//�����ַ����״γ��ֵ�λ��
void squeez(char s[], char c);							//ɾ��s�е��ַ�c
void replace(char s[], char str[], char str_new[]);		//�����ַ�������ԭʽ��ָ���ַ���
void getin();											//ע���ַ�������
void read();											//�ļ�����
void getnext(char T[], int next[])
{
	int i = 0, j = -1;
	next[0] = -1;
	while (T[i] != '\0') {
		if (j == -1 || T[i] == T[j]) { //iΪ��׺λ�ã�jΪǰ׺λ��
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j]; //���ַ���ͬ����jֵ����
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
			(j == 0) ? i++ : (j = next[j]); 		//j���˵���Ӧλ�ÿ�ʼƥ�䣬iֵ����
	}
	free(next);
	if (T[j] == '\0') 	//ƥ��ɹ�������ƥ��λ��
		return  i - j;
	else
		return -1;
}

//˳���
int searchElem(ElemType list[], int n, ElemType item);	//�۰����
int insertElem(int list[], int i, int item);			//����Ԫ��
int deleteElem(int list[], int i);						//ɾ��˳���Ԫ��
//����
//ջ����-141
void initStack();
int isEmpty(); 
int isFull();
void push(int s[], int elem);
int pop(int s[]);
//�Ӳ���,���Ϸ�����




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
	//�ַ�����ע�⻻�з��������ǵ�һ�еĻ��з�������n֮����봦������ÿ���������getsһ�Ρ�
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

//ջ����
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

//�Ӳ���
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