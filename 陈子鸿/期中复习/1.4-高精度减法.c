#include <stdio.h>
#include <string.h>
char a[100],b[100];
int a1[100], b1[100], re[100];
int rel;
void compute(int a[], int b[], int al) {
	int i, tmp;
	rel = al;
	for (i = 0; i < al; i++) {
		if (b[i] == '\0') {
			if (a[i] < 0) {
				a[i] += 10;
				a[i + 1]--;
			}
			re[i] = a[i];
			continue;
		}
		tmp = a[i] - b[i];
		if (tmp < 0) {
			tmp += 10;
			a[i + 1]--;
		}
		re[i] = tmp;
	}
}
int main() {
	scanf("%s", a);
	scanf("%s", b);
	int al, bl, i, j, flag=0;
	al = strlen(a);
	bl = strlen(b);
	for (i = al - 1, j = 0; i >= 0; i--)
		a1[j++] = a[i] - '0';
	for (i = bl - 1, j = 0; i >= 0; i--)
		b1[j++] = b[i] - '0';
	while (al > 1 && a1[al - 1] == 0)
		al--;
	while (bl > 1 && b1[bl - 1] == 0)
		bl--;

	if (al < bl) {
		flag = 1;
		compute(b1, a1, bl);
	}
	else if (al > bl) {
		compute(a1, b1, al);
	}
	else {
		for(i=al-1;i>=0;i--)
			if (a1[i] < b1[i]) {
				flag = 1;
				break;
			}
		if (flag == 1) {
			compute(b1, a1, bl);
		}
		else {
			compute(a1, b1, al);
		}
	}
	while (rel>1&&re[rel - 1] == 0)
		rel--;
	if (flag == 1)
		printf("-");
	for (i = rel - 1; i >= 0; i--) {
		printf("%d", re[i]);
	}
	return 0;
}