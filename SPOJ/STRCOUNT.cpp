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
long long dp[64][64];
int main()
{
    for(int i=0;i<=64;i++)
        dp[i][i] = dp[i][0] = 1;
    for(int i=1;i<=63;i++)
    {
//        cout<<i<<endl;
        cout<<dp[i][0]<<" ";
        for(int j=1;j<=i;j++)
        {
            dp[i][j] = 0;
            for(int k=0;k<j && i-k-1>=j;k++)
            {
                dp[i][j] += dp[i-k-1][j];
            }
//            if(i == 2 && j == 1)cout<<"*"<<dp[i][j]<<endl;
            if(i-j-1 < 0)
                dp[i][j] = 1;
            for(int k=0;k<=j && i-j-1>=k;k++)
                dp[i][j] += dp[i-j-1][k];
            printf("%lld ", dp[i][j]);
        }
        cout<<endl;
    }
}
