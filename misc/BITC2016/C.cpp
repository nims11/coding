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
int N;
vector<int> neigh[100010];
int dp[100010][16], dp_c[100010][16];
int parent[100010];
void dfs(int idx, int par=-1){
    parent[idx] = par;
    for(int v: neigh[idx]){
        if(v != par)
            dfs(v, idx);
    }
}
void compute_c(int idx, int dist){
    if(dp_c[idx][dist] != -1)
        return;
    dp_c[idx][dist] = 0;
    for(int v: neigh[idx]){
        if(v != parent[idx]){
            compute_c(v, dist-1);
            dp_c[idx][dist] += dp_c[v][dist-1];
        }
    }
}
void compute(int idx, int dist){
    if(dp[idx][dist] != -1)
        return;
    dp[idx][dist] = 0;
    compute_c(idx, dist);
    if(idx!=1)
        compute(parent[idx], dist-1);
    if(dist-2 > 0)
        compute_c(idx, dist-2);
    dp[idx][dist] = dp_c[idx][dist] + (idx!=1?(dp[parent[idx]][dist-1] - (dist-2>=0?dp_c[idx][dist-2]:0)):0);
}
int main(){
    memset(dp, -1, sizeof(dp));
    memset(dp_c, -1, sizeof(dp_c));
    in_I(N);
    int x, y;
    for(int i = 0;i<N-1;i++){
        in_I(x);in_I(y);
        neigh[x].push_back(y);
        neigh[y].push_back(x);
    }
    for(int i = 1;i<=N;i++){
        dp[i][0] = dp_c[i][0] = 1;
    }
    dfs(1);
    int Q;
    in_I(Q);
    while(Q--){
        in_I(x);in_I(y);
        int ans = 0;
        for(int i = 0;i<=y;i++){
            compute(x, i);
            ans += dp[x][i];
        }
        printf("%d\n", ans);
    }
}
