#include <stdio.h>
#include <string.h>
int n;
int list[15],f[15];

void dfs(int digit){
	if(digit==n+1){
		int i;
		for(i=1;i<=n;i++){
			printf("%d ",list[i]);
		}
		printf("\n");
		return;
	}
	int i;
	for(i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			list[digit] = i;
			dfs(digit+1);
			f[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	
	return 0;
 } 
