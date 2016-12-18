/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<stack>
#include<set>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int n, m;
vector<int> adj[100001];
int mini[100001];
int comp = 0;
int u, v;
int visited[100001];
void dfs(int u)
{
    visited[u] = comp;
    for(int i=0;i<adj[u].size();i++)
        if(!visited[adj[u][i]])
            dfs(adj[u][i]);
}
int c[100001];
int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++)
        in_I(c[i+1]);
    for(int i=1; i<=n ;i++)
    {
        if(!visited[i])
        {
            comp++;
            dfs(i);
        }
    }
    if(comp == 1)
    {
        printf("0\n");
        return 0;
    }
    const int INF = 1000000000;
    for(int i=1;i<=comp;i++)
        mini[i] = INF;
    for(int i=1;i<=n;i++)
    {
        if(c[i]>=0)
            mini[visited[i]] = min(mini[visited[i]], c[i]);
    }
    int glo_min = INF, idx;
    for(int i=1;i<=comp;i++)
    {
        if(mini[i] == INF)
        {
            printf("-1\n");
            return 0;
        }
        if(glo_min>mini[i])
            glo_min = mini[i], idx = i;
    }
    long long res = 0;
    for(int i=1;i<=comp;i++)
    {
        if(i != idx)
        {
            res += mini[i] + glo_min;
        }
    }
    printf("%lld\n", res);
}
