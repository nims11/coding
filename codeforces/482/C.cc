#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

const int INF = INT_MAX;

const int mod = 1000000007;
using namespace std;
vector<int> neigh[300010];
int vis[300010];
int x, y;
int dfs(int idx){
    vis[idx] = 1;
    if(idx == y)
        return -1;
    int ret = 0;
    for(int u: neigh[idx]){
        if(!vis[u]){
            int foo = dfs(u);
            if(ret >= 0 && foo >= 0)
                ret += foo;
            else
                ret = -1;
        }
    }
    if(ret == -1)
        return -1;
    return ret + 1;
}
int main(){
    int n;
    in_I(n); in_I(x); in_I(y);
    for(int i = 0; i < n-1  ; i++){
        int u, v;
        in_I(u);
        in_I(v);
        neigh[u].push_back(v);
        neigh[v].push_back(u);
    }
    vis[x] = 1;
    long long x_tot = 0;
    for(int u: neigh[x]){
        int foo = dfs(u);
        if(foo > 0)
            x_tot += foo;
    }
    assert(vis[y] == 1);
    long long y_tot = 0;
    for(int u: neigh[y]){
        if(!vis[u]){
            int foo = dfs(u);
            if(foo > 0)
                y_tot += foo;
        }
    }
    long long tot = (n * 1LL * (n-1));
    tot -= ((x_tot+1) * (y_tot+1));
    cout<<tot<<endl;
}
