/*
    Nimesh Ghelani (nims11)
*/
#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
double dp[2001][2001];
int main()
{
    int n, t;
    double p;
    in_I(n);in_F(p);in_I(t);
    double res = 0.0f;
    dp[0][0] = 1;
    for(int T = 1;T<=t;T++){
        for(int N = 0;N<=n;N++){
            dp[T][N] = dp[T-1][N]*(N!=n?(1-p):1) + (N>0?(dp[T-1][N-1]*p):0);
            // cout<<dp[T][N]<<" ";
        }
        // cout<<endl;
    }
    for(int i = 0;i<=n;i++)
        res += dp[t][i]*i;
    printf("%.8lf", res);
}
