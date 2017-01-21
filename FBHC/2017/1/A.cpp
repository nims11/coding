#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;
long long dp[301][301];
int cost[301][301];
const long long INF = 1e18;
int main(){
    int z = 0;
    in_T{
        z++;
        cout<<"Case #"<<z<<": ";
        int N, M;
        in_I(N);
        in_I(M);
        dp[0][0] = 0;
        for(int i = 1;i<=N;i++){
            dp[0][i] = INF;
            for(int j = 0;j<M;j++){
                in_I(cost[i][j]);
            }
            sort(cost[i], cost[i]+M);
        }
        for(int i = 1;i<=N;i++){
            for(int j = 0;j<=N;j++){
                dp[i][j] = dp[i-1][j];
                long long cur_cost = 0;
                for(int k = 1;k<=M && j-k>=0;k++){
                    cur_cost += cost[i][k-1];
                    dp[i][j] = min(dp[i][j], dp[i-1][j-k] + cur_cost + k*k);
                }
            }
        }
        cout<<dp[N][N]<<endl;
    }
}
