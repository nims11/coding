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
#include<cassert>
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
int sk[100001];
int n,m,u,v;
int BIT[100001];
vector<int> adj[100001];
int query(int idx)
{
    int ret = 0;
    while(idx>0)
    {
        ret += BIT[idx];
        idx -= idx & -idx;
    }
    return ret;
}
void update(int idx, int val)
{
//    assert(idx>0);
    while(idx<=n)
    {
        BIT[idx] += val;
        idx += idx & -idx;
    }
}
int dfs_no = 1;
int foo[100001];
int maxi[100001];
void mapp(int idx, int par = -1)
{
    foo[idx] = dfs_no++;
    maxi[idx] = foo[idx];
    for(int i=0;i<adj[idx].size();i++)
    {
        if(adj[idx][i] != par)
        mapp(adj[idx][i], idx);
    }
    maxi[idx] = dfs_no-1;
}
char str[5];
int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++)
    {
        in_I(sk[i]);
    }
    for(int i=1;i<n;i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    mapp(1);
    for(int i=1;i<=n;i++)
    {
        assert(foo[i]>0);
        update(foo[i], sk[i]);
    }
    while(m--)
    {
        scanf("%s %d", str, &u);
        if(str[0] == 'U')
        {
            in_I(v);
            int diff = v - sk[u];
            sk[u] = v;
            update(foo[u], diff);
        }else
        {
            printf("%d\n", query(maxi[u]) - query(foo[u]-1));
        }
    }
}
