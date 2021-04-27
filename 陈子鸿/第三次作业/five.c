#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 90007
struct aii{//统计单词 
	char a[50];
	int num;
}f[1000];
int sort(const void*p1,const void *p2){
	struct aii* c=(struct aii*)p1;
	struct aii* b=(struct aii*)p2;
	if(strcmp(c->a,b->a)>0) return 1;
	else if(strcmp(c->a,b->a)<0) return -1;
	else return 0;
}
int main(){
	int i,j,k,m,n;
	FILE *in;
	char a[1000];
	int count=0;
	in=fopen("article.txt","r");
	for(i=0;i<1000;i++){
		strcpy(f[i].a,"\0");//初始化 
		f[i].num=0;
	}
	while((fgets(a,999,in))!=NULL){
		char b[50];
		k=0;
		int p=0;
		while(a[p]!='\0'){
			if(isalpha(a[p])){ 
				for(k=0;isalpha(a[p+k]);k++){//一个单词 
					b[k]=tolower(a[p+k]);
				}
				p+=k; 
				b[k++]='\0';
				int flag=0;
				for(j=0;j<count;j++){
					if(strcmp(f[j].a,b)==0){
						f[j].num=f[j].num+1;
						flag=1;//找到单词 
						break;
					}
				}
				if(flag==0){//增加单词 
					strcpy(f[count].a,b);
					f[count].num=f[count].num+1;
					count++;
				}
			}else{
				p++;
			}
		}
	}
	qsort(f,count,sizeof(struct aii),sort);
	for(i=0;i<count;i++){
		printf("%s %d\n",f[i].a,f[i].num);
	}
	return 0;
}


