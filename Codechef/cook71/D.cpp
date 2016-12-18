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

int N, M;
vector<int> neigh[100010];
int cnt[100010];
int isCycle[100010];
int vis[100010];
int cntt = 0;
int bar(int idx, int par=-1){
    if(vis[idx])
        return 0;
    vis[idx] = ++cntt;
    int ret = 0;
    for(int u: neigh[idx]){
        if(u != par){
            ret += bar(u, idx);
            if(vis[idx] > vis[u]){
                ret++;
            }
        }
    }
    return ret;
}
int main(){
    in_I(N);
    in_I(M);
    int foo = 0;
    for(int i = 0;i<M;i++){
        int u, v;
        in_I(u);
        in_I(v);
        cnt[u]++;
        cnt[v]++;
        neigh[u].push_back(v);
        neigh[v].push_back(u);
    }
    for(int i = 1;i<=N;i++){
        if(cnt[i] < 2){
            foo++;
        }
    }
    int bb = bar(1);
    printf(foo + bb <= 2?"YES\n": "NO\n");
}
