#include <cstdio>
#include <queue>
#include <stdlib.h>
#include <stack>
#include <algorithm>
#include <list>
using namespace std;
const int INF = 1000000000;
const int MAXN = 1000;
const int MAXM = 100000;
const int MAX = 1000;

#define NUM37
//11.3.4
//not  finish
#ifdef NUM39
int s,t,n,m,ans;
int cap[MAXN][MAXM],flow[MAXN][MAXM],res[MAXN][MAXM];
int p[MAXN],a[MAXN];
int main()
{
	scanf("%d %d",&n,&m);
	memset(cap,0,sizeof(cap));
	for(int i = 0; i < m; i++)//get graph and cap
	{
		int u,v,c;
		scanf("%d %d %d",&u,&v,&c);
		cap[u][v] = c;
	}
	memset(flow,0,sizeof(flow));
	s = 0;
	t = n - 1;
	ans = 0;

	queue<int> q;
	for(;;)
	{
		memset(a,0,sizeof(a));
		a[s] = INF;
		q.push(0);
		
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
		
			for(int v = 0; v < n; v++)//find connected edge
			{//未被访问
				if(!a[v] && cap[u][v] > flow[u][v])
				{
					p[v] = u;//father node 
					q.push(v);
					if(a[u] > cap[u][v] - flow[u][v])
						a[v] = cap[u][v] - flow[u][v];
					else
						a[v] = a[u];
				}
			}
		}
		if(a[t] == 0)
			break;
		for(int u = t; u != s; u = p[u])
		{
			flow[p[u]][u] += a[t];
			flow[u][p[u]] -= a[t];
		}
		ans += a[t];
	}
	printf("%d\n",ans);
}
#endif
#ifdef NUM38
int main()
{
	queue<int> q;
	int d[MAXN];
	memset(flow,0,sizeof(flow));
	c = f = 0;
	for(;;)
	{
		//bellman ford begin
		bool inq[MAXN];
		for(int i = 0; i < n; i++)
			d[i] = (i == s ? 0 : INF);
		memset(inq,0,sizeof(inq));
		q.push(s);
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			inq[u] = false;
			for(int v = 0; v < n; v++)
				if(cap[u][v] > flow[u][v] && d[v] > d[u] + cost[u][v])
				{
					d[v] = d[u] + cost[u][v];
					p[v] = u;
					if(!inq[v])
					{
						inq[v] = true;
						q.push(v);
					}
				}
		}
		//bellman ford end
		if(d[t] == INF)
			break;
		int a = INF;
		for(int u = t; u != s; u =p[u])
			if(a > cap[p[u]][u] - flow[p[u]][u])
				a = cap[p[u]][u] - flow[p[u]][u];
		for(int u = t; u != s; u = p[u])
		{
			flow[p[u]][u] += a;
			flow[u][p[u]] -= a
		}
		c += d[t] * a;
		f += a;
	}
	return 0;
}
#endif
//home_work 5(2) 2
#ifdef NUM37
int m,n,k;
int G[MAXN][MAXN],s[MAX],f[MAX][MAXN];
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	memset(G,0,sizeof(G));//fill the non-edge position 0
	for(int i = 0; i < m; i++)
	{
		int u,v,o;
		scanf("%d %d %d",&u,&v,&o);
		G[u][v] = o;
	}
	memset(s,0,sizeof(s));
	for(int i = 1; i <= k; i++)
	{
		scanf("%d",&s[i]);	
	}
	//end of input ,begin OPT
	memset(f,0,sizeof(f));
	f[0][0] = 1;
	int u,out_flag = 1;
	for(int i = 1; i <= k; i++)
	{	
		int flag = 0;
		for(int x = 0; x < n; x++)
		{
			if(f[i-1][x] == 1)
			{
				u = x;
				flag = 1;
				for(int j = 0; j < n; j++)
				{
					if(G[u][j] != 0 && s[i] == G[u][j])
					{
						f[i][j] = 1;
					}
				}
			}
		}
		out_flag = flag;
		if(flag == 0)
			break;
	}
	//return
	if(out_flag == 0)
		printf("NO-SUCH-PATH\n");	
	else
		printf("EXIST S\n");
	for(int i = 0; i <= k; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%d ",f[i][j]);
		printf("\n");
	}
	return 0;
}
#endif
//Bellmanford netflow
#ifdef NUM36
int n,m;
int s,t,c,f;
int p[MAXN];
int cap[MAXN][MAXN],flow[MAXN][MAXN],cost[MAXN][MAXN];
int main()
{
	memset(cap,0,sizeof(cap));
	memset(flow,0,sizeof(flow));
	memset(cost,0,sizeof(cost));
	scanf("%d%d",&n,&m);
	for(int i = 0; i < m; i++)
	{
		int u,v,c;
		scanf("%d %d %d",&u,&v,&c);
		cap[u][v] = c;
	}

	queue<int> q;
	int d[MAXN];
	memset(flow,0,sizeof(flow));
	c = f = 0;
	s = 0;
	for(;;)
	{
		bool inq[MAXN];
		for(int i = 0; i < n; i++)
			d[i] = (i == s ? 0 : INF);
		memset(inq,0,sizeof(inq));
		q.push(s);
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			inq[u] = false;
			for(int v = 0; v < n; v++)
				if(cap[u][v] > flow[u][v] && d[v] > d[u] + cost[u][v])
				{
					d[v] = d[u] + cost[u][v];
					p[v] = u;
					if(!inq[v])
					{
						inq[v] = true;
						q.push(v);
					}
				}
		}

		if(d[t] == INF)
			break;
		int a = INF;
		for(int u = t; u != s; u = p[u])
		{
			if(a > cap[u][u] - flow[p[u]][u])
				a = cap[u][u] - flow[p[u]][u];
		}
		for(int u = t; u != s; u = p[u])
		{
			flow[p[u]][u] += a;
			flow[u][p[u]] -= a;
		}
		c += d[t]*a;
		f += a;
	}
	printf("%d\n ",f);
	return 0;
}
#endif

//Ford-fulkson DFS
#ifdef NUM35
int n, m, s, t;
int vis[MAXN], p[MAXN], cap[MAXN][MAXN], flow[MAXN][MAXN];

int path(int u)//DFS
{ 
    int d;
  	vis[u] = 1;
  	if(u == t) //访问到t
		return INF;
  	else 
		for(int v = 0; v < n; v++)
    		if(!vis[v] && cap[u][v]>flow[u][v] && (d = path(v)) > 0)
			{ //没有访问过，且存在边,且容量大于流量，且最少的容量大于0
      			p[v] = u;//U的父亲
				if(d > cap[u][v] - flow[u][v])
					d = cap[u][v] - flow[u][v];
	      		return d;//剩余容量最少的
  			}
  	return 0;
}

int main() 
{
    scanf("%d%d", &n, &m);
  	memset(cap, 0, sizeof(cap));
  	memset(flow, 0, sizeof(flow));
  	for(int i = 0; i < m; i++) 
	{
    	int u, v, c;
    	scanf("%d%d%d", &u, &v, &c);
    	cap[u][v] = c;
  	}
  	s = 0;
  	t = n-1;
	int ans = 0;
  	for(;;) //直到增广路径不存在
	{
    	memset(vis, 0, sizeof(vis));//释放访问标记
    	int d = path(s);//找一条增广路径
    	if(d == 0) //如果增广路径不存在，退出
			break;
    	for(int u = t; u != s; u = p[u])//处理剩余图,从t到s 
		{
      		flow[p[u]][u] += d;//后向流
      		flow[u][p[u]] -= d;//前向流  有些问题
    	};
    	ans += d;//最大流
  	}
  	printf("%d\n", ans);
  	return 0;
}

#endif
//11.3.2 Edmonds-Karp BFS
#ifdef NUM34
int n, m, s, t;
int a[MAXN], p[MAXN], cap[MAXN][MAXN], flow[MAXN][MAXN];

int main() 
{
    scanf("%d%d", &n, &m);
  	memset(cap, 0, sizeof(cap));
  	for(int i = 0; i < m; i++) 
	{
    	int u, v, c;
    	scanf("%d%d%d", &u, &v, &c);
    	cap[u][v] = c;
  	}
  	s = 0;
  	t = n-1;
  	int ans = 0;

  	queue<int> q;
  	memset(flow, 0, sizeof(flow));
  	for(;;) //直到找不到增广路径
	{
		//找一个增广路径
    	memset(a, 0, sizeof(a));//
    	a[s] = INF;//
    	q.push(s);//起点入队列
    	while(!q.empty()) //找一条增广路径
		{
      		int u = q.front();
			q.pop();
      		for(int v = 0; v < n; v++) //所有关联的边
				if(!a[v] && cap[u][v] > flow[u][v])
				{//未访问，且存在边，且容量大于流量
        			p[v] = u;//u是v的父节点，存储路径
					q.push(v);
					//用a表示每个节点的最小残量
					if(a[u] > cap[u][v] - flow[u][v])
        				a[v] = cap[u][v] - flow[u][v];//最小残量
					else
						a[v] = a[u];
      			}	   
    	}   
    	if(a[t] == 0)//不存在增广路径 
			break;
    	for(int u = t; u != s; u = p[u]) 
		{
      		flow[p[u]][u] += a[t];//前向流
      		flow[u][p[u]] -= a[t];
    	}
    	ans += a[t];
  	}

  	printf("%d\n", ans);
  	return 0;
}
#endif
//Floyd
#ifdef NUM33
int n,m;
int u[MAXM],v[MAXM],w[MAXM];
int d[MAXN][MAXN];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{	
			if(i == j)
				d[i][j] = 0;
			else
				d[i][j] = INF;
		}
	 for(int i = 0; i < m; i++)
	 {
	 	int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		d[x][y] = d[y][x] = z;
	 }
	 for(int i = 0; i < n; i++)
	 	for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
			{
				if(d[i][k] >= d[i][j] + d[j][k])
					d[i][k] = d[i][j] + d[j][k];
			}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			printf("%d to %d : %d\n",i,j,d[i][j]);
	return 0;
}

#endif
//求最短路径
//Bellman-Ford
//实际上算法使用的是SPFA算法
#ifdef NUM32
int n, m;
int first[MAXN], d[MAXN];
int u[MAXM], v[MAXM], w[MAXM], Dnext[MAXM];

int main() 
{
    scanf("%d%d", &n, &m);
  	for(int i = 0; i < n; i++) 
		first[i] = -1; 
  	for(int e = 0; e < m; e++) 
	{
    	scanf("%d%d%d", &u[e], &v[e], &w[e]);
    	Dnext[e] = first[u[e]];//
    	first[u[e]] = e;
  	}

  	queue<int> q;
  	bool inq[MAXN];
  	for(int i = 0; i < n; i++) //节点
		d[i] = (i==0 ? 0 : INF);//除了第一个为0，其他均为无穷大\
		表示到起点的距离
  	memset(inq, 0, sizeof(inq));
  
	q.push(0);//0号节点入栈
  	while(!q.empty()) //栈非空
	{
    	int x = q.front(); 
		q.pop();
    	inq[x] = false;//访问过
    	for(int e = first[x]; e != -1; e = Dnext[e]) 
			if(d[v[e]] > d[x]+w[e]) //得到更小的距离，则更新d值
			{
      			d[v[e]] = d[x] + w[e];//更新d值
      			if(!inq[v[e]]) //如果访问过,再标记，入队列
				{
        			inq[v[e]] = true;
        			q.push(v[e]);
      			}   
    		}   
			//因为Bellman-ford是BFS，一个节点不会多次入队列\
			而这里一个队列能够多次入队列，所以属于SPFA的特性\
			但是，这里并没有从汇点往回进行松弛，严格来说并不\
			SPFA算法
  	}

  	for(int i = 0; i < n; i++)
    	printf("%d\n", d[i]);
  	return 0;
}
#endif
//dijkstra advancy FIFO
#ifdef NUM31
int n, m;
int first[MAXN];
int d[MAXN];
int u[MAXM];
int v[MAXM];
int w[MAXM];
int Dnext[MAXM];

typedef pair<int,int> pii;

int main() 
{
    scanf("%d%d", &n, &m);
  	for(int i = 0; i < n; i++) 
		first[i] = -1;//every node 
  	for(int e = 0; e < m; e++) 
	{
    	scanf("%d%d%d", &u[e], &v[e], &w[e]);
    	Dnext[e] = first[u[e]];
    	first[u[e]] = e;
  	}

  	priority_queue<pii, vector<pii>, greater<pii> > q;
  	bool done[MAXN];
  	for(int i = 0; i < n; i++) 
		d[i] = (i==0 ? 0 : INF);

  	memset(done, 0, sizeof(done));//like v[]
  	q.push(make_pair(d[0], 0));
  	while(!q.empty()) 
	{
    	pii u = q.top(); 
		q.pop();//delete from fifo
    	int x = u.second;
    //	if(done[x]) 
	//		continue;
    //	done[x] = true;
    	for(int e = first[x]; e != -1; e = Dnext[e]) 
			if(d[v[e]] > d[x]+w[e]) //P.S.  v[e] ,connected with u[e]
			{
      			d[v[e]] = d[x] + w[e];//松弛操作
      			q.push(make_pair(d[v[e]], v[e]));
    		}	
  	}

  	for(int i = 0; i < n; i++)
    	printf("%d\n", d[i]);
  	return 0;
}

#endif
//dijsktra
#ifdef NUM30
int n,m;
int first[MAX];
int u[MAX];
int v[MAX];
int w[MAX];
int Dnext[MAX];
void read_graph()
{
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++)
		first[i] = -1;//
	for(int e = 0; e < m; e++)
	{
		scanf("%d %d %d",&u[e],&v[e],&w[e]);
		Dnext[e] = first[u[e]];
		first[u[e]] = e;
		printf("first(%d) = %d,next(%d) = %d\n",u[e],first[u[e]],e,Dnext[e]);
	}
	printf("\n");
}
int main()
{
	read_graph();
	for(int i = 0; i < n; i++)
		printf("%d\n",first[i]);
	printf("\n");
	for(int i = 0; i < m; i++)
		printf("%d\n",Dnext[i]);
	return 0;
}
#endif
//dijkstra self
#ifdef NUM29
int n,m;
int v[MAX];
int d[MAX];
int G[MAX][MAX];
int main()
{
	scanf("%d %d",&m,&n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			G[i][j] = INF;
	for(int i = 0; i < n; i++)
	{
		int v,u,w;
		scanf("%d %d %d",&v,&u,&w);
		G[v][u] = w;
	}

	memset(v,0,sizeof(v));//
	d[0] = 0;//deal with the source node
	for(int i = 1; i < n; i++)
		d[i] = INF;
	for(int i = 0; i < n; i++)
	{
		printf("node %d\n",i);
		int m = INF;
		int k;
		for(int j = 0; j < n; j++)
		{//greedy to find the closest node
			if(!v[j] && d[j] <= m)
				m = d[k=j];//for k 
		}
		v[k] = 1;
		printf("node %d visited\n",k);
		for(int j = 0; j < n; j++)//所有与该点关联的边的节点的值更新
		{
			if(d[j] >= d[k] + G[k][j])
			{
				d[j] = d[k] + G[k][j];
				printf("change d of node %d to be %d\n",j,d[j]);
			}
		}
	}
	for(int i = 0; i < m; i++)
		printf("%d\n",d[i]);
	return 0;
}
#endif
//11.2.1 dijkstra 
#ifdef NUM28
//const int INF = 1000000000;
//const int MAXN = 1000;

int n, m;
int v[MAXN], d[MAXN], G[MAXN][MAXN];

int main() 
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < n; j++)
        	G[i][j] = INF;
    for(int i = 0; i < m; i++)
    {
   	    int u, v, w;
    	scanf("%d%d%d", &u, &v, &w);
    	G[u][v] = w;
  	}

 	memset(v, 0, sizeof(v));//visit tab -- n nodes 
  	for(int i = 0; i < n; i++) 
		d[i] = (i==0 ? 0 : INF);//the d value is INF
  	for(int i = 0; i < n; i++) //every node
	{
    	int x, m = INF;
    	for(int y = 0; y < n; y++) 
			if(!v[y] && d[y]<=m) //not be visited
				m = d[x=y];//x get the min distance to 0 , node num
    	v[x] = 1;
    	for(int y = 0; y < n; y++)
		{ 
			if(d[y] >= d[x] + G[x][y])
				d[y] = d[x] + G[x][y];
		}
	}
  	for(int i = 0; i < n; i++)
    	printf("%d\n", d[i]);
  	return 0;
}
#endif

//11.1.3  最小生成树
#ifdef NUM27
const int maxi = 1000;
int u[maxi];
int v[maxi];
int w[maxi];
int r[maxi];
int p[maxi];
int n,m;
int cmp(const int i,const int j)
{
	return w[i] < w[j];
}
int Ufind(int x)//find root node
{
	if(p[x] == x)
		return p[x];
	else
		return Ufind(p[x]);
}
int Kruskal()
{
	int ans = 0;
	for(int i = 0; i < n; i++)
		p[i] = i;
	for(int i = 0; i < m; i++)
		r[i] = i;
	sort(r,r+m,cmp);
	for(int i = 0; i < m; i++)
	{
		int e = r[i];
		int x = Ufind(u[e]);
		int y = Ufind(v[e]);
		if(x != y)
		{
			ans += w[e];//sum of weight
			p[x] = y;//union
		}
		return ans;
	}
}
int main()
{
	int ans;
	scanf("%d %d",&n,&m);
	for(int i = 0; i < m; i++)
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
	ans = Kruskal();
	printf("%d\n", ans);
	return 0;
}
#endif
//11.1.1  
#ifdef NUM26
const int maxn = 1000;
int p[1000];
int n;
vector<int> G[maxn];
void read_tree()
{
	int u,v;
	scanf("%d",&n);
	for(int i = 0; i < n-1; i++)
	{
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
}
void dfs(int u,int fa)
{
	int d = G[u].size();
	for(int i = 0; i < d; i++)
	{
		int v = G[u][i];
		if(v != fa)
			dfs(v,p[v] = u);
	}
}
int main()
{
	int root;
	read_tree();
	root = 1;
	p[root] = -1;
	dfs(root,-1);
	for(int i = 0; i < n; i++)
		printf("%d\n",p[i]);
	return 0;
}

#endif

#ifdef NUM25
//9.3.3  滚动数组
#define MAXN 1000
#define MAXC 100000
int V[MAXN], W[MAXN];
int d[MAXC];
int main()
{
    int n, C;
	scanf("%d %d",&n, &C);
    for(int i = 1; i <= n; i++)
    	scanf("%d %d", &V[i], &W[i]);
	memset(d,0,sizeof(d));
    for(int i = 1; i <= n; i++)
    	for(int j = C; j >= 0; j--) 
		{
			d[j] = (i == 1 ? 0 : d[j]);
			if(j >= W[i])
			{
				if(d[j] <= d[j-W[i]] + V[i])
					d[j] = d[j-W[i]] + V[i];
			}
		}   
  
  	printf("%d\n", d[C]);
  	for(int j = 0; j <= C; j++)
		printf("%d ",d[j]);	
	printf("\n");
  	return 0;
}


#endif
//9.3.1   0-1 package update from head
#ifdef NUM24
#define MAXN 1000
#define MAXC 100000
int V[MAXN], W[MAXN];
int d[MAXN][MAXC];
int main()
{
    int n, C;
	scanf("%d %d",&n, &C);
    for(int i = 1; i <= n; i++)
    	scanf("%d %d", &V[i], &W[i]);
	memset(d,0,sizeof(d));
    for(int i = 1; i <= n; i++)
    	for(int j = 0; j <= C; j++) 
		{
			d[i][j] = (i == 1 ? 0 : d[i-1][j]);
			if(j >= W[i])
			{
				if(d[i][j] <= d[i-1][j-W[i]] + V[i])
					d[i][j] = d[i-1][j-W[i]] + V[i];
			}
		}   
  
  	printf("%d\n", d[n][C]);
  	for(int i = 1; i <= n; i++)
  	{
  		for(int j = 0; j <= C; j++)
			printf("%d ",d[i][j]);	
  		printf("\n");
	}
	for(int i = 1; i <= n; i++)
	{
		if(d[i][C] == d[i+1][C-W[i]] + V[i])
		{
			printf("V = %d W = %d\n",V[i],W[i]);
			C = C - W[i];
		}
	}
	printf("\n");
  	return 0;
}


#endif
//9.3.1   0-1 package update from end
#ifdef NUM23
#define MAXN 1000
#define MAXC 100000
int V[MAXN], W[MAXN];
int d[MAXN][MAXC];
int main()
{
    int n, C;
	scanf("%d %d",&n, &C);
    for(int i = 1; i <= n; i++)
    	scanf("%d %d", &V[i], &W[i]);
	memset(d,0,sizeof(d));
    for(int i = n; i >= 1; i--)
    	for(int j = 0; j <= C; j++) 
		{
			if(i == n)
			{
				if(j >= W[i])
					d[i][j] = V[i];
			}
			else
			{
				d[i][j] = d[i+1][j];
				if(j >= W[i])
				{
					if(d[i][j] <= d[i+1][j-W[i]]+V[i])
						d[i][j] = d[i+1][j-W[i]]+V[i];
				}
			}
		}   
  
  	printf("%d\n", d[1][C]);
  	for(int i = 1; i <= n; i++)
  	{
  		for(int j = 0; j <= C; j++)
			printf("%d ",d[i][j]);	
  		printf("\n");
	}
	for(int i = 1; i <= n; i++)
	{
		if(d[i][C] == d[i+1][C-W[i]] + V[i])
		{
			printf("V = %d W = %d\n",V[i],W[i]);
			C = C - W[i];
		}
	}
	printf("\n");
  	return 0;
}

#endif
//9.3.1   complete package
#ifdef NUM22
const int MAX = 1000;
int V[MAX], W[MAX],d[MAX];
int main()
{
	int n,C;
	scanf("%d %d",&n,&C);
	for(int i = 1; i <= n; i++)
		scanf("%d %d",&V[i],&W[i]);

	for(int i = 1; i <= C; i++)//d[C] to note
	//update from front to end
		for(int j = 1; j <= n; j++)
			if(i >= W[j])
			{
				if(d[i] <= d[i-W[j]] + V[j])
					d[i] = d[i-W[j]] + V[j];
			}
	printf("%d",d[C]);
	printf("\n");
	for(int i = 1; i <= n; i++)
		if(d[C] == d[C-W[i]] + V[i])
		{
			printf("V = %d; W = %d\n",V[i],W[i]);
			C = C - W[i];
			i = 1;
		}
	return 0;
}
#endif

//9.2.3  coins 
#ifdef NUM21
#define INF -1000000000
#define INFL 1000000000
const int MAX = 1000;
int M_A_X[MAX],M_I_N[MAX];//note
int V[MAX];
int max_coin[MAX],min_coin[MAX];
int n,S;
void print_ans(int* d,int S)
{
	for(int i = 1; i <= n; i++)
		if(d[S] == d[S-V[i]] + 1)
		{
			printf("V_%d:%d ", i, V[i]);
			S = S - V[i];
		}
}
void print_ans_1(int* d,int S)
{
	while(S)
	{
		printf("%d ", d[S]);
		S -= V[d[S]];
	}
}
int main()
{
	scanf("%d %d",&n,&S);
	for(int i = 1; i <= n; i++)
		scanf("%d",&V[i]);
	
	M_A_X[0] = M_I_N[0] = 0;
	for(int i = 1; i <= S; i++)
	{
		M_A_X[i] = INF;
		M_I_N[i] = INFL;
	}
	for(int i = 1; i <= S; i++)
		for(int j = 1; j <= n; j++)
			if(i >= V[j])
			{
				if(M_A_X[i] <= M_A_X[i-V[j]] + 1)
				{
					M_A_X[i] = M_A_X[i-V[j]] + 1;
					max_coin[i] = j;
				}
				if(M_I_N[i] >= M_I_N[i-V[j]] + 1)
				{
					M_I_N[i] = M_I_N[i-V[j]] + 1;
					min_coin[i] = j;
				}
			}
	printf("M_I_N = %d\n",M_I_N[S]);
	print_ans(M_I_N, S);
	printf("\n\n");
	printf("M_A_X = %d\n",M_A_X[S]);
	print_ans(M_A_X,S);
	printf("\n");
	printf("\n");
	print_ans_1(min_coin,S);
	printf("\n");
	print_ans_1(max_coin,S);
	printf("\n");
	return 0;
}
#endif

//9.2.1 coin problem selffirst
#ifdef NUM20
#define MAXIMUM 1000000000
#define MINIMUM -1000000000
const int MAX = 1000;
int n,S;
int V[MAX];
int d[MAX][MAX];//note 2 dimension,x = S, y = n
int Max_dp(int i,int v)
{
	int& ans = d[i][v];
	if(v == 0)
		return 0;
	if(v < 0)
		return MINIMUM;
	if(ans > 0)
		return ans;
	else
	{
		int temp_1,temp_2;
		temp_1 = Max_dp(i-1,v);
		temp_2 = Max_dp(i,v-V[i]) + 1;
		if(temp_1 >= temp_2)
			ans = temp_1;
		else
			ans = temp_2;
		return ans;
	}
}


int Min_dp(int i,int v)
{
	int& ans = d[i][v];
	if(v == 0)
		return ans;
	if(v < 0)
		return MAXIMUM;
	if(ans > 0)
		return ans;
	else
	{
		int temp_1,temp_2;
		temp_1 = Min_dp(i-1,v);
		temp_2 = Min_dp(i,v-V[i]) + 1;
		if(temp_1 <= temp_2)
			ans = temp_1;
		else
			ans = temp_2;
		return ans;
	}
}
void print_ans(int i,int v)
{
	if(v - V[i]>=0)
	{
		if(d[i][v]  == d[i][v-V[i]] + 1)
		{
			printf("V_%d: %d\n", i, V[i] );
			print_ans(i,v-V[i]);
		}
		else
			if(d[i][v] == d[i-1][v])
				print_ans(i-1,v);
	}
	else
		print_ans(i-1,v);
}

int main()
{
	int max,min;
	scanf("%d %d",&n,&S);
	for(int i = 1; i <= n; i++)
		scanf("%d", &V[i]);
	sort(V+1,V+n);
	
	memset(d,0,sizeof(d));//0
	for(int i = 1; i <= S; i++)
		d[0][i] = MAXIMUM;//OPT(0,v) = MAXIMUM
	min = Min_dp(n,S);
	printf("min = %d\n",min);
	print_ans(n,S);	

	printf("\n");
	memset(d,0,sizeof(d));//0
	for(int i = 1; i <= S; i++)
		d[0][i] = MINIMUM;//OPT(0,v) = MINIMUM
	max = Max_dp(n,S);
	printf("max = %d\n",max);
	print_ans(n,S);
	//for(int i = 1; i <= n; i++)
	//	printf("%d ",V[i]);
	printf("\n");
	return 0;
}
#endif

#ifdef NUM19
const int MAX = 1000;
int n;
int G[MAX][MAX],X[MAX],Y[MAX],d[MAX];
int Dp(int i)
{
	int& ans = d[i];
	if(ans > 0)
		return ans;
	ans = 1;//if i do not have sub
	for(int j = 1; j <= n; j++)
		if(G[i][j])
		{
			int temp;
			temp = Dp(j) + 1;
			if(ans < temp)//get the largest value
				ans = temp;
		}
	return ans;
}
void print_ans(int i)
{
	printf("%d ",i);
	for(int j = 1; j <= n; j++)
		if(G[i][j] && d[i] == d[j] + 1)
		{
			print_ans(j);
			break;
		}
}


int main()
{
	int ans,best;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d %d",&X[i],&Y[i]);
		if(X[i] > Y[i])
		{
			int temp;
			temp = X[i];
			X[i] = Y[i];
			Y[i] = temp;
		}
	}
	memset(G,0,sizeof(G));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(X[i] < X[j] && Y[i] < Y[j])
				G[i][j]  = 1;
	ans = 0;
	for(int i = 1; i <= n; i++)
		if(ans < Dp(i))
		{
			best = i;
			ans = Dp(i);//
		}
	printf("%d\n",ans);
	print_ans(best);
	printf("\n");
	return 0;
}
#endif

#ifdef NUM18
#define MAXN 1010
int n, G[MAXN][MAXN];//
int x[MAXN], y[MAXN], d[MAXN];

int dp(int i) {// one time only one source, i -> n
  int& ans = d[i];//d[] is a note
  if(ans > 0) 
	return ans;//if visited
  ans = 1;//dont know why ,maybe can be ignored
  for(int j = 1; j <= n; j++) 
	if(G[i][j]) // if has a path i -> j
	{
		int temp = dp(j) + 1;
		if(ans < temp)
			ans = temp;
	}
  return ans;
}
//print huisu
void print_ans(int i) {
  printf("%d ", i);
  for(int j = 1; j <= n; j++) 
  	if(G[i][j] && d[i] == d[j]+1) 
	{
    	print_ans(j);
    	break;
  	}
}

int main() {
  int i, j, ans, best;
  scanf("%d", &n);
  for(i = 1; i <= n; i++) {
    scanf("%d%d", &x[i], &y[i]);
    if(x[i] > y[i]) {
      int t = x[i]; x[i] = y[i]; y[i] = t;//x for small,y for large
    }
  }
  memset(G, 0, sizeof(G));//G
  memset(d,0,sizeof(d));//
  for(i = 1; i <= n; i++)
    for(j = 1; j <= n; j++)
      if(x[i] < x[j] && y[i] < y[j]) 
		G[i][j] = 1;//if i<j, G[i][j] = 1,means i->j,

  ans = 0;
  for(i = 1; i <= n; i++)//every i can be the source
    if(dp(i) > ans) {
      best = i;
      ans = dp(i);
    }
  printf("%d\n", ans);
  print_ans(best);//get the path
  printf("\n");
  return 0;
}

#endif

//9.1.1 Dynamic 3 : note
#ifdef NUM17
int solve(int a[5][5],int d[5][5],int i,int j,int n)
{
	if(i == n)
		return a[i][j];
	else
	{
		if(d[i][j]>=0)
			return d[i][j];
		else
		{
			int temp_1,temp_2;
			temp_1 = solve(a,d,i+1,j,4);
			temp_2 = solve(a,d,i+1,j+1,4);
			return d[i][j] = a[i][j] + (temp_1 >= temp_2 ? temp_1 : temp_2);
		}
	}
}
int main()
{
    int n;
    int a[5][5];
    int d[5][5];

	memset(d,-1,sizeof(d));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            scanf("%d",&a[i][j]);
    printf("OPT = %d\n",solve(a,d,1,1,4));
}
		
#endif

#ifdef NUM16
//9.1.1 Dynamic 2 : from down to up
int max(int a,int b)
{
	return a >= b ? a : b;
}
int main()
{
    int n;
    int a[5][5];
	int d[5][5];
	scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            scanf("%d",&a[i][j]);

	for(int j=1;j<=n;j++)
		d[n][j] = a[n][j];
	for(int i=n-1;i>=1;i--)
		for(int j=1;j<=i;j++)
			d[i][j] = a[i][j] + max(d[i+1][j],d[i+1][j+1]);	

    printf("OPT = %d\n",d[1][1]);
}
#endif

//9.1.1 Dynamic 1
#ifdef NUM15
int max(int a,int b)
{
	return a >= b ? a : b;
}
int d(int a[5][5],int i,int j,int n)
{
	if(i == n)
		return a[i][j];
	else
	{
		int temp_1,temp_2;
		temp_1 = d(a,i+1,j,n);
		temp_2 = d(a,i+1,j+1,n);
		return a[i][j] + max(temp_1,temp_2);
	}
}
int main()
{
	int n;
	int a[5][5];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			scanf("%d",&a[i][j]);
	printf("OPT = %d\n",d(a,1,1,n));
}
#endif
//8.4
#ifdef NUM13
int main()
{
	int n,C;

	while(scanf("%d %d",&n,&C) == 2)
	{
		int w[100];
		for(int i=1;i<=n;i++)
			scanf("%d",&w[i]);
		int count=0;
		int sum = 0;
		sort(w+1,w+n);
		for(int i=1;i<=n&&sum<=C;i++)
		{
			sum = sum + w[i];
			if(sum<=C)
				count++;
		}
		printf("count = %d\n",count);
			
	}
	return 0;
}
#endif

//8.3.2
#ifdef NUM12
void Design_Sch(int* A,int n,int a,int b)//a:hang;;b:lie
{

	int m = b/2;
	if(m == 0)
		return;
	else
	{
		int x,y;
		x = (a+b)/2;
		y = x - a;//hang shu
		Design_Sch(A,n,a,m);
	    Design_Sch(A,n,a+y+1,m);
		for(int j=a;j<=a+y;j++)//left down -> right up
			for(int i=m+1;i<=m+1+y;i++)
				A[j*n+i] = A[(j+y+1)*n+i-y-1];
		for(int j=a+y+1;j<=a+y+1+y;j++)//left up -> right down
			for(int i=y+1;i<=m+1+y;i++)
				A[j*n+i] = A[(j-y-1)*n+i-y-1];
		return;
	}	
}
int main()
{
	int num[8][8];
	int T[64];
    int n;

	memset(num,0,sizeof(num));
    scanf("%d",&n);// n = 2^k
    for(int i=0;i < n;i++)
        num[i][0] = i+1;
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			T[i*8+j] = num[i][j];
	Design_Sch(T,8,0,n-1);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",T[i*8+j]);
		printf("\n");
	}
	printf("\n");
    return 0;
}

#endif

//binary search
#ifdef NUM10
int BSearch(int p,int q,int v,int* A)
{
	if(p>q)
		return -1;
	else
	{
		int m;
		m = (p+q)/2;
		if(v == A[m])
			return m;
		else
		{
			if(v < A[m])
				return BSearch(p,m-1,v,A);
			else
				return BSearch(m+1,q,v,A);
		}
	}
}
int main()
{
    int num[100];
    int n;
    scanf("%d",&n);
    for(int i=0;i < n;i++)
        scanf("%d",&num[i]);
	printf("Pos = %d",BSearch(0,n-1,5,num));
	printf("\n");
    return 0;
}

#endif

#ifdef NUM9
//8.2.2 Quick sort
int Partition(int p,int q,int* A)
{
	int i,j,x;
	int temp_1;
	x = A[q];
	i = p - 1;
	for(j=p;j<=q-1;j++)
	{
		if(A[j] <= x)
		{
			int temp;
			i = i + 1;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	temp_1 = A[i+1];
	A[i+1] = A[q];
	A[q] = temp_1;
	return i+1;
}

void Quick_Sort(int p,int q,int* A)//p,q is position
{
//	if( p >= q)
//		return;
//	else
	if(p<q)
	{
		int m;
		m = Partition(p,q,A);
		Quick_Sort(p,m-1,A);
		Quick_Sort(m+1,q,A);
		return;
	}
}
int main()
{
    int num[100];
    int n;
    scanf("%d",&n);
    for(int i=0;i < n;i++)
        scanf("%d",&num[i]);
    Quick_Sort(0,n-1,num);
    for(int i = 0;i<n;i++)
        printf("%d ",num[i]);
    printf("\n");
    return 0;
}

#endif
//8-2 ReversePair num
#ifdef NUM8
int Reverse_Num(int p,int q,int* A,int* T)
{
	if(q-p == 1)
		return 0;
	else
	{
		int m,x,y,i;
		int count = 0;
		m = (p+q)/2;
		x = p;
		y = m;
		i = p;
		count = Reverse_Num(p,m,A,T) + Reverse_Num(m,q,A,T);
		while(x < m || y < q)
		{
			if(y>=q || ( x < m && A[x] <= A[y]))
			{
				T[i++] = A[x++];
				count = count + (y - m);
			}
			if(x>=m || ( y < q && A[y] < A[x]))
			{
				T[i++] = A[y++];
			//	if(x<m)
			//		count = count + (y - m);
				
			}
		}
		for(int j=p;j<q;j++)
			A[j] = T[j];
		return count;
	}
}
int main()
{
	int num[100];
    int T[100];
    int n;
	int pair;
    scanf("%d",&n);
    for(int i=0;i < n;i++)
        scanf("%d",&num[i]);
    pair = Reverse_Num(0,n,num,T);
    for(int i = 0;i<n;i++)
        printf("%d ",num[i]);
    printf("\n");
	printf("%d\n",pair);
	return 0;
}
#endif

//prac merge_sort
#ifdef NUM7
void merge_sort(int p,int q,int* A,int* T)
{
	if(q-p>1)//at least 2, q is not used
	{
		int i,m,x,y;
		m = (p+q)/2;
		x = p;
		y = m;
		i = p;
		merge_sort(p,m,A,T);
		merge_sort(m,q,A,T);
		while(x<m || y<q )
		{
			if(y>=q || ( x < m && A[x] <= A[y] ))
				T[p++] = A[x++];
			if(x>=m || ( y < q && A[y] <= A[x]))
				T[p++] = A[y++];
		}
		for(int j=i;j<q;j++)
			A[j] = T[j];
	}
}
int main()
{
	int num[100];
	int T[100];
	int n;
	scanf("%d",&n);
	for(int i=0;i < n;i++)
		scanf("%d",&num[i]);
	merge_sort(0,n,num,T);
	for(int i = 0;i<n;i++)
		printf("%d ",num[i]);
	printf("\n");
	return 0;
}
#endif
//prac qsort
#ifdef NUM6
int comp(const void* x, const void* y)
{
	return *(int*)x - *(int*)y;
}
int main()
{
    int n;
    int num[100];
    while(scanf("%d",&n)==1)
    {   
        for(int i = 0;i < n;i++)
            scanf("%d",&num[i]);
        qsort(num,n,sizeof(int),comp);
        for(int i=0;i<n;i++)
            printf("%d ",num[i]);
        printf("\n");
    }   
}

#endif

//prac sort
#ifdef NUM5
int main()
{
	int n;
	int num[100];
	while(scanf("%d",&n)==1)
	{
		for(int i = 0;i < n;i++)
			scanf("%d",&num[i]);
		sort(num,num+n);
		for(int i=0;i<n;i++)
			printf("%d ",num[i]);
		printf("\n");
	}
}

#endif

//7.2.3
#ifdef NUM4
int main() {
  int n, p[10];
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &p[i]);
  sort(p, p+n); // ÅÅÐò£¬µÃµ½pµÄ×îÐ¡ÅÅÁÐ
  do {
    for(int i = 0; i < n; i++) printf("%d ", p[i]); // Êä³öÅÅÁÐp
    printf("\n");
  } while(next_permutation(p, p+n)); // ÇóÏÂÒ»¸öÅÅÁÐ
  return 0;
}


#endif




#ifdef NUM3
struct command
{
	char cmd;
	int A;
	int B;
};

int main()
{
	int n,m;
	int i;
	int num[500000];
	struct command cmmd[100000];
	while( scanf("%d %d",&n, &m)!= EOF)
	{
		for(i=0;i<n;i++)
		{
			num[i]=i+1;
		}
		for(i = 1;i <= m; i++)
		{
			char tmp[10];
			list<int> llist(num,num+n);
			scanf("%s%d%d",tmp,&cmmd[i].A,&cmmd[i].B);
			cmmd[i].cmd = tmp[0];
		}
		for(i=1;i <= m;i++)
		{
			if(cmmd[i].cmd == 'A')
			{
		
			}
		}
	}
	return 0;
}
#endif 


#ifdef NUM2
const int MAXN = 1000 + 10;
int n,target[MAXN];

int main()
{
	while(scanf("%d",&n) == 1)
	{
		stack<int> s;
		int A = 1, B = 1;
		for(int i = 1; i <=n; i++)
		{
			scanf("%d",&target[i]);
		}
		int ok = 1;
		while(B <= n)
		{
			if(A == target[B])
			{
				A++;
				B++;
			}
			else
			{
				if(!s.empty() && s.top() == target[B])
				{
					s.pop();
					B++;
				}
				else
				{
					if(A <= n)	
						s.push(A++);
					else
					{
						ok=0;
						break;
					}
				}
						
			}
		}
		printf("%s\n",ok?"Yes":"No");
	}
	return 0;
}
#endif

#ifdef NUM1
queue<int> q;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		q.push(i+1);
	while(!q.empty())
	{
		printf("%d ",q.front() );
		q.pop();
		q.push(q.front());
		q.pop();
	}
	return 0;
}
#endif
