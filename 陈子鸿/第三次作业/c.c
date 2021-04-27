#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	int coe;
	int pow;
	struct node* next;
};
typedef struct node Node;
typedef struct node* Nodeptr;
Nodeptr list1, list2;
Nodeptr p, q, r, tmp, before;

int searchpow() {
	for (r = list2; r != NULL; before=r, r=r->next) {
		if (tmp->pow > r->pow) {
			break;
		}
		else if (tmp->pow == r->pow) {
			return 1;
		}
	}
	return 0;
}

int insertword() {
	if (r == list2) {
		tmp->next = list2;
		list2 = tmp;
	}
	else {
		tmp->next = r;
		before->next = tmp;
	}
	return 0;
}

int main()
{
	int a, n;
	char c;
	do {
		scanf("%d%d%c", &a, &n, &c);
		q = (Nodeptr)malloc(sizeof(Node));
		q->coe = a;
		q->pow = n;
		q->next = NULL;
		if (list1 == NULL) {
			list1 = p = q;
		}
		else {
			p->next = q;
			p = q;
		}
	} while (c != '\n');
	do {
		scanf("%d%d%c", &a, &n, &c);
		q = (Nodeptr)malloc(sizeof(Node));
		q->coe = a;
		q->pow = n;
		q->next = NULL;
		for (p = list1; p != NULL; p = p->next) {
			tmp = (Nodeptr)malloc(sizeof(Node));
			tmp->coe = p->coe * q->coe;
			tmp->pow = p->pow + q->pow;
			tmp->next = NULL;
			if (list2 == NULL) {
				list2 = tmp;
			}
			else {
				if (searchpow() == 1) {
					r->coe += tmp->coe;
					free(tmp);
				}
				else {
					insertword();
				}
			}
		}
	} while (c != '\n');

	for (p = list2; p != NULL; p = p->next) {
		printf("%d %d ",p->coe, p->pow);
	}
	return 0;
}