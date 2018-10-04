#include <cstdio>
#include <iostream>
#define NUM5
//////////////////////////
//1.5	Piotr's Ants
//answer
//////////////////////////
#ifdef NUM5
#include <algorithm>
using namespace std;
const int maxn = 10000 + 5;
struct Ant
{
	int id;
	int p;
	int d;
	bool operator < (const Ant & a) const
	{
		return p < a.p;
	}
}before[maxn], after[maxn];

const char dirName[][10] = {"L", "Turning", "R"};

int order[maxn];

int main()
{
	int K;
	scanf("%d", &K);
	for(int kase = 0; kase < K; kase++)
	{
		int L, T, n;
		printf("Case #%d:\n", kase);
		scanf("%d%d%d", &L, &T, &n);
		for(int i = 0; i < n; i++)
		{
			int p, d;
			char c;
			scanf("%d %c", &p, &c);
			d = (c == 'L' ? -1 : 1);
			before[i] = (Ant){i, p, d};
			after[i] = (Ant){0, p+T*d, d};
		}

		sort(before, before+n);
		for(int i = 0; i < n; i++)
			order[before[i].id] = i;
		sort(after, after+n);
		for(int i = 0; i < n-1; i++)
			if(after[i].p == after[i+1].p)
				after[i].d = after[i+1].d = 0;
		for(int i = 0; i < n; i++)
		{
			int a = order[i];
			if(after[a].p < 0 || after[a].p > L)
				printf("Fell off\n");
			else
				printf("%d %s\n", after[a].p, dirName[a].d+1);
		}	
		printf("\n");
	}
	return 0;
}

#endif


//////////////////////////
//1.5	Piotr's Ants
//my code
//////////////////////////
#ifdef NUM4
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct Ant
{
	int id;
	int pos;
	char dir;
	int sta;
};

int comp(const void * a, const void * b)
{
	int x = ((Ant*)a)->pos;
	int y = ((Ant*)b)->pos;
	return x - y;
}
int comp_1(const void * a, const void * b)
{
	int x = ((Ant*)a)->id;
	int y = ((Ant*)b)->id;
	return x - y;
}

int main()
{
	int cases;
	cin >> cases;
	while(cases--)
	{
		int L, T, n;
		Ant ants[10000];
		Ant copy[10000];
		cin >> L >> T >> n;
		for(int i = 0; i < n; i++)
		{
			ants[i].id = i;	
			scanf("%d %c", &ants[i].pos, &ants[i].dir);
		}
		memcpy(copy, ants, sizeof(ants));
		qsort(copy, n, sizeof(Ant), comp);
		for(int i = 0; i < n; i++)
		{
			if(ants[i].dir == 'R')
				ants[i].pos += T;
			else
				ants[i].pos -= T;
		}
		qsort(ants, n, sizeof(Ant), comp);
		for(int i = 0; i < n; i++)
		{
			copy[i].pos = ants[i].pos;
			copy[i].dir = ants[i].dir;
		}
		for(int i = 0; i < n; i++)
		{
			//ants[i].dir = copy[i].dir;
			if(i == 0)
			{
				if(copy[i].pos < 0 || copy[i].pos > L)
					copy[i].sta = 0;
				else if(copy[i].pos == copy[i+1].pos)
					copy[i].sta = 1;
				else
					copy[i].sta = 2;
				continue;
			}
			if(i == (n - 1))
			{
				if(copy[i].pos < 0 || copy[i].pos > L)
					copy[i].sta = 0;
				else if(copy[i].pos == copy[i-1].pos)
					copy[i].sta = 1;
				else
					copy[i].sta = 2;
				continue;
			}
			if(copy[i].pos < 0 || copy[i].pos > L)
					copy[i].sta = 0;
			else if(copy[i].pos == copy[i-1].pos 
							|| copy[i].pos == copy[i+1].pos)
				copy[i].sta = 1;
			else
				copy[i].sta = 2;
		}
		qsort(copy, n, sizeof(Ant), comp_1);
		static int num = 0;
		printf("Case #%d: \n", ++num);
		for(int i = 0; i < n; i++)
		{
			switch (copy[i].sta)
			{
				case 0:
					printf("Fell off\n");
					break;
				case 1:
					printf("%d ", copy[i].pos);
					printf("Turning\n");
					break;
				case 2:
					printf("%d %c\n", copy[i].pos, copy[i].dir );
					break;
				default:
					break;
			}
		}
		cout << endl;
	}
	return 0;
}
#endif

//////////////////////////
//1.4	Graveyard
//////////////////////////
#ifdef NUM3
#include <cmath>
using namespace std;
int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) == 2)
	{
		double ans = 0.0;
		for(int i = 1; i < n; i++)
		{
			double pos = (double)i / n * (n+m);
			ans += fabs(pos - floor(pos+0.5)) / (n+m);
		}
		printf("%.4lf\n", ans*10000);
	}
	return 0;
}
#endif

#ifdef NUM2
#include <cmath>
using namespace std;
int main()
{
	cout.precision(4);
	cout.setf(ios::fixed, ios::floatfield);
	int n, m;
	while(scanf("%d %d", &n, &m) == 2)
	{
		double ans = 0.0;
		double init[1000] = {0};
		double last[1000] = {0};
		double cycle_init = 10000.0 / n;
		double cycle_last = 10000.0 / (n+m);
		for(int i = 1; i < (n+m); i++)
			last[i] = last[i-1] + cycle_last;
		for(int i = 1; i < n; i++)
			init[i] = init[i-1] + cycle_init;
		for(int j = 1, i = 1; i < n;)
		{
			if((j+1)*cycle_last >= init[i])
			{
				if(last[j+1] - init[i] >= init[i] - last[j])
					ans += (init[i] - last[j]);
				else
					ans += (last[j+1] - init[i]);
				i++;
				j++;
			}
		}
	}
}
#endif

//////////////////////////
//1.4	Graveyard
//////////////////////////
#ifdef NUM1
#include <cmath>
using namespace std;
int main()
{
	cout.precision(4);
	cout.setf(ios::fixed, ios::floatfield);
	int n, m;
	while(scanf("%d %d", &n, &m) == 2)
	{
		double ans = 0.0;
		double init[1000] = {0};
		double last[1000] = {0};
		double cycle_init = 10000.0 / n;
		double cycle_last = 10000.0 / (n+m);
		for(int i = 1; i < (n+m); i++)
			last[i] = last[i-1] + cycle_last;
		for(int i = 1; i < n; i++)
			init[i] = init[i-1] + cycle_init;
		for(int j = 1, i = 1; i < n;)
		{
			if((j+1)*cycle_last >= init[i])
			{
				if(last[j+1] - init[i] >= init[i] - last[j])
					ans += (init[i] - last[j]);
				else
					ans += (last[j+1] - init[i]);
				i++;
				j++;
			}
			else
				j++;
		}
		cout << ans << endl;
	}
	return 0;
}
#endif
