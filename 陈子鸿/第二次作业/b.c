#include <stdio.h>
#include <string.h>
#define tolower(c) (c>='A'&&c<='Z'?c-'A'+'a':c)
#define MAX_LINE 10000
char s[1024], str[1024], line[MAX_LINE], temp[MAX_LINE];
int i, j, k, sl;
void empty() {
	int i;
	for (i = 0; temp[i] != '\0'; i++)
		temp[i] = '\0';
}
int main()
{
	FILE *in, *out;
	in = fopen("filein.txt", "r");
	out = fopen("fileout.txt", "w");
	if (in == NULL) {
		printf("can't open file\n");
		return 1;
	}
	if (out == NULL) {
		printf("can't open file\n");
		return 1;
	}

	scanf("%s", s);
	scanf("%s", str);
	while ((fgets(line, MAX_LINE - 1, in)) != NULL) {
		sl = strlen(s);
		for (i = 0; line[i] != '\0'; i++) {
			for (j = i, k = 0; s[k] != '\0' && tolower(line[j]) == tolower(s[k]); j++, k++);
			if (s[k] == '\0') {
				strcpy(temp, &line[i + sl]);
				for (j = i; j < i + sl; j++) {
					line[i] = '\0';
				}
				strcat(line, str);
				strcat(line, temp);
				//empty();
			}
		}
		fputs(line, out);
	}
	
	

	return 0;
}