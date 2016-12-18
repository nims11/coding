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
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<stack>
#include<set>
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
        int n;
        in_I(n);
        long long dp[n+1][n+1];
        for(int i = 0; i<=n; i++)
            dp[0][i] = 1, dp[i][0] = 0;
        dp[0][0] = 1;
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                dp[i][j] = dp[i][j-1];
                if(i-j >= 0)
                    dp[i][j] += dp[i-j][j-1];
            }
        }
        printf("%lld\n", dp[n][n-1]);
    }
}
