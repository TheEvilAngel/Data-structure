#include <stdio.h>
#include <string.h>
char numl[100],numr[100],c[100],d[100],re[100],flag,same=1;
char a[100],b[100];
int i,j,al,bl,max;

int main()
{
	scanf("%s",a);
	scanf("%s",b);
	al = strlen(a);
	bl = strlen(b);
	for(i=al-1;i>=0;i--){				//ÿһλ������֣���������
		c[al-1-i] = a[i] - '0'; 
	}
	for(i=bl-1;i>=0;i--){
		d[bl-1-i] = b[i] - '0';
	}
	
	while (al > 1 && c[al - 1] == 0) al--;				//ȥ��ǰ��0
	while (bl > 1 && d[bl - 1] == 0) bl--;
	
	if(al>bl||(al==bl&&strcmp(c,d)>0)){	//a����
		max = al;
		for(i=0;i<al;i++){
			numl[i] = c[i];
		}
		for(i=0;i<bl;i++){
			numr[i] = d[i];
		}
	}else if(al<bl||(al==bl&&strcmp(c,d)<0)){	//b����
		flag = 1;
		max = bl;
		for(i=0;i<al;i++){
			numr[i] = c[i];
		}
		for(i=0;i<bl;i++){
			numl[i] = d[i];
		}
	}else{								//���
		printf("0");
		return 0;
	}
	
	for(i=0;i<max;i++){					//�����������λ
		re[i] = numl[i]-numr[i];
		if(re[i]<0){
			numl[i+1]--;
			re[i] += 10;
		}
	}
	while(re[max-1]==0) max--;			//ȥ0
		
	if(flag==1) printf("-");
	for(i=max-1;i>=0;i--){
		printf("%d",re[i]);
	}
	
	return 0;
}
