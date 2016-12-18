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
int n,m;
int L[11][101];
int dp[11][101];
int main()
{
    in_T
    {
        in_I(n); in_I(m);
        for(int i = 1;i<=n;i++)
            for(int j = 1;j<=m;j++)
            in_I(L[i][j]);
        for(int i = 1;i<=n;i++)
            for(int j = 0;j<=m;j++)
        dp[i][j] = -1;
        for(int i = 1;i<=n;i++)
        {
            for(int j = 0;j<=m;j++)
            {
                for(int k = 1;k<=m;k++)
                {
                    if(j+k>m)break;
                    if(dp[i-1][j+k] != -1 && L[i][k] >= 5)
                        dp[i][j] = max(dp[i][j], dp[i-1][j+k]+L[i][k]);
                }
            }
        }
        int res = -1;
        for(int i = 0;i<=m;i++)
            res = max(res, dp[n][i]);
        if(res == -1)
            printf("Too much Dota.\n");
        else
            printf("%d\n", res);
    }
}
