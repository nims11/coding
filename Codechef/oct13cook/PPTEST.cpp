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
int dp[101][101];
int P[101], C[101], T[101];
int N, W;
int main()
{
    in_T
    {
        in_I(N);in_I(W);
        for(int i = 1;i<=N;i++)
        {
            in_I(C[i]); in_I(P[i]); in_I(T[i]);
        }
        for(int i = 0;i<=N;i++)
            for(int j = 0;j<=W;j++)
                dp[i][j] = 0;
        dp[0][W] = 0;
        int ans = 0;
        for(int i = 1;i<=N;i++)
            for(int j = 0;j<=W;j++)
            {
                dp[i][j] = dp[i-1][j];

                if(j+T[i] <= W)
                {
                    dp[i][j] = max(dp[i][j], C[i]*P[i]+dp[i-1][j+T[i]]);
                }
                ans = max(ans, dp[i][j]);
            }
//        cout<<dp[1][5]<<endl;
        printf("%d\n", ans);
    }
}
