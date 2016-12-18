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
int adj[301][301];
int vis[301];
int n;
const int inf = 1e9;
int IDX;
int dfs(int idx, int par=-1, int depth=1){
    cout<<idx<<endl;
    vis[idx] = 1;
    int ret = inf;
    for(int i = 0;i<n;i++){
        if(i != par && adj[idx][i] > 0){
            if(!vis[i])
                ret = min(ret, dfs(i, idx, depth+1));
            else if(i == IDX){
                ret = min(ret, depth);
            }
        }
    }
    return ret;
}
int main(){
    in_I(n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            in_I(adj[i][j]);
            if(adj[i][j] == -1)
                adj[i][j] = inf;
        }
    }
    for(int k = 0;k<n;k++){
        for(int i= 0;i<n;i++){
            for(int j = 0;j<n;j++){
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    for(int i = 0;i<n;i++){
        memset(vis, 0, sizeof(vis));
        IDX = i;
        int x = dfs(i);
        cout<<endl;
        if(x == inf) x = -1;
        printf("%d\n",x);
    }
}
