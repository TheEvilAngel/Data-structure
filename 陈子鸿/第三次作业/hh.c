#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct DNode {
	char word[50];
	int freq;
	struct DNode *prior, *next;
}DNode, *DLinkList;
bool InitDNode(DLinkList *p);
bool InsertNextDNode(DNode *pos, DNode *ptr);
bool sort(DNode* ptr1, DNode* ptr2);
bool DeleteNextNode(DNode *p);
bool OutputList(DNode *p);
DNode* isexist(DLinkList p, DNode Word);
int main()
{
	DLinkList L;
	InitDNode(&L);
	FILE *in = fopen("article.txt", "r");
	DNode store;
	store.prior = NULL;			store.next = NULL;			store.freq = 1;
	DNode *ptr = L;
	while (fscanf(in, "%s", store.word) != EOF)
	{
		int inilen=strlen(store.word);
		int cnt1 = 0, cnt2 = 0;
		store.prior = NULL;			store.next = NULL;			store.freq = 1;
		while (cnt1<inilen)
		{
			while (isalpha(store.word[cnt1]) == 0)		cnt1++;
			if(cnt1>=inilen)
				break;
			while (isalpha(store.word[cnt1]) != 0)
			{
				if (isupper(store.word[cnt1]) != 0)
				{
					store.word[cnt2++] = store.word[cnt1] + 'a' - 'A';
					cnt1++;
				}
				else
				{
					store.word[cnt2++] = store.word[cnt1];
					cnt1++;
				}
			}
			store.word[cnt2] = '\0';
			if (isexist(L, store) == NULL)
			{
				DLinkList P;
				InitDNode(&P);
				*P = store;
				InsertNextDNode(ptr, P);
				ptr = ptr->next;
			}
			else
			{
				DNode *s = isexist(L, store);
				s->freq++;
			}
			cnt2 = 0;
		}
	}
	fclose(in);
	DNode *ptr1 = L->next, *ptr2;
	while (ptr1 != NULL)
	{
		ptr2 = L->next;
		while (ptr2 != NULL)
		{
			if (strcmp(ptr1->word, ptr2->word) < 0)
			{
				sort(ptr1, ptr2);
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	OutputList(L);
	return 0;
}
bool InitDNode(DLinkList *p)
{
	*p = (DNode *)malloc(sizeof(DNode));
	if (*p == NULL)	return false;
	strcpy((*p)->word, "wordfreq");
	(*p)->prior = NULL;
	(*p)->next = NULL;
	return true;
}
bool InsertNextDNode(DNode *pos, DNode *ptr)
{
	if (pos == NULL || ptr == NULL)		return false;
	ptr->next = pos->next;
	if (pos->next != NULL)		pos->next->prior = ptr;
	ptr->prior = pos;
	pos->next = ptr;
	return true;
}
bool sort(DNode* ptr1, DNode* ptr2)
{
	if (ptr1 == NULL || ptr2 == NULL)			return false;
	DNode store1;				store1 = *ptr1;
	strcpy(ptr1->word, ptr2->word);				strcpy(ptr2->word, store1.word);
	ptr1->freq = ptr2->freq;								ptr2->freq = store1.freq;
	return true;
}
bool DeleteNextNode(DNode *p)
{
	DNode *q = p->next;
	if (q == NULL)		return false;
	if (q->next == NULL)
	{
		p->next = NULL;
		free(q);
		q = NULL;
	}
	else
	{
		p->next = q->next;
		q->next->prior = p;
		free(q);
		q = NULL;
	}
	return true;
}
bool OutputList(DNode *p)
{
	if (p == NULL)			return false;
	else {
		DNode *z = p->next;
		while (z != NULL) {
			printf("%s %d\n", z->word, z->freq);
			z = z->next;
		}
		return true;
	}
}
DNode* isexist(DLinkList p, DNode Word)
{
	DNode *ptr = p->next;
	while (ptr != NULL)
	{
		if(strcmp(ptr->word,Word.word)==0)
			return ptr;
		ptr=ptr->next;
	}
	return NULL;
}


