/*
    Nimesh Ghelani (nims11)
*/
#include<cstdio>
#include<iostream>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
int dp[101][101];
int cost[101][101];
int a[101];
int cumul_cost[101];
int n;
void calc_cost()
{
    cumul_cost[0]=0;
    for(int i=1;i<=n;i++)
    cumul_cost[i]=(cumul_cost[i-1]+a[i])%100;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            cost[i][j]=cumul_cost[j]-cumul_cost[i-1];
            if(cost[i][j]<0)cost[i][j]=100+cost[i][j];
            else cost[i][j]%=100;
        }
    }
}
int getans(int i,int j)
{
    if(dp[i][j]!=-1)return dp[i][j];
    dp[i][j]=getans(i,i)+getans(i+1,j)+cost[i][i]*cost[i+1][j];
    for(int m=i;m<j;m++)
    {
        int h1=getans(i,m)+getans(m+1,j)+cost[i][m]*cost[m+1][j];
        dp[i][j]=MIN(dp[i][j],h1);
    }
    return dp[i][j];
}
int main()
{
    while(in_I(n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        in_I(a[i]);
        calc_cost();
        for(int i=0;i<=n;i++)
        for(int j=i;j<=n;j++)
        dp[i][j]=-1;
        for(int i=0;i<=n;i++)
        dp[i][i]=0;
        int res=getans(1,n);
        printf("%d\n",res);
    }
}
