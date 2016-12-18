/*
    Nimesh Ghelani (nims11)
    DP
    dp[i][j] = optimum solution for subarray(i,j)
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
int n, row[1001];
int dp[1001][1001];
int getans(int r1, int r2)
{
    if(r2<r1)return 0;
    if(dp[r1][r2] != -1)return dp[r1][r2];
    int &ret = dp[r1][r2];
    if(row[r1]==row[r2])
    {
        r1++;
    }else if(row[r1]<row[r2])
    {
        r2--;
    }else
    {
        r1++;
    }
    if(r2<r1)return (ret=0);
    return (ret = max(row[r1]+getans(r1+1, r2), row[r2] + getans(r1, r2-1)));
}
int main()
{
    int c = 0;
    while(1)
    {
        c++;
        in_I(n);
        if(!n)return 0;
        for(int i=1;i<=n;i++)
            in_I(row[i]);
        int sum = 0;
        for(int i=1;i<=n;i++)
            sum += row[i];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                dp[i][j] = -1;
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n",c , 2*(max(row[1]+getans(2, n),row[n]+getans(1,n-1)))-sum);
    }
}
