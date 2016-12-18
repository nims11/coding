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
long double win[3020];
long double PP[3010][3010];
long double C[3020][3020];
long double dp[3020];
int main(){
    for(int i = 0;i<=3010;i++)
        C[i][0] = C[i][i] = 1;
    for(int i = 1;i<=3010;i++)
        for(int j = 1;j<i;j++)
            C[i][j] = C[i-1][j-1] + C[i-1][j];

    int z = 0;
    int t;
    cin>>t;
    while(t--){
        int N, K;
        long double p;
        cin>>N>>K>>p;
        PP[0][0] = 1;
        for(int i = 1;i<=N;i++){
            win[i] = 0;
            for(int j = 0;j<=i;j++){
                PP[i][j] = PP[i-1][j]*(1-p);
                if(j>0)
                    PP[i][j] += PP[i-1][j-1]*p;
                if(j>=K)
                    win[i] += PP[i][j];
            }
        }
        // for(int i = 0;i<=5;i++)
        //     cout<<win[i]<<" ";
        // cout<<endl;
        dp[0] = 0;
        for(int i = 1;i<=N;i++){
            dp[i] = 0;
            for(int j = 1;j<=i;j++){
                dp[i] = max(dp[i], dp[i-j] + win[j]);
            }
            // if(z == 1)
            // cout<<i<<" "<<dp[i]<<endl;
        }
        printf("Case #%d: %.10Lf\n", (++z), dp[N]);
    }
}
