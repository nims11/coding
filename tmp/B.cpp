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

int N, K;
double getans(int mask, vector<double> &p){
   double dp[N+1][K+1];
   memset(dp, 0, sizeof(dp));
   dp[0][0] = 1;
   for(int i = 1;i<=N;i++){
       for(int j = 0;j<=min(i, K);j++){
           dp[i][j] = dp[i-1][j];
           if(mask&(1<<(i-1))){
               dp[i][j] = dp[i-1][j]*(1-p[i]) + (j>0?dp[i-1][j-1]*p[i]:0);
           }
       }
   }
   return dp[N][K/2];
}
int main(){
   int z = 0; 
   int t;
   cin>>t;
   for(int z = 1;z<=t;z++){
       cin>>N>>K;
       vector<double> p(N+1);
       for(int i = 1;i<=N;i++)
           cin>>p[i];
       double ans = 0;
       for(int i = 0;i<(1<<N);i++){
           if(__builtin_popcount(i) == K){
            ans = max(ans, getans(i, p));
           }
       }
       // double dp[N+1][K+1][K+1];
       // memset(dp, 0, sizeof(dp));
       // dp[0][0][0] = 1;
       // for(int i = 1;i<=N;i++){
       //  for(int k = 0; k<=min(i,K); k++){
       //      for(int j = 0;j<=k;j++){
       //          dp[i][k][j] = max(dp[i][k][j], dp[i-1][k][j]);
       //          if(k > 0){
       //              dp[i][k][j] = max(dp[i][k][j], dp[i-1][k-1][j]*(1-p[i]) + (j>0?dp[i-1][k-1][j-1]*p[i]:0));
       //          }
       //      }
       //  }
       // }
       // for(int i = 1;i<=N;i++){
       //  for(int j = 0;j<=min(i, K);j++)
       //      for(int k = 0;k<=j;k++)
       //          cout<<i<<" "<<j<<" "<<k<<": "<<dp[i][j][k]<<endl;
       // }
       // cout<<dp[N][K][K/2]<<endl;
       printf("Case #%d: %.8lf\n", z, ans);
   }
}
