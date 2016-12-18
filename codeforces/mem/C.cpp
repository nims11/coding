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
int r, n;
int dp[101][101][201];
int main()
{
    cin>>r>>n;
    dp[0][0][0] = 1;
    for(int i = 1;i<=r; i++)
    {
        for(int j = 1; j<=i; j++)
        {
            int L = max(0, j-2), R = max(i-(j+1), 0);
            dp[i][0][0] = dp[L][0][0]^dp[R][0][0];
            if(dp[i][0][0] == 0)
                break;
        }
    }
    for(int i = 0; i<=r; i++)
        for(int k = 0; k<=(r<<1); k++)
            dp[0][i][k] = dp[i][0][0];
    for(int i = 1; i<=r; i++)
    {
        for(int j = 1; j<=r; j++)
        {
            for(int s = 0; i<(r<<1); i++)
            {

            }
        }
    }
}
