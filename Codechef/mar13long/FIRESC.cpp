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
vector<int> adj[100001];
bool visited[100001];
int dfs(int id)
{
    int ret = 1;
    for(int i=0;i<adj[id].size();i++)
    {
        if(!visited[adj[id][i]])
        {
            visited[adj[id][i]] = true;
            ret += dfs(adj[id][i]);
        }
    }
    return ret;
}
int mod = 1000000007;
int main()
{
    in_T
    {
        int n, m, x, y;
        in_I(n);
        in_I(m);
        for(int i=1;i<=n;i++)
            adj[i].clear(), visited[i] = false;
        for(int i=0;i<m;i++)
        {
            in_I(x);
            in_I(y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int cnt = 0;
        long long xx = 1;

        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                cnt++;
                visited[i] = true;
                xx = (xx*dfs(i))%mod;
            }
        }
        cout<<cnt<<" "<<xx<<endl;
    }
}
