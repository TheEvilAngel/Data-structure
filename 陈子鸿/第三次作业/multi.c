#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int lena = 0, lenb = 0, ret, x, lenc = 0;

typedef struct Link {
	int num;
	int exp;
	struct Link* next;
}link;

link* CreatLink() {
	link* head = (link*)malloc(sizeof(link));
	head->next = NULL;
	link* temp = head;
	temp->exp = -1;
	temp->num = -1;
	temp->next = NULL;
	int temp_num;
	int temp_exp;
	int flag;
	for (int i = 0; i < lena; i++)
	{
		for (int j = 0; j < lenb; j++)
		{
			temp = head;
			temp_num = a[i].num * b[j].num;
			temp_exp = a[i].exp + b[j].exp;
			flag = 1;
			while (temp->next != NULL)
			{
				if (temp->exp == temp_exp && flag)
				{
					temp->num += temp_num;
					flag = 0;
				}
				if (temp->exp > temp_exp && temp->next->exp < temp_exp && flag)
				{
					link* c = (link*)malloc(sizeof(link));
					c->exp = temp_exp;
					c->num = temp_num;
					c->next = temp->next;
					temp->next = c;
					flag = 0;
				}
				temp = temp->next;
			}
			if (temp->exp > temp_exp || temp->exp < 0)
			{
				link* c = (link*)malloc(sizeof(link));
				c->exp = temp_exp;
				c->num = temp_num;
				c->next = NULL;
				temp->next = c;
			}
			if (temp->exp == temp_exp || temp->exp < 0)
			{
				temp->num += temp_num;
			}
		}
	}
	return head;
}



int main() {
	char d; int i = 0;

	while (1)
	{
		scanf("%d%d", &a[lena].num, &a[lena].exp);
		scanf("%c", &d);
		lena++;
		if (d == '\n')break;
	}
	while (1)
	{
		scanf("%d%d", &b[lenb].num, &b[lenb].exp);
		scanf("%c", &d);
		lenb++;
		if (d == '\n')break;
	}

	link* temp = CreatLink();
	while (temp->next != NULL) {
		temp = temp->next;
		printf("%d %d ", temp->num, temp->exp);
	}
}


