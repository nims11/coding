#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;
int N;
vector<int> neigh[2][500010];
int par[1000100][32];
int depth[1000100];
void dfs1(int idx, int par = -1){
    for(int v: neigh[idx]){
        if(v != par){
        }
    }
}
int main(){
    in_T{
        in_I(N);
        for(int i = 0;i<=N;i++){
            neigh[0][i].clear();
            neigh[1][i].clear();
        }
        for(int i = 0;i<N-1;i++){
            int u, v;
            in_I(u);
            in_I(v);
            neigh[0][u].push_back(v);
            neigh[0][v].push_back(u);
        }
        for(int i = 0;i<N-1;i++){
            int u, v;
            in_I(u);
            in_I(v);
            neigh[1][u].push_back(v);
            neigh[1][v].push_back(u);
        }
        depth[1] = 1;
        dfs1(1);
    }
}
