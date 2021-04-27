#include <stdio.h>
#include <string.h>
char key[55], vis[30], ch, s[1024], save[1024];
int keyl, i, j;

int main()
{
	FILE *in, *out;
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

	while ((ch = getchar()) != '\n') {
		if (vis[ch-'a'] == 1)
			continue;
		vis[ch-'a']++;
		key[keyl++] = ch;
	}
	for (i = keyl, j = 0; i < 26; i++, j++) {
		if (vis['z' - 'a' - j] == 1) {
			i--;
			continue;
		}
		key[i] = 'z' - j;
	}

	while (fgets(s, 1024 - 1, in) != NULL) {
		for (i = 0; s[i] != '\0'; i++) {
			if (s[i] <= 'z' && s[i] >= 'a')
				save[i] = key[s[i] - 'a'];
			else
				save[i] = s[i];
		}
		fputs(save, out);
	}
	
	return 0;
}