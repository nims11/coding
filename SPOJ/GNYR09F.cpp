/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int main()
{
    in_T
    {
        int dta, n,k;
        scanf("%d%d%d", &dta, &n, &k);
        int dp[n+1][k+1][2];
        dp[1][0][0] = dp[1][0][1] = 1;
        for(int i=1;i<=k;i++)
        {
            dp[1][i][0] = dp[1][i][1] = 0;
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
                dp[i][j][1] = dp[i-1][j][0] + (j-1>=0?dp[i-1][j-1][1]:0);
            }
        }
        printf("%d %d\n", dta, dp[n][k][0]+dp[n][k][1]);
    }
}
