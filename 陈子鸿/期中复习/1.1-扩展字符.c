#include <stdio.h>
#include <string.h>

int sl;
char s[1000000];


int judge(char c) {
	if (c <= 'z' && c >= 'a')
		return 1;
	if (c <= 'Z' && c >= 'A')
		return 2;
	if (c <= '9' && c >= '0') 
		return 3;
	return 0;
}
int main()
{
	int i;
	char j;
	gets(s);
	sl = strlen(s);
	for (i = 0; i < sl; i++) {
		if (s[i] != '-') {
			printf("%c", s[i]);
		}
		else {
			if (i == 0 || i == sl - 1)
				printf("%c", s[i]);
			else {
				if (judge(s[i - 1]) == judge(s[i + 1])) {
					for (j = s[i - 1] + 1; j < s[i + 1]; j++)
						printf("%c", j);
				}
				else {
					printf("%c", s[i]);
				}
			}
		}
	}
	return 0;
}