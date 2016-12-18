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
long long dp[1001][2], mod = 1000000007;
int main()
{
    in_T
    {
        int n,k;
        in_I(n);
        in_I(k);
        dp[0][0] = 1;
        dp[0][1] = 0;
        for(int i=1;i<=n;i++)
        {
            dp[i][0] = dp[i-1][1];
            dp[i][1] = ((dp[i-1][1]*(k-1))%mod + (k*dp[i-1][0])%mod)%mod;
        }
        printf("%lld\n", dp[n][0]);
    }
}
