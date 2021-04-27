#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data {
	int prior;
	char name[50];
	char tel[50];
	int flag;
}data;
data inf[105];
int i,j,k,l,num;
char laji[5];

int cmp(const void* p1, const void* p2) {
	if (strcmp((*(data*)p1).name, (*(data*)p2).name) == 0) 
		return (*(data*)p1).prior - (*(data*)p2).prior;
	return strcmp((*(data*)p1).name, (*(data*)p2).name);
}

int main()
{
	scanf("%d", &num);    //字符串输入问题很大
	for (i = 0; i < num; i++) {
		scanf("%s", inf[i].name);
		scanf("%s", inf[i].tel);
		inf[i].prior = i;
		inf[i].flag = 0;		//flag=1代表重复，不需要这组数据
	}
	qsort(inf, num, sizeof(inf[0]), cmp);

	for (i = 0; i < num; i++) {
		if (strcmp(inf[i].name, inf[i + 1].name) == 0) {		//如果名字相同
			j = 1;
			while (strcmp(inf[i].name, inf[i + j].name) == 0) {	//把所有名字一样的都提出来
				if (strcmp(inf[i + j - 1].tel, inf[i + j].tel) == 0)	
					inf[i + j].flag = 1;	//两两比较，完全相同的不用输出(have bug)
				j++;
			}
			l = 0;
			for (k = i; k < i + j; k++) {
				if (inf[k].flag == 0) {
					l == 0?printf("%s %s\n\n", inf[k].name, inf[k].tel):printf("%s_%d %s\n\n", inf[k].name, l, inf[k].tel);
					l++;	
				}
			}
			i = i + j - 1;  //跳过判断过的数据
		}
		else if (inf[i].flag == 0) {
			printf("%s %s\n\n", inf[i].name, inf[i].tel);
		}
		
	}
	
}