//GQ
/*
 * DP
 * maintain a list of all possible bases and perform a brute-force.
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
long long dp[100];int n,x,y,z,Qcount;
struct foo
{
    int a,b,c;
};
struct foo bar[100];
long long getans(int qux)
{
    if(dp[qux]!=-1)return dp[qux];
    dp[qux]=0;
    for(int i=0;i<Qcount;i++)
    {
        if(bar[i].a>bar[qux].a && bar[i].b>bar[qux].b)
        {
            dp[qux]=max(dp[qux],getans(i)+bar[i].c);
        }
    }
//    dp[qux]+=bar[qux].c;
    return dp[qux];
}
int main()
{
    while(1)
    {
        Qcount=0;
        in_I(n);
        if(n==0)return 0;
        for(int i=0;i<3*n;i++)
        dp[i]=-1;
        for(int i=0;i<n;i++)
        {
            in_I(x);in_I(y);in_I(z);
            bar[Qcount].c=z;
            if(x>y)bar[Qcount].a=x,bar[Qcount].b=y;
            else bar[Qcount].a=y,bar[Qcount].b=x;
            Qcount++;
            bar[Qcount].c=y;
            if(x>z)bar[Qcount].a=x,bar[Qcount].b=z;
            else bar[Qcount].a=z,bar[Qcount].b=x;
            Qcount++;
            bar[Qcount].c=x;
            if(z>y)bar[Qcount].a=z,bar[Qcount].b=y;
            else bar[Qcount].a=y,bar[Qcount].b=z;
            Qcount++;
        }
        long long ans=0,k;
        for(int i=0;i<Qcount;i++)
        {
            k=getans(i)+bar[i].c;
            ans=max(ans,k);
        }
        printf("%lld\n",ans);
    }
}
