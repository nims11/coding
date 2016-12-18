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
        int k,m;
        in_I(k);in_I(m);
        int dp[m+1][k+1];
        for(int i=0;i<=k;i++)
            dp[0][i] = 0;
        int w[m], v[m];
        for(int i=0;i<m;i++)
        {
            in_I(w[i]);
            in_I(v[i]);
        }
        for(int i=1;i<=m;i++)
        {
            dp[i][0] = 0;
            for(int j=1;j<=k;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j-w[i-1]>=0)
                    dp[i][j] = max(dp[i][j], v[i-1]+dp[i-1][j-w[i-1]]);
            }
        }
        cout<<"Hey stupid robber, you can get "<<dp[m][k]<<".\n";
    }
}
