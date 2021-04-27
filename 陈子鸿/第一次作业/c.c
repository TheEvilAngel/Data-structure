#include <stdio.h>
#include <string.h>
char s[105];
int point,meaning,re,i,sl,tri;

int main()
{
	gets(s);
	sl = strlen(s);
	for(i=sl-1;i>=0;i--){
		if(s[i]=='0'){
			s[i] = '\0';
			sl--;
		}else{
			break;
		}
	}
	for(i=0;i<sl;i++){
		if(s[i]=='.'){
			point = i;
			s[i] = '0';
			break;
		}
	}
	for(i=0;i<sl;i++){
		if(s[i]!='0'){
			meaning = i;
			break;
		}
	}
	re = point - meaning;
	if(re>0) re--;  //小数点在后面 
	
	for(i=meaning;i<sl;i++){
		if(i==meaning+1&&tri==0){
			printf(".");
			i--;
			tri=1;
			continue;
		}
		if(i==point){
			continue;
		}
		printf("%c",s[i]);
	}

	printf("e%d",re);
	return 0;
 } 
