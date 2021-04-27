#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define isnum(x) ((x) <= '9' && (x) >= '0' ? 1 : 0) // 判断字符是否为数字
#include<ctype.h> 
#include<math.h>
int main(){
	int i,j,k,m,n,q,k1,k2,k3;
	char a[100001],f[100001],c[100],d[10000];
	gets(f);
	int b[1000],count=0;
	int num1=0,num2=0;
	for(i=0;f[i]!='\0';i++){
		if(isnum(f[i])==1){
			for(;isnum(f[i])==1;i++){
				a[num1++]=f[i];
			}
			i--;
			a[num1++]='.';//用.来分隔数字 
		}else if(f[i]=='('){
			d[num2++]=f[i];
		}else if(f[i]==')'){
			num2--;
			for(;d[num2]!='(';num2--){
				a[num1++]=d[num2];
			}
		}else if(f[i]=='+'){
			num2--;
			for(;num2>=0&&d[num2]!='(';num2--){
				a[num1++]=d[num2];
			}
			num2++;
			d[num2++]=f[i];
		}else if(f[i]=='-'){
			num2--;
			for(;num2>=0&&d[num2]!='(';num2--){
				a[num1++]=d[num2];
			}
			num2++;
			d[num2++]=f[i];
		}else if(f[i]=='*'){
			num2--;
			for(;(d[num2]=='*'||d[num2]=='/'||d[num2]=='%')&&num2>=0;num2--){
				a[num1++]=d[num2];
			}
			num2++;
			d[num2++]=f[i];
		}else if(f[i]=='/'){
			num2--;
			for(;(d[num2]=='*'||d[num2]=='/'||d[num2]=='%')&&num2>=0;num2--){
				a[num1++]=d[num2];
			}
			num2++;
			d[num2++]=f[i];
		}else if(f[i]=='%'){
			num2--;
			for(;(d[num2]=='*'||d[num2]=='/'||d[num2]=='%')&&num2>=0;num2--){
				a[num1++]=d[num2];
			}
			num2++;
			d[num2++]=f[i];
		}
	}
	num2--;
	for(;num2>=0;num2--){
		a[num1++]=d[num2];
	}
	a[num1++]='\0';
	for(i=0;a[i]!='\0';){
		if(isnum(a[i])==1){
			j=0;
			for(;isnum(a[i])==1;i++){
				c[j++]=a[i];
			}
			c[j++]='\0';
			m=atoi(c);
			b[count++]=m;
		}else if(a[i]=='.'){
			i++;
			continue;
		}else{
			k1=b[--count];
			k2=b[--count];
			if(a[i]=='+'){
				k3=k1+k2;
				b[count++]=k3;
			}else if(a[i]=='*'){
				k3=k1*k2;
				b[count++]=k3;
			}else if(a[i]=='-'){
				k3=k2-k1;
				b[count++]=k3;
			}else if(a[i]=='/'){
				k3=k2/k1;
				b[count++]=k3;
			}else{
				k3=k2%k1;
				b[count++]=k3;
			}
			i++;
		}
	}
	printf("%d\n",b[0]);
	return 0;
}

