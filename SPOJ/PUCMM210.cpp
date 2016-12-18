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

using namespace std;
static long long dp[1000005];
int main()
{
    int n,mod=1000000003;
    dp[0]=1;
    for(long long i=2;i<=1000005;i++)
    {
        long long k=(((i*(i+1))/2)%mod);
        dp[i-1]=(dp[i-2]+(k*k)%mod)%mod;
    }
    in_T
    {
        in_I(n);
        printf("%lld\n",dp[n-1]);
    }
}

