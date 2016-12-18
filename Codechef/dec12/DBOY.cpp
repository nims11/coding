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
        int n;
        in_I(n);
        int H[n], K[n];
        int max_H(0);
        for(int i=0;i<n;i++)
        {
            in_I(H[i]);
            if(max_H<H[i])
                max_H = H[i];
        }
        max_H <<=1;
        for(int i=0;i<n;i++)
            in_I(K[i]);
        sort(K, K+n);
        int dp[max_H+1];
        dp[0] = 0;
        for(int i=1;i<=max_H;i++)
        {
            dp[i] = -1;
            int ans = 1<<29;
            for(int j=0;j<n && K[j]<=i;j++)
            {
                if(dp[i-K[j]] != -1)
                ans = min(ans, dp[i-K[j]]+1);
            }
            dp[i] = ans;
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans += dp[2*H[i]];
        }
        printf("%d\n", ans);
    }
}
