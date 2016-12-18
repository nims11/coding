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
int n;
int a[3001], b[3001], c[3001];
int dp[3001][2];
const int INF = 1e9;
int main()
{
    in_I(n);
    for(int i = 1;i<=n;i++)
        in_I(a[i]);
    for(int i = 1;i<=n;i++)
        in_I(b[i]);
    for(int i = 1;i<=n;i++)
        in_I(c[i]);

    dp[0][0] = 0;
    dp[0][2] = -INF;
    dp[1][0] = a[1];
    dp[1][2] = b[1];
    for(int i = 2;i<=n;i++)
    {
        dp[i][0] = dp[i-1][2] + a[i];
        dp[i][0] = max(dp[i][0], dp[i-1][0] + b[i]);

        if(i != n)
        {
            dp[i][2] = dp[i-1][0] + c[i];
            dp[i][2] = max(dp[i][2], dp[i-1][2] + b[i]);
        }
        else
            dp[i][2] = -INF;
    }
    cout<<dp[n][0]<<endl;
}
