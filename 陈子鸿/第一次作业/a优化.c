#include <stdio.h>
#include <string.h>
int re, op1, op2;
char sign1, sign2, sign3;

int main()
{
	sign1 = '+';
	while (sign1 != '=') {
		scanf("%d %c", &op1, &sign2);
		while (sign2 == '*' || sign2 == '/') {
			scanf("%d %c", &op2, &sign3);
			if (sign2 == '*') {
				op1 *= op2;
			}
			if (sign2 == '/') {
				op1 /= op2;
			}
			sign2 = sign3;
		}
		if (sign1 == '+')
			re += op1;
		else
			re -= op1;
		sign1 = sign2;
	}
	printf("%d", re);
	return 0;
}