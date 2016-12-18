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
vector<pair<int, int> > neigh[100001];
bool visited[100001];
int mod = 1000000007;
pair<int, int> x;
// MODULO OP
pair<int, int> dfs(int u)
{
    pair<int, int> ret = make_pair(0, 1);
    int tmp = 1;
    for(int i=0;i<neigh[u].size();i++)
    {
        int v = neigh[u][i].first;
        if(!visited[v])
        {
            visited[v] = true;
            x = dfs(v);
            ret.first = (ret.first + x.first)%mod;
            x.second = (x.second*1LL*neigh[u][i].second)%mod;
            ret.first = (ret.first + (1LL*tmp*x.second)%mod)%mod;
            tmp = (tmp + x.second)%mod;
            ret.second = (ret.second + x.second)%mod;
        }
    }
//    cout<<u<<" "<<ret.first<<" "<<ret.second<<endl;
    return ret;
}
int main()
{
    int n,a,b,c;
    in_I(n);
    for(int i=0;i<n-1;i++)
    {
        in_I(a);in_I(b);in_I(c);
        neigh[a].push_back(make_pair(b,c));
        neigh[b].push_back(make_pair(a,c));
    }
    visited[1] = true;
    printf("%d\n", dfs(1).first);
}
