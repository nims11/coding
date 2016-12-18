/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
long long m,n,x,mod=1000000007,d,c[100],tmp;
long long dp[1000];
int dp2[805][405];
long long ans=0;
long long eval(int v)
{
    if(v==d)return (c[v]*tmp)%mod;
    return (tmp*((c[v]+eval(v+1))%mod))%mod;
}
int getans(int sum,int cnt)
{
    if(dp2[sum][cnt]!=-1)
    return dp2[sum][cnt];

    int ans=0;
    for(int i=0;i<=sum;i++)
    {
        ans+=(dp[i]*getans(sum-i,cnt-1))%mod;
        ans%=mod;
    }
    dp2[sum][cnt]=ans;
    return ans;
}
int main()
{
    in_T
    {
        ans=0;
        in_L(m);in_L(n);in_L(x);in_L(d);
        for(int i=0;i<=d;i++)
        in_L(c[i]);
        if(d>0)
        for(int i=0;i<=n;i++)
        {
            tmp=(x*i)%mod;
            dp[i]=c[0]+eval(1);
        }
        else
        for(int i=0;i<=n;i++)
        {
            tmp=(x*i)%mod;
            dp[i]=c[0];
        }
        for(int i=0;i<=n;i++)
        for(int j=2;j<=m;j++)
        dp2[i][j]=-1;

        for(int i=0;i<=n;i++)
        dp2[i][1]=dp[i];

        printf("%lld\n",getans(n,m));
    }
}
