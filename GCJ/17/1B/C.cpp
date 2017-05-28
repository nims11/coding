#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;
int adj[200][200];
int dp[300][300];
int prefix[300];
int main(){
    int z = 0;
    in_T{
        z++;
        int N, Q;
        in_I(N);
        in_I(Q);
        vector<int> E(N);
        vector<int> S(N);
        for(int i = 0;i<N;i++){
            in_I(E[i]);
            in_I(S[i]);
        }
        for(int i = 0;i<N;i++)
            for(int j = 0;j<N;j++)
                in_I(adj[i][j]);
        prefix[0] = 0;
        for(int i = 1;i<N;i++){
            prefix[i] = prefix[i-1] + adj[i-1][i];
        }
        int u, v;
        in_I(u);
        in_I(v);
        for(int i = 0;i<=N;i++)
            for(int j = 0;j<=N;j++)
                dp[i][j] = 1e9;
        dp[0][0] = 0;
        for(int i = 1;i<N;i++){
            for(int j = 0;j<i;j++){
                if(E[j] >= prefix[i] - prefix[j]){
                    dp[i][j] = min(dp[i][j], dp[j][j] + (prefix[i]-prefix[j])/S[j]);
                }
                cout<<dp[i][j]<<endl;
            }
        }
    }
}
