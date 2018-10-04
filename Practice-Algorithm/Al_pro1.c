#include <stdio.h>
#include <string.h>
const int MAXN = 1000;

#define NUM6
//7.2.2
#ifdef NUM6
int P[100], A[100];

// Êä³öÊý×éPÖÐÔªËØµÄÈ«ÅÅÁÐ¡£Êý×éPÖÐ¿ÉÄÜÓÐÖØ¸´ÔªËØ
void print_permutation(int n, int* P, int* A, int cur) {
  int i, j;
  if(cur == n) {
    for(i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");
  } else for(i = 0; i < n; i++) if(!i || P[i] != P[i-1]) {
    int c1 = 0, c2 = 0;
    for(j = 0; j < cur; j++) if(A[j] == P[i]) c1++;
    for(j = 0; j < n; j++) if(P[i] == P[j]) c2++;
    if(c1 < c2) {
      A[cur] = P[i];
      print_permutation(n, P, A, cur+1);
    }   
  }
}

int main() {
  int i, n;
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &P[i]);
  print_permutation(n, P, A, 0); 
  return 0;
}

#endif
//7.2.1
#ifdef NUM5
int A[100];

// Êä³ö1~nµÄÈ«ÅÅÁÐ
void print_permutation(int n, int* A, int cur) {
  int i, j;
  if(cur == n) { // µÝ¹é±ß½ç
    for(i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");
  } else for(i = 1; i <= n; i++) { // ³¢ÊÔÔÚA[cur]ÖÐÌî¸÷ÖÖÕûÊýi
    int ok = 1;
    for(j = 0; j < cur; j++)
      if(A[j] == i) ok = 0; // Èç¹ûiÒÑ¾­ÔÚA[0]~A[cur-1]³öÏÖ¹ý£¬Ôò²»ÄÜÔÙÑ¡
    if(ok) {
      A[cur] = i;
      print_permutation(n, A, cur+1); // µÝ¹éµ÷ÓÃ
    }   
  }
}

int main() {
  print_permutation(4, A, 0); 
  return 0;
}

#endif

//6.4.1
#ifdef NUM4
int mat[MAXN][MAXN],vis[MAXN][MAXN];
void dfs(int x,int y)
{
	if(vis[x][y] || !mat[x][y] )
		return;
	vis[x][y] = 1;
	dfs(x-1,y-1);dfs(x-1,y);dfs(x-1,y+1);
	dfs(x,y-1);              dfs(x,y+1);
	dfs(x+1,y-1);dfs(x+1,y);dfs(x+1,y+1);
}
int main()
{
	int n;
	scanf("%d",&n);
	memset(mat,0,sizeof(mat));
	memset(vis,0,sizeof(vis));
	for(int i = 1; i<=n; i++)
	{	
		char s[1000];
		scanf("%s",s);
		for(int j = 0; j<n;j++)
		{
			mat[i][j+1] = s[j]-'0';
		}		
	}
	int count=0;
	for(int i = 1; i<=n;i++)
	{
		for(int j =1;j<=n;j++)
		{
			if(!vis[i][j]&&mat[i][j])
			{
				count++;
				dfs(i,j);
			}
		}
	}
	printf("%d\n",count);
	return 0;
}


#endif

#ifdef NUM3
//6.3.3
void build(int n,char *s1,char *s2,char *s)
{
	if(n <= 0)
		return;
	int p = strchr(s2,s1[0]) - s2;//xaingduiweizhi
	build(p, s1+1,s2,s);
	build(n-p-1,s1+p+1,s2+p+1,s+p);
	s[n-1] = s1[0];
}
int main()
{
	char s1[30],s2[30],s3[30];
	while(scanf("%s%s",s1,s2)==2)
	{
		int n = strlen(s1);
		build(n,s1,s2,s3);
		s3[n] = '\n';
		printf("%s\n",s3);
	}
	return 0;
}

#endif

#ifdef NUM2
//6.3.1
const int MAX=20;
int s[1<<MAX];
int main()
{
	int D,I;
	while(scanf("%d %d",&D,&I))
	{
		int res = 1;
		memset(s,0,sizeof(s));
		for(int j = 1;j <= I;j++)
		{
			for(int i=1;i <=(1<<D)-1;)
			{
				if(i > ((1<<D)-1))
					break;
				res = i;
				if(s[i] == 0)
				{
					s[i] = 1;
					i = 2*i;
				}
				else
				{
					s[i] = 0;
					i = 2*i + 1;
				}
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
#endif
//6.2.1
/*
#ifdef NUM1
struct Node
{
	int num;
	struct Node *next;
}List[500000];

int main()
{
	int n,m;
	while( scanf("%d %d", &n ,&m) )
	{
		char cmd[10]={'0'};
		int sour[100000],dest[100000];
		char ming[100000];
		
		for(int i = 1; i <=m ; i++)
		{
			scanf("%s%d%d",cmd,&sour[i],&dest[i]);
			ming[i] = cmd;
		}
		for(int i =1 ; i <= n; i++)
		{
			List[i].num = i;
			if(i == n)
				List[i].next = NULL;
			else
				List[i].next = &List[i+1].num；
		}
		for(int i = 1; i <= m; i++)
		{
			if( ming[i] == 'A')
			{
				int *front,*back;
				for(int j = 1; j <= n; j++)
				{
					
				}
			}
		}
	}
	return 0;
}
#endif
*/
