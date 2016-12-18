#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)
vector<pair<int, int>> neigh[200];
int dist[200];
int main(){
    int n, m;
    in_I(n);
    vector<int> t(n+1);
    for(int i = 1;i<=n;i++)
        in_I(t[i]);
    in_I(m);
    for(int i = 0;i<m;i++){
        int u, v, c;
        in_I(u);in_I(v);in_I(c);
        neigh[u].push_back({v,c});
        neigh[v].push_back({u,c});
    }
    priority_queue<pair<pair<int, int>, int>> dij;
    dij.push({{0,t[1]}, 1});
    while(!dij.empty()){
        auto top = dij.top();
        dij.pop();
        int u = top.second;
        dist[u] = 1;
        int c = -top.first.first;
        int tot = top.first.second;
        if(u == n){
            printf("%d %d\n", c, tot);
            return 0;
        }

        for(auto &v: neigh[u]){
            if(!dist[v.first]){
                dij.push({{-c-v.second, tot+t[v.first]}, v.first});
            }
        }
    }
    printf("impossible\n");
}
