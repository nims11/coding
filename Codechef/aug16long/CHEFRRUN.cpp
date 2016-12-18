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
int arr[100010];
int vis[100010];
int iscycle[100010];
int _time = 0;
void dfs(int idx){
    vis[idx] = _time;
    int next = (idx + arr[idx] + 1)%N;
    if(vis[next] == 0)
        dfs(next);
    else if(vis[next] == _time && !iscycle[next]){
        iscycle[next] = 1;
        dfs(next);
    }
}
int main(){
    in_T{
        in_I(N);
        for(int i = 0;i<N;i++)
            in_I(arr[i]);
        fill(vis, vis+N, 0);
        fill(iscycle, iscycle+N, 0);
        int ans = 0;
        for(int i = 0;i<N;i++){
            if(!vis[i]){
                _time++;
                dfs(i);
            }
            ans += iscycle[i];
        }
        printf("%d\n", ans);
    }
}
