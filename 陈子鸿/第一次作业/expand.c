#include <stdio.h>
#include <string.h>

char s[1024];

int main()
{
	int i,j,ls;
	fgets(s,1024,stdin);
	ls = strlen(s);
	for(i=0;i<ls;i++){
		if(s[i]=='-'){
			int flag = s[i-1]-s[i+1];
			int num = 0;
			if(s[i-1]<='9'&&s[i-1]>='0') 
				num = 1;
			else if((s[i-1]<='Z'&&s[i+1]<='Z'&&s[i-1]>='A'&&s[i+1]>='A')||(s[i-1]>='a'&&s[i+1]>='a'&&s[i-1]<='z'&&s[i+1]<='z'))
				num = 2;
			if(flag<=9&&flag>=-9&&num==1){
				if(flag<0) flag=flag*-1;
				for(j=1;j<flag;j++){
					printf("%c",s[i-1]+j);
				}
			}else if(flag<=26&&flag>=-26&&num==2){
				if(flag<0) flag=flag*-1;
				for(j=1;j<flag;j++){
					printf("%c",s[i-1]+j);
				}
			}else{
				printf("%c",s[i]);
			}
		}else if((s[i]<='Z'&&s[i]>='A')||(s[i]>='a'&&s[i]<='z')||(s[i]<='9'&&s[i]>='0')){
			printf("%c",s[i]);
		}
	}
	return 0;	
}

