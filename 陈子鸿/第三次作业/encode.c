#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

char Cipher[200];

char mapping[200];

int lenCipher;

typedef struct Link {
	char code;
	struct Link* next;
	struct Link* before;
}link;

void read()
{
	char Read_temp;
	int used = 0;
	while (scanf("%c", &Read_temp) != EOF)
	{
		if (Read_temp >= 32 && Read_temp <= 126)
		{
			for (int i = 0; i < lenCipher; i++)
			{
				used = 0;
				if (Cipher[i] == Read_temp)
				{
					used = 1;
					break;
				}
			}
			if (!used)
			{
				Cipher[lenCipher] = Read_temp;
				lenCipher++;
			}
		}
	}

	int Nowchar = 0;
	int Flag = 0;
	int temp, j;
	for (int i = lenCipher; i <= 94; i++)
	{
		j = 0;
		while (j < lenCipher)
		{
			if (Cipher[j] - ' ' == Nowchar)
			{
				Nowchar++;
				j = 0;
			}
			j++;
		}
		Cipher[i] = Nowchar + ' ';
		Nowchar++;
	}
}

link* CreatLink() {
	link* head = (link*)malloc(sizeof(link));
	head->next = NULL;
	head->before = NULL;
	link* temp = head;
	temp->code = ' ';
	temp->next = NULL;
	temp->before = NULL;
	for (int i = 0; i < 94; i++)
	{
		link* c = (link*)malloc(sizeof(link));
		c->code = Cipher[i];
		c->next = NULL;
		c->before = temp;
		temp->next = c;
		temp = temp->next;
		temp->before = c->before;
	}
	link* c = (link*)malloc(sizeof(link));
	c->code = Cipher[94];
	c->next = NULL;
	c->before = temp;
	temp->next = c;
	temp = temp->next;
	temp->next = head->next;
	link* tempBefore;
	tempBefore = temp;
	temp = temp->next;
	temp->before = tempBefore;
	return head;
}

void ReshapeLink(link* head) {
	int temp_code;
	int head_code = head->code;
	while (head->next != head)
	{
		temp_code = head->code;
		link* tempHead = head;
		head->before->next = head->next;
		head->next->before = head->before;
		head = head->next;
		free(tempHead);
		tempHead = NULL;
		for (int i = 2; i <= temp_code; i++)
		{
			head = head->next;
		}
		mapping[temp_code] = head->code;
	}
	mapping[head->code] = head_code;
}

void Read_Write(FILE* Input, FILE* Ouput)
{
	int  len = 0;
	char ch;
	char str[105000];
	ch = fgetc(Input);
	while (ch != EOF)
	{
		str[len++] = ch;
		ch = fgetc(Input);
	}

	for (int i = 0; i < len + 1; i++)
	{
		int flag = 0;
		if (str[i] >= ' ' && str[i] <= '~')
		{
			fputc(mapping[str[i]], Ouput);
		}
		else
		{
			fputc(str[i], Ouput);
		}
	}
	fclose(Input);
	fclose(Ouput);
}

int main() {
	read();

	link* LinkCipher = CreatLink();
	LinkCipher = LinkCipher->next;
	ReshapeLink(LinkCipher);

	FILE* Input, * Ouput;
	Input = fopen("in.txt", "r");
	Ouput = fopen("in_crpyt.txt", "w");

	Read_Write(Input, Ouput);
}


