#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

const int INF = INT_MAX;
using namespace std;
int n, m;
long long a[200010];
vector<pair<int, long long>> neigh[200010];
vector<pair<int, long long>> best[200010];
long long dp[200010];
long long getans(int idx){
    if(dp[idx] > 0)
        return dp[idx];
    auto &ans = dp[idx];
    ans = 1e18;
    if(best[idx].size() == 0)
        return (ans = a[idx]);
    for(auto &x: best[idx]){
        ans = min(ans, x.second + getans(x.first));
    }
    return ans;
}
int main(){
    in_I(n);
    in_I(m);
    int u, v;
    long long c;
    for(int i = 0; i < m; i++){
        in_I(u);
        in_I(v);
        in_L(c);
        neigh[u].push_back({v,c});
        neigh[v].push_back({u,c});
    }

    for(int i = 1; i <= n; i++){
        in_L(a[i]);
    }

    for(int i = 1; i <= n;i++){
        for(auto &x:neigh[i]){
            if(a[i] > 2*x.second + a[x.first]){
                best[i].push_back({x.first, 2*x.second});
            }
        }
    }

    for(int i = 1; i <= n; i++){
        printf("%lld ", getans(i));
    }
    newline;
}
