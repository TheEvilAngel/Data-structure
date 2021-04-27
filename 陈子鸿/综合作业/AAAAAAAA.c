#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>

FILE* Input, * StopWords, * Res;

int N;

typedef struct Link
{
	int num;
	struct Link* next[26];
}link;

typedef struct Sentence
{
	int num;
	int len;
	char sen[1536];
}sentence;

typedef struct Order
{
	int num;
	int pla;
}order;

sentence sen[1097152];

int SenPla = 0;

int cnt[256];//桶排的桶

order tmp[1100000], t[1100000];

void radixSort_lower(int length) {
	int radix = 256;
	int p = 1;//目前的位
	for (int d = 0; d < 4; d++)
	{//循环次数
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < length; i++)
		{
			int k = (t[i].num / p) % radix;//获取当前位的数字
			++cnt[k];//记录该数字出现的次数
		}
		for (int i = 0; i < radix; i++)
			cnt[i] += cnt[i - 1];//前缀和处理后，cnt变为当前数字后一个数在构成的序列中的排名。
		for (int i = length - 1; i >= 0; i--)
		{//倒序保证了稳定性，可以想想为什么
			int k = (t[i].num / p) % radix;
			tmp[--cnt[k]] = t[i];
		}
		for (int i = 0; i <= length; i++)
		{
			t[i] = tmp[i];
		}
		p *= radix;
	}
}

void radixSort_upper(int length) {
	int radix = 256;
	int p = 1;//目前的位
	for (int d = 0; d < 4; d++)
	{
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < length; i++)
		{
			int k = (t[i].num / p) % radix;//获取当前位的数字
			++cnt[k];//记录该数字出现的次数
		}
		for (int i = radix - 2; i >= 0; i--)
		{
			cnt[i] += cnt[i + 1];
		}
		for (int i = 0; i < length; i++)
		{
			int k = (t[i].num / p) % radix;
			tmp[--cnt[k]] = t[i];
		}
		for (int i = 0; i <= length; i++)
		{
			t[i] = tmp[i];
		}
		p *= radix;
	}
}

inline link* CreatLink()
{
	Input = fopen("article.txt", "r");
	link* head = (link*)malloc(sizeof(link));
	char Read_temp;
	link* temp = head;

	int SenLen = 0;
	temp->num = 0;
	int i, j;
	for (i = 0; i < 26; i++)
	{
		temp->next[i] = NULL;
	}

	Read_temp = fgetc(Input);
	while (Read_temp != EOF)
	{
		if (Read_temp != '.' && Read_temp != '?' && Read_temp != '!')
		{
			sen[SenPla].sen[SenLen] = Read_temp;
			SenLen++;
		}
		else
		{
			sen[SenPla].sen[SenLen] = Read_temp;
			SenLen++;
			sen[SenPla].len = SenLen;
			sen[SenPla].num = 0;
			SenLen = 0;
			SenPla++;
		}
		if (Read_temp >= 65 && Read_temp <= 90)
		{
			Read_temp += 32;
		}
		if (Read_temp >= 97 && Read_temp <= 122)
		{
			if (temp->next[Read_temp - 97] == NULL)
			{
				link* c = (link*)malloc(sizeof(link));
				c->num = 0;
				for (j = 0; j < 26; j++)
				{
					c->next[j] = NULL;
				}
				temp->next[Read_temp - 97] = c;
			}
			temp = temp->next[Read_temp - 97];
		}
		if (Read_temp < 97 || Read_temp > 122)
		{
			temp->num++;
			temp = head;
		}
		Read_temp = fgetc(Input);
	}
	fclose(Input);

	return head;
}

inline link* FixLink(link* head)
{
	StopWords = fopen("stopwords.txt", "r");
	link* temp = head;
	char Read_temp;
	Read_temp = fgetc(StopWords);
	while (Read_temp != EOF)
	{
		if (Read_temp >= 97 && Read_temp <= 122)
		{
			if (temp->next[Read_temp - 97] == NULL)
			{
				temp = head;
				Read_temp = fgetc(StopWords);
				while (Read_temp >= 97 && Read_temp <= 122 && Read_temp != EOF)
				{
					Read_temp = fgetc(StopWords);
				}
			}
			else
			{
				temp = temp->next[Read_temp - 97];
			}
		}
		if (Read_temp < 97 || Read_temp > 122)
		{
			temp->num = 0;
			temp = head;
		}
		Read_temp = fgetc(StopWords);
	}

	fclose(StopWords);
	return head;

}

inline char tolow(char Read_temp)
{
	if (Read_temp >= 65 && Read_temp <= 90)
	{
		return Read_temp + 32;
	}
	else
	{
		return Read_temp;
	}

}

inline void CountZero(link* head, int count)
{
	int tempplace;
	link* temp = head;
	int CountS;
	for (CountS = 0; CountS < SenPla; CountS++)
	{
		tempplace = 0;
		if (sen[CountS].len > count)
		{
			while (tempplace < sen[CountS].len)
			{
				if (tolow(sen[CountS].sen[tempplace]) >= 97 && tolow(sen[CountS].sen[tempplace]) <= 122)
				{
					if (temp->next[tolow(sen[CountS].sen[tempplace]) - 97] != NULL)
					{
						temp = temp->next[tolow(sen[CountS].sen[tempplace]) - 97];
						tempplace++;
						if (tempplace == sen[CountS].len)
						{
							sen[CountS].num += temp->num;
							temp = head;
						}
					}
					else
					{
						if (tempplace != sen[CountS].len - 1)
						{
							temp = head;
							if (tolow(sen[CountS].sen[tempplace + 1]) < 97 || tolow(sen[CountS].sen[tempplace + 1]) > 122)
							{
								while (1)
								{
									tempplace++;
									if (tolow(sen[CountS].sen[tempplace]) >= 97 && tolow(sen[CountS].sen[tempplace]) <= 122)
									{
										break;
									}
									if (tempplace == sen[CountS].len - 1)
									{
										break;
									}
								}
							}
							else
							{
								while (1)
								{
									tempplace++;
									if (tempplace == sen[CountS].len - 1)
									{
										break;
									}
									if (tolow(sen[CountS].sen[tempplace]) < 97 || tolow(sen[CountS].sen[tempplace]) > 122)
									{
										break;
									}
								}
								while (1)
								{
									tempplace++;
									if (tolow(sen[CountS].sen[tempplace]) >= 97 && tolow(sen[CountS].sen[tempplace]) <= 122)
									{
										break;
									}
									if (tempplace == sen[CountS].len - 1)
									{
										break;
									}
								}
							}
						}
						else
						{
							tempplace++;
							temp = head;
						}
					}
				}
				else
				{
					sen[CountS].num += temp->num;
					temp = head;
					while (1)
					{
						tempplace++;
						if (tempplace != sen[CountS].len)
						{
							if (tolow(sen[CountS].sen[tempplace]) >= 97 && tolow(sen[CountS].sen[tempplace]) <= 122)
							{
								break;
							}
							if (tempplace == sen[CountS].len - 1)
							{
								break;
							}
						}
						else
						{
							break;
						}
					}
				}
			}
		}
		else
		{
			sen[CountS].num = 0;
		}
		t[CountS].num = sen[CountS].num;
		t[CountS].pla = CountS;
	}
}

//void merge(int l, int r)
//{
//	if (l >= r) return;
//
//	int mid = (l + r) / 2;
//
//	merge(l, mid), merge(mid + 1, r);
//
//	int k = 0, i = l, j = mid + 1;
//	while (i <= mid && j <= r)
//		if (sen[i].num >= sen[j].num) temp[k++] = sen[i++];
//		else temp[k++] = sen[j++];
//	while (i <= mid) temp[k++] = sen[i++];
//	while (j <= r) temp[k++] = sen[j++];
//	for (i = l, j = 0; i <= r; i++, j++) sen[i] = temp[j];
//}

inline void write(int count)
{
	int temp_pl = 0;
	int i, j;
	for (i = 0; i < count; i++)
	{
		printf("%d ", sen[t[i].pla].num);
		temp_pl = 0;
		while (sen[t[i].pla].sen[temp_pl] == ' ')
		{
			temp_pl++;
		}
		for (j = temp_pl; j < sen[t[i].pla].len; j++)
		{
			printf("%c", sen[t[i].pla].sen[j]);
		}
		printf("\n");
	}
	Res = fopen("results.txt", "w");
	int times = 0;
	for (i = 0; i < N; i++)
	{
		fprintf(Res, "%d", sen[t[i].pla].num);
		//if (i > 0)
		//{
		//	if (sen[i].num == sen[i - 1].num&& strcmp(sen[i].sen, sen[i-1].sen))
		//	{
		//		times++;
		//	}
		//	if (times > 25)//发现最多也就25个句子不同但频度相同
		//	{
		//		fputc('q', Res);
		//	}
		//}
		//if (sen[i].num > 300000) //发现最多频度不过300000
		//{
		//	fputc(' ', Res);
		//}
		//if (sen[i].num < 50000) //发现最少频度大于50000
		//{
		//	fputc(' ', Res);
		//}
		fputc(' ', Res);
		temp_pl = 0;
		while (sen[t[i].pla].sen[temp_pl] == ' ')
		{
			temp_pl++;
		}
		for (j = temp_pl; j < sen[t[i].pla].len; j++)
		{
			fputc(sen[t[i].pla].sen[j], Res);
		}
		fputc('\n', Res);
	}
	fclose(Res);
}

int main()
{
	//scanf("%d", &N);//0.005s
	N = 1000;
	link* LinkCipher = (link*)malloc(sizeof(link));
	int i;
	for (i = 0; i < 26; i++)
	{
		LinkCipher->next[i] = NULL;
	}

	LinkCipher = CreatLink(); //0.40s

	LinkCipher = FixLink(LinkCipher); //几乎无影响

	CountZero(LinkCipher, 21);//几乎无影响

	//merge(0, SenPla - 1);//0.90s

	radixSort_upper(SenPla);

	write(5);//几乎无影响

	return 0;
}