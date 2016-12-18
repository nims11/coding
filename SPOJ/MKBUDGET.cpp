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
    int ccc = 0;
    while(1)
    {
        ccc++;
        int n;
        in_I(n);
        if(n==0)return 0;
        int hire, salary, sever;
        scanf("%d%d%d\n", &hire, &salary, &sever);
        int req[n+1];
        req[0] = 0;
        int max1 = 0;
        for(int i=1;i<=n;i++)
        {
            in_I(req[i]);
            max1 = max(max1, req[i]);
        }
        int dp[n+1][max1+1];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=max1;j++)
                dp[i][j] = -1;
        dp[0][0] = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=req[i];j>=req[i-1];j--)
            {
                if(dp[i-1][j] != -1)
                {
                    if(dp[i][req[i]]==-1)
                        dp[i][req[i]] = dp[i-1][j] + req[i]*salary + (req[i]-j)*hire;
                    else
                        dp[i][req[i]] = min(dp[i][req[i]], dp[i-1][j] + req[i]*salary + (req[i]-j)*hire);
                }
            }
            for(int j=req[i]+1;j<=max1;j++)
            {
                if(dp[i-1][j]!=-1)
                for(int k=req[i];k<=j;k++)
                {
                    if(dp[i][k]!=-1)
                    dp[i][k] = min(dp[i][k], dp[i-1][j] + sever*(j-k) + salary*k);
                    else
                        dp[i][k] = dp[i-1][j] + sever*(j-k) + salary*k;
                }
            }
        }
//        for(int j=0;j<=n;j++)
//        {for(int i=0;i<=max1;i++)
//            cout<<dp[j][i]<<" ";
//        cout<<endl;
//        }
        int ans = dp[n][req[n]];
        for(int i=req[n]+1;i<=max1;i++)
            ans = min((dp[n][i]==-1?ans:dp[n][i]), ans);
        printf("Case %d, cost = $%d\n",ccc, ans);
    }
}
