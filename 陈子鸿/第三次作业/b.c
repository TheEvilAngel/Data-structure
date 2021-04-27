#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, m, qu;
struct node {
	int num;
	struct node* next;
};
struct node* f, * p, * q;
int main()
{
	int i;
	scanf("%d%d%d", &n, &m, &qu);
	for (i = 1; i <= n; i++) {
		q = (struct node*)malloc(sizeof(struct node));
		if (f == NULL) {
			f = p = q;
			p->num = i;
		}
		else {
			p->next = q;		
			p = q;
			p->num = i;
		}
	}
	p->next = f;
	for (p = f; p->num != qu; p = p->next);

	while (1) {
		for (i = 1; i < m - 1; i++) {
			p = p->next;
		}
		if (n == 2) {
			printf("%d", p->num);
			return 0;
		}
		q = p->next;
		p->next = p->next->next;
		p = p->next;
		free(q);
		n--;
	}
	return 0;
}