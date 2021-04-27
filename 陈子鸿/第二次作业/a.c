#include <stdio.h>
#include <string.h>

int a[25][25];
int i, j;

int main()
{
	memset(a, -1, sizeof(a));

	for (i = 1; i <= 19; i++) {
		for (j = 1; j <= 19; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 1; i <= 19; i++) {
		for (j = 1; j <= 19; j++) {
			if (a[i][j] == 1) {
				if (a[i][j + 1] == 1 && a[i][j + 2] == 1 && a[i][j + 3] == 1 && a[i][j + 4] == 0) {		
					printf("1:%d,%d", i, j);
					return 0;
				}
				if (a[i][j + 1] == 1 && a[i][j + 2] == 1 && a[i][j + 3] == 1 && a[i][j - 1] == 0) {
					printf("1:%d,%d", i, j);
					return 0;
				}
				if (a[i + 1][j] == 1 && a[i + 2][j] == 1 && a[i + 3][j] == 1 && a[i + 4][j] == 0) {
					printf("1:%d,%d", i, j);
					return 0;
				}
				if (a[i + 1][j] == 1 && a[i + 2][j] == 1 && a[i + 3][j] == 1 && a[i - 1][j] == 0) {
					printf("1:%d,%d", i, j);
					return 0;
				}
				if (j > 5 && a[i + 1][j - 1] == 1 && a[i + 2][j - 2] == 1 && a[i + 3][j - 3] == 1 && a[i + 4][j - 4] == 0) {
					printf("1:%d,%d", i, j);
					return 0;
				}
				if (j > 4 && a[i + 1][j - 1] == 1 && a[i + 2][j - 2] == 1 && a[i + 3][j - 3] == 1 && a[i - 1][j + 1] == 0) {
					printf("1:%d,%d", i, j);
					return 0;
				}
				if (a[i + 1][j + 1] == 1 && a[i + 2][j + 2] == 1 && a[i + 3][j + 3] == 1 && a[i + 4][j + 4] == 0) {
					printf("1:%d,%d", i, j);
					return 0;
				}
				if (a[i + 1][j + 1] == 1 && a[i + 2][j + 2] == 1 && a[i + 3][j + 3] == 1 && a[i - 1][j - 1] == 0) {
					printf("1:%d,%d", i, j);
					return 0;
				}
			}
			if (a[i][j] == 2) {
				if (a[i][j + 1] == 2 && a[i][j + 2] == 2 && a[i][j + 3] == 2 && a[i][j + 4] == 0) {
					printf("2:%d,%d", i, j);
					return 0;
				}
				if (a[i][j + 1] == 2 && a[i][j + 2] == 2 && a[i][j + 3] == 2 && a[i][j - 1] == 0) {
					printf("2:%d,%d", i, j);
					return 0;
				}
				if (a[i + 1][j] == 2 && a[i + 2][j] == 2 && a[i + 3][j] == 2 && a[i + 4][j] == 0) {
					printf("2:%d,%d", i, j);
					return 0;
				}
				if (a[i + 1][j] == 2 && a[i + 2][j] == 2 && a[i + 3][j] == 2 && a[i - 1][j] == 0) {
					printf("2:%d,%d", i, j);
					return 0;
				}
				if (j > 5 && a[i + 1][j - 1] == 2 && a[i + 2][j - 2] == 2 && a[i + 3][j - 3] == 2 && a[i + 4][j - 4] == 0) {
					printf("2:%d,%d", i, j);
					return 0;
				}
				if (j > 4 && a[i + 1][j - 1] == 2 && a[i + 2][j - 2] == 2 && a[i + 3][j - 3] == 2 && a[i - 1][j + 1] == 0) {
					printf("2:%d,%d", i, j);
					return 0;
				}
				if (a[i + 1][j + 1] == 2 && a[i + 2][j + 2] == 2 && a[i + 3][j + 3] == 2 && a[i + 4][j + 4] == 0) {
					printf("2:%d,%d", i, j);
					return 0;
				}
				if (a[i + 1][j + 1] == 2 && a[i + 2][j + 2] == 2 && a[i + 3][j + 3] == 2 && a[i - 1][j - 1] == 0) {
					printf("2:%d,%d", i, j);
					return 0;
				}
			}
		}
	}
	printf("No");
	return 0;
}