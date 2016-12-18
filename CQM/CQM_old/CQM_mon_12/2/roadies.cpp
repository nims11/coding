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
int n,p[10002];
long long dp[10002];
long long getans(int n)
{
    if(n<=0)return 0;
    if(dp[n]!=-1)return dp[n];
    long long &ans=dp[n];
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,(long long)p[i]+getans(n-i));
    }
    return ans;
}
int main()
{
    in_T
    {
        in_I(n);
        for(int i=0;i<=n;i++)
        dp[i]=-1;
        p[0]=0;
        for(int i=1;i<=n;i++)
        in_I(p[i]);
        cout<<getans(n)<<endl;
    }
}
