#include<stdio.h>
#include <stdlib.h> 
int main()
{
	FILE *in;
	in = fopen("example.c", "r");
	int num=1;
	int error=0;
	char a[200], b[200];
	int c[1000];
	int top=-1,count=-1;
	char t;
	int l=1;
	while(l)
	{
		t=fgetc(in);
		if(t==EOF)  break;
	    else if(t=='\n'){
	    	num++; 
		}else if(t=='"'){
			t=fgetc(in);
			for(;t!='"';){
				if(t=='\\')  t = fgetc(in);
				else if(t=='"')  break;
				t=fgetc(in);
			}
		}
		else if(t=='\'')
		{
			t=fgetc(in);
			for(;t!='\'';){
				if(t=='\\')  t = fgetc(in);
				else if(t=='\'')  break;
				t=fgetc(in);
			}
		}else if(t=='/'){
	    	t=fgetc(in);
	    	if(t=='/'){
	    		while((t= fgetc(in)) != '\n')
	    		  ;
	    		num++;
			}else if(t=='*')
			{
				int g= 0;
				t= fgetc(in);
				while(1)
				{
					if(g)  break;
					while(t!= '*')
				   {
					   t= fgetc(in);
					   if(t== '\n')  num++;
				   }  
				   t=fgetc(in);
				   if(t=='\n') num++;
				   if(t=='/') g= 1;
				}
			}
		}else if(t=='(') 
		{
			a[++top] = t;
			b[++count] = t;
			c[top] = num;
		}else if(t=='{')
		{
			if(a[top]=='('){
				printf("without maching '%c' at line %d\n", a[top], c[top]);
				error = 1;
				break;
			}else{
				a[++top]=t;
				b[++count]=t;
				c[top]=num;
			}	
		}else if(t==')')
		{
			b[++count] = t;
			c[top]=num;
			if(top == -1) 
			{
				printf("without maching '%c' at line %d\n",t,num);
				error = 1;
				break;
			}else {
				if( a[top]=='(' )    
				{
					top--;
				}else  
				{
					printf("without maching '%c' at line %d\n",t,num);
					error = 1;
					break;
				}
			}
			
		}else if(t=='}')
		{
			b[++count] = t;
			c[top]=num;
			if(top == -1)
			{
				printf("without maching '%c' at line %d\n",t,num);
				error = 1;
				break;
			}
			else
			{
				if( a[top]=='{' ){
					top--;
				}
				else
				{
					printf("without maching '%c' at line %d\n",t,num);
					error = 1;
					break;
				}
			}
		}
		
		else 
		continue;
	}
	
	if(top==0&&error==0)    //最后可能剩下左括号，没有匹配上右括号，上面的判断错误都是判断多出来的右括号 
	{
		printf("without maching '%c' at line %d\n",a[top] ,c[top]);
		error = 1;
	}
	b[++count] = '\0';
	if(error == 0) printf("%s", b);  
    fclose(in);  
    return 0;  
	
}


