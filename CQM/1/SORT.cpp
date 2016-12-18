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
int dp[1001];
int main()
{
    in_T
    {
        int n,x;
        in_I(n);
        for(int i = 0; i<=1000; i++) dp[i] = 0;
        int res = 0, sum = 0;
        for(int i = 0; i<n; i++)
        {
            in_I(x);
            sum += x;
            int y = dp[x];
            for(int j = 0; j<x; j++)
            {
                y = max(y, dp[j]);
            }
            dp[x] = max(dp[x], y+x);

            res = max(dp[x], res);
        }
        printf("%d\n", sum-res);
    }
}
