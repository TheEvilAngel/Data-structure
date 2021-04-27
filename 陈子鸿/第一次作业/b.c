#include <stdio.h>
#include <string.h>
#define MAX 1024
char sign[10]={'+','-','*','/'};
char exp[MAX];

typedef struct STACK{
	int data[MAX];
	int top;
}stack;
stack num_stack,sign_stack;

void Initstack(stack *s){
	s->top = 0;
}
void push(stack *s,int n){
	s->data[s->top++] = n;
}

int pop(stack *s){
	return s->data[--s->top];
}

int judge(char n){
	int i,flag=0;
	for(i=0;i<=3;i++){
		if(n==sign[i]) flag=1;
	}
	if(flag==1) return 1;
	else return 0;
}

int cal(int a,char op,int b){
	int val=0;
	switch(op){
		case '+': val = a+b; break;
		case '-': val = a-b; break;
		case '*': val = a*b; break;
		case '/': val = a/b; break;
	}
	return val; 
}

void squeez(char s[],char c){
	int i,j;
	for(i=j=0;s[i]!='\0';i++){
		if(s[i]!=c) s[j++]=s[i];
	}
	s[j]='\0';
}

int main()
{
	int i,tri=1,el,result,flag=0,fu=0;
	int numl,numr,val;
	char op;
	gets(exp);
	squeez(exp,' ');
	squeez(exp,'=');
	el=strlen(exp);
	Initstack(&num_stack);
	Initstack(&sign_stack);
	push(&num_stack,'#');
	push(&sign_stack,'#');
	for(i=0;i<el;i++){
		if(judge(exp[i])==1) flag=1;
	}
	if(flag==0){
		puts(exp);
		return 0;
	}
	for(i=0;i<el;i++){
		if(judge(exp[i])==1){ //is sign	
			if(exp[i]=='+'||exp[i]=='-'){
				push(&sign_stack,exp[i]);
			}else{
				push(&sign_stack,exp[i]);
				tri = 0;
				continue;	
			}	
		}else{
			int data = exp[i]-'0',j;
			for(j=i;j<el-1;j++){
				if(exp[j+1]<='9'&&exp[j+1]>='0'){
				data = data*10 + exp[j+1]-'0';
				}else{
					i = j;
					break;
				}
			}
			push(&num_stack,data);
			i=j;
			if(tri==0){
					numr = pop(&num_stack);
					numl = pop(&num_stack);
					op = pop(&sign_stack);
					val = cal(numl,op,numr);
					push(&num_stack,val);
					tri = 1;
			}
		}
	}
	while(num_stack.data[num_stack.top-2]!='#'){
		numr = pop(&num_stack);
		numl = pop(&num_stack);
		op = pop(&sign_stack);
		if(sign_stack.data[sign_stack.top-1]=='-'){
			numl = numl*(-1);
			sign_stack.data[sign_stack.top-1]='+';
		}
		val = cal(numl,op,numr);
		push(&num_stack,val);
	}
	
	result = pop(&num_stack);
	printf("%d",result);
	
	return 0;
}


 
