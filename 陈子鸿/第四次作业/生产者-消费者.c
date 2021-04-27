#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define isnum(x) ((x) <= '9' && (x) >= '0' ? 1 : 0) // ÅĞ¶Ï×Ö·ûÊÇ·ñÎªÊı×Ö
#include<ctype.h> 
#include<math.h>
struct node{
	int k1,k2;
}a[10000];
int p1=0,p2=0;
int main(){
	int i,j,k,m,n,num;
	int count=3;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num);
		for(j=0;j<num;j++){
			a[p2++].k1=i;
		}
		if((p2-p1)/count>=7&&count<5) count++;
		if((p2-p1)/count>=7&&count<5) count++;
		for(k=1;k<=count;k++){
			if(p2==p1) break;
			a[p1].k2=i;
			printf("%d : %d\n",p1+1,a[p1].k2-a[p1].k1);
			p1++;
		}
		if((p2-p1)/count<7&&count>3) count--;
		if((p2-p1)/count<7&&count>3) count--;
	}
	for(;p1<p2;){
		for(k=1;k<=count;k++){
			if(p2==p1) break;
			a[p1].k2=i;
			printf("%d : %d\n",p1+1,a[p1].k2-a[p1].k1);
			p1++;
		}
		if((p2-p1)/count<7&&count>3) count--;
		if((p2-p1)/count<7&&count>3) count--;
		i++;
	}
	return 0;
}

