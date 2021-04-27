#include <stdio.h>
#include <string.h>
char s[1000000];
char an[1000000];
int sl;
int main()
{
	int i,j=0,point,real,ans;
	gets(s);
	sl = strlen(s);
	i = sl - 1;
	while (s[i] == '0') {
		s[i] = '\0';
		i--;
		sl--;
	}
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == '.') {
			point = i;
			s[i] = '0';
			break;
		}
	}
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] != '0') {
			real = i;
			break;
		}	
	}
	ans = point - real;
	if (ans >= 0)
		ans--;
	for (i = real; i < sl; i++) {
		if (i == real + 1) {
			if (i + 1 != sl) 
				an[j++] = '.';
			if (point != real + 1) {
				an[j++] = s[i];
			}
			continue;
		}
		if (i == point)
			continue;
		an[j++] = s[i];
	}
	s[i] = '\0';
	printf("%se%d", an, ans);
	return 0;
}