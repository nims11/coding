/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<set>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
using namespace std;
long dp[500003]={0};
set <long> present;
long calc(long n)
{
    if(n==0)return 0;
    if(dp[n])return dp[n];
    dp[n]=calc(n-1)-n;
    if(dp[n]<=0 || present.find(dp[n])!=present.end())
    dp[n]+=n+n;
    present.insert(dp[n]);
    return dp[n];
}
int main()
{
    present.insert(0);
    for(int i=0;i<=500000;i++)calc(i);
    long n;
    while(1)
    {
        in_L(n);
        if(n==-1)break;
        printf("%lld\n",calc(n));
    }
}
