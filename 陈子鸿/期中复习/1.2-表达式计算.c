#include <stdio.h>
#include <string.h>
long long op1, op2;
char sign1, sign2, sign3;
long long re;
int main()
{
	sign1 = '+';
	while (sign1 != '=') {
		scanf("%lld %c", &op1, &sign2);
		while (sign2 == '*' || sign2 == '/') {
			scanf("%lld %c", &op2, &sign3);
			if (sign2 == '*')
				op1 *= op2;
			else
				op1 /= op2;
			sign2 = sign3;
		}
		if (sign1 == '+')
			re += op1;
		else
			re -= op1;
		sign1 = sign2;
	}
	printf("%lld", re);
	return 0;
}