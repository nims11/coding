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
int main()
{
    in_T
    {
        int n;
        in_I(n);
        int dp[n][3], grid[n][3];
        for(int i=0;i<n;i++)
            scanf("%d%d%d", &grid[i][0], &grid[i][1], &grid[i][2]);
        dp[0][0] = grid[0][0];
        dp[0][1] = grid[0][1];
        dp[0][2] = grid[0][2];
        for(int i=1;i<n;i++)
        {
            dp[i][0] = grid[i][0] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = grid[i][1] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = grid[i][2] + min(dp[i-1][1], dp[i-1][0]);
        }
        printf("%d\n", min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2])));
    }
}
