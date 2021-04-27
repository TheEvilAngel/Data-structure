#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> 
#include<math.h>
struct node{
	int u;
	int uu;
	int uuu;
	char c[1000];
}f[1000];
int main(){
	int i,j,k,m,n,count=0,r,w,q,nn;
	char a[1000],b[1000],gg[100],ggg[1000]="";
	gets(a);
	scanf("%d",&n);
	nn=strlen(a);
	for(count=0;count<n;count++){
		scanf("%d %d %s",&f[count].u,&f[count].uu,f[count].c);
	}
	char *p1,*p2,*p3;
	for(i=n-1;i>=0;i--){
		if(f[i].u==1){
			r=strlen(f[i].c);
			p1=&a[f[i].uu+r];
			memset(ggg,'\0',sizeof (char) * 1000);
			strcat(ggg,p1);
			nn=strlen(a);
			for(j=f[i].uu;j<nn;j++){
				a[j]='\0';
			}
			strcat(a,ggg);
		}else{
			p1=&a[f[i].uu];
			memset(ggg,'\0',sizeof (char) * 1000);
			strcat(ggg,p1);
			nn=strlen(a);
			for(j=f[i].uu;j<nn;j++){
				a[j]='\0';
			}
			strcat(a,f[i].c);
			strcat(a,ggg);
		}
		//puts(a);
	}
	for(i=0;i<n;i++){
		if(f[i].u==2){
			f[i].uuu=strlen(f[i].c);
		}
	}
	gets(gg);
	scanf("%d",&k);
	while(k!=-1){
		if(k==3){
			count--;
		}else if(k==2){
			scanf("%d %d",&f[count].uu,&f[count].uuu);
			f[count].u=k;
			count++;
		}else{
			scanf("%d %s",&f[count].uu,f[count].c);
			f[count].u=k;
			count++;
		}
		scanf("%d",&k);
	}
	for(i=0;i<count;i++){
		if(f[i].u==1){
			p1=&a[f[i].uu];
			memset(ggg,'\0',sizeof (char) * 1000);
			strcat(ggg,p1);
			nn=strlen(a);
			for(j=f[i].uu;j<nn;j++){
				a[j]='\0';
			}
			strcat(a,f[i].c);
			strcat(a,ggg);
		}else{
			r=f[i].uuu;
			p1=&a[f[i].uu+r];
			memset(ggg,'\0',sizeof (char) * 1000);
			strcat(ggg,p1);
			nn=strlen(a);
			for(j=f[i].uu;j<nn;j++){
				a[j]='\0';
			}
			strcat(a,ggg);
		}
		//nn=strlen(a);
		//puts(a);
	}
	puts(a);
	return 0;
}

