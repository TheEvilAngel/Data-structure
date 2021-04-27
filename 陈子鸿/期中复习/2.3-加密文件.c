#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char key[55], word;
int vis[30];
int main()
{
	FILE* in, * out;
	in = fopen("encrypt.txt", "r");
	out = fopen("output.txt", "w");
	if (in == NULL) {
		printf("can't open file\n");
		return 1;
	}
	if (out == NULL) {
		printf("can't open file\n");
		return 1;
	}
	scanf("%s", key);
	int i, j;
	for (i = 0; key[i] != '\0'; i++) {
		if (!vis[key[i] - 'a']) {
			vis[key[i] - 'a'] = 1;
		}
		else {
			j = i;
			while (key[j]) {
				key[j] = key[j + 1];
				j++;
			}
			i--;
		}
	}
	int keyl = strlen(key);
	for (i = keyl, j = 25; j >=0 ; j--) {
		if (!vis[j]) {
			key[i++] = 'a' + j;
		}
	}
	//puts(key);
	while (1) {
		word = fgetc(in);
		if (word == EOF)
			break;
		if (word <= 'z' && word >= 'a') {
			word = key[word - 'a'];
		}
		fprintf(out, "%c", word);
	}
	return 0;
}