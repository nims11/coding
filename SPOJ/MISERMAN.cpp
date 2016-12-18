/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int main()
{
    int n,m;
    int fares[102][102],dp[102][102];
    in_I(n);in_I(m);
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        in_I(fares[i][j]);
    }
    for(int i=0;i<m;i++)
    dp[n-1][i]=fares[n-1][i];
    for(int i=n-2;i>=0;i--)
    {
        dp[i][0]=fares[i][0]+min(dp[i+1][1],dp[i+1][0]);

        for(int j=1;j<m-1;j++)
        dp[i][j]=fares[i][j]+min(dp[i+1][j],min(dp[i+1][j-1],dp[i+1][j+1]));

        dp[i][m-1]=fares[i][m-1]+min(dp[i+1][m-2],dp[i+1][m-1]);
    }
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<m;j++)cout<<dp[i][j]<<','<<fares[i][j]<<"\t";
//        cout<<endl;
//    }
    int ans=1<<30;
    for(int i=0;i<m;i++)
    if(ans>dp[0][i])ans=dp[0][i];
    cout<<ans<<endl;
}

