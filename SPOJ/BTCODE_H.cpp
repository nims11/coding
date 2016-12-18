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
long double C[301][301];
long double dp[301][301];
long double pow2[301];
int main()
{
    for(int i=0;i<=300;i++)
        C[i][0] = 1;
    for(int i=1;i<=300;i++)
        C[0][i] = 0;
    for(int i=1;i<=300;i++)
        for(int j=1;j<=300;j++)
            C[i][j] = C[i-1][j-1] + C[i-1][j];
    pow2[0] = 1;
    for(int i=1;i<=300;i++)
        pow2[i] = 2*pow2[i-1];
    dp[0][0] = 0;
    for(int i=1;i<=300;i++)
        dp[i][0] = 1, dp[0][i] = 0;
    for(int i=1;i<=300;i++)
        for(int j=1;j<=300;j++)
    {
        dp[i][j] = 0;
        for(int k=0;k<=i;k++)
        {
            dp[i][j] += C[i][k]*(dp[k][j-1]+dp[i-k][j-1]);
        }
        dp[i][j] /= pow2[i];
        dp[i][j] += 1;
    }
    int a,b;
    in_T
    {
        scanf("%d%d", &a, &b);
        printf("%.2llf\n", dp[a][b]);
    }
}
