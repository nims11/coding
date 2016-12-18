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
long long mod = 1e9+7;
int mod1 = 2;
long long mod2 = 5e8+3;
long long POW(long long r, long long n, long long mod)
{
    long long ans = 1;
    while(n>0)
    {
        if(n&1)
            ans = (ans*r)%mod;
        n /= 2;
        r = (r*r)%mod;
    }
    return ans;
}
long long fact[200001];
long long inv(long long x, long long mod)
{
    return POW(x, mod-2, mod);
}
long long combi(int n, int k, long long mod)
{
    return (((fact[n]*inv(fact[k], mod))%mod)*inv(fact[n-k], mod))%mod;
}
int main()
{
    fact[0] = 1;
    for(int i=1;i<=200000;i++)
        fact[i] = (fact[i-1]*i)%mod2;
    in_T
    {
        int a,b,n;
        in_I(a);in_I(b);in_I(n);
        long long exp, tmp;
        exp = combi(2*n, n, mod2);

        tmp = POW(exp, b, mod2);
        if(b!=0)
        if(((n==0)-tmp)%2 != 0)
            tmp += mod2;
        tmp = POW(a, tmp, mod);
        printf("%lld\n", tmp);
    }
}
