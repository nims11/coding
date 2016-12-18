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
    int mod = 314159;
    in_T
    {
        int n;
        in_I(n);
        int dp[n+1][2];
        dp[0][0] = 1;
        dp[0][1] = 0;
        for(int i=1;i<=n;i++)
        {
            dp[i][0] = ((9*dp[i-1][0]) + dp[i-1][1])%mod;
            dp[i][1] = ((9*dp[i-1][1]) + dp[i-1][0])%mod;
        }
        printf("%d\n",dp[n][0]);
    }
}
