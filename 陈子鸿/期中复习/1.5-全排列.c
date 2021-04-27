#include <stdio.h>
#include <string.h>
int n;
int re[15], vis[15];
void dfs(int t) {
	int i = 0;
	if (t == n + 1) {
		for (i = 1; i <= n; i++) {
			printf("%d ", re[i]);
		}
		puts("");
		return;
	}
	for (i = 1; i <= n; i++) {
		if (!vis[i]) {
			re[t] = i;
			vis[i] = 1;
			dfs(t + 1);
			vis[i] = 0;
		}
	}
}
int main() {
	scanf("%d", &n);
	dfs(1);
	return 0;
}