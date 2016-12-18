/*
    Nimesh Ghelani (nims11)
    dp[i][j] = optimal answer for submatrix [0..i][0..j]
    each cell can either go all the way to top or left.
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
int n,m;
int dp[501][501];
int yeye[501][501], blog[501][501];
int main()
{
    for(int i=0;i<=500;i++)
        dp[i][0] = dp[0][i] = yeye[0][i] = yeye[i][0] = blog[i][0] = blog[0][i] = 0;
    while(1)
    {
        scanf("%d%d", &n, &m);
        if(n == 0)
            return 0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                in_I(yeye[i][j]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                in_I(blog[i][j]);

        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                yeye[i][j] += yeye[i][j-1], blog[i][j] += blog[i-1][j];

        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            dp[i][j] = max(yeye[i][j]+dp[i-1][j], blog[i][j]+dp[i][j-1]);
        }
        printf("%d\n", dp[n][m]);
    }
}
