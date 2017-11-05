
#include <cstdio>
#define NUM3



#ifdef NUM3
#include <string.h>
int get_next(int x)
{
	char temp;
	char s[5];
	int a, b, n;
	n = 4;
	sprintf(s, "%d", x);
	for(int i = 0; i < n-1; i++)
	{
		for(int j = 0; j  < n-1-i; j++)
		{
			if(s[j] > s[j+1])
			{
				temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			}
		}
	}
	sscanf(s, "%d", &a);
	for(int i = 0; i < n/2; i++)
	{
		temp = s[i];
		s[i] = s[n-1-i];
		s[n-1-i] = temp;
	}
	sscanf(s, "%d", &b);
	return b - a;
}

int main()
{
		
	int num;
	while(scanf("%d", &num) != EOF)
	{
		int ans = num;
		printf("%d->", num);
		while(get_next(ans) != 6174)
		{
			ans = get_next(ans);
			printf("%d->", ans);
		}
		printf("%d",get_next(ans));
	}
	scanf("%d", &num);
	printf("%d\n", get_next(num));
	return 0;
}
#endif

/*************************************/
//WERYU
//输入：任意字符串
//输出：键盘上该字符左边的字符
/*************************************/
#ifdef NUM2
char *s = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
int main()
{
	using namespace std;
	int i, c;
	while((c = getchar()) != EOF)
	{
		for(i = 1; s[i] && s[i] != c; i++);
			if(s[i])
				getchar(s[i-1]);
			else
				getchar(c);
	}
	return 0;
}
#endif

/*************************************/
//最长回文子串
//输入：带标点的字符串
//输出：原串中的最长回文子串
//		最长回文子串的长度
/*************************************/
#ifdef NUM1

#include <cstring>
#include <ctype.h>

const int MAXN = 5000;

int main()
{
	char buf[MAXN];
	char str[MAXN];
	int p[MAXN];
	fgets(buf, MAXN, stdin);
	int j = 0;
	for(int i = 0; i < strlen(buf); i++)
	{
		if (isalpha(buf[i]))
		{
			p[j] = i;
			str[j++] = toupper(buf[i]);
		}
	}
	str[j] = '\0';
	int max = 0;
	int x, y;
	for(int i = 0; i < strlen(str); i++)
	{
		for(int j = i; j < strlen(str); j++)
		{
			int ok = 1;
			for(int k = i; k < j; k++)
			{
				if(str[k] != str[i+j-k])
					ok = 0;
			}
			if(ok && j-i+1 > max)
			{
				max = j-i+1;
				x = p[i];
				y = p[j];
			}
		}
	}
	for(int i = x; i <= y; i++)
		printf("%c", buf[i]);
	printf("\n");
	printf("%d\n", max);
	return 0;
}
#endif
