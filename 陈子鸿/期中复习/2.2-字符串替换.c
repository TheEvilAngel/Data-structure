#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define tolower(c) (c>='A'&&c<='Z'?c-'A'+'a':c)

char str[500], strn[500], s[500], tmp[500];
int vis[500];
void getnext(char T[], int next[])
{
	int i = 0, j = -1;
	next[0] = -1;
	while (T[i] != '\0') {
		if (j == -1 || T[i] == T[j]) { //i为后缀位置；j为前缀位置
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j]; //若字符不同，则j值回溯
	}
}
void KMPindex(char S[], char T[])
{
	int i = 0, j = 0, * next;
	memset(vis, 0, 500);
	next = (int*)malloc(sizeof(int) * (strlen(T) + 1));
	getnext(T, next);
	while (S[i] != '\0') {
		if (tolower(S[i]) == tolower(T[j])) {
			i++;
			j++;
		}
		else
			(j == 0) ? i++ : (j = next[j]); 		//j回退到相应位置开始匹配，i值不变
		if (T[j] == '\0') 	//匹配成功，返回匹配位置
			vis[i- j] = 1;		
	}
	free(next);
	
}
int main()
{
	FILE* in, * out;
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
	scanf("%s", str);
	scanf("%s", strn);
	int i,j,k;
	int strl = strlen(str);
	while (fgets(s, 500 - 1, in) != NULL) {
		int sl = strlen(s);
		KMPindex(s, str);
		for (i = sl - 1; i >= 0; i--) {
			if (vis[i]) {
				strcpy(tmp, &s[i + strl]);
				s[i] = '\0';
				strcat(s, strn);
				strcat(s, tmp);
			}
		}
		/*for (i = 0; s[i] != '\0'; i++) {
			for (k = i, j = 0; tolower(s[k]) == tolower(str[j]); k++, j++);
			if (str[j] == '\0') {
				strcpy(tmp, &s[i+strl]);
				s[i] = '\0';
				strcat(s, strn);
				strcat(s, tmp);
			}
		}*/
		fprintf(out, "%s", s);
	}
	return 0;
}