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
#include<cstring>
#include<cstdlib>
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
int mod = 1000000007;
int POW(long long r, long long n)
{
    int ans = 1;
    while(n>0)
    {
        if(n&1)
            ans = (ans*r)%mod;
        n >>= 1;
        r = (r*r)%mod;
    }
    return ans;
}
int fact[1000002];
int main()
{
    fact[0] = 1;
    for(int i=1;i<=1000000;i++)
    {
        fact[i] = (fact[i-1]*1LL*i)%mod;
    }
    int n, m;
    in_T
    {
        scanf("%d%d", &n, &m);
        int diff = m-n;
        long long base = fact[diff+1];
        int row = n-diff-1;
        base = (base*POW(diff+1, row/2))%mod;
        base = (base*POW(diff, (row+1)/2))%mod;
        printf("%lld\n", base);
    }
}
