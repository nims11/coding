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
long long mod = 1000000007;
long long poww(long long r2,long long n)
{
    long long ans=1;
    while(n>0)
    {
        if((n&1)>0)
        ans=(ans*r2)%mod;
        n>>=1;
        r2=(r2*r2)%mod;
    }
    return ans%mod;
}
long long pow_2[2001];
long long fact[2001], inv[2001];
long long combi(int n, int k)
{
    return (fact[n]*((inv[k]*inv[n-k])%mod))%mod;
}
int main()
{
    pow_2[0] = 1;
    for(int i=1;i<=2000;i++)
        pow_2[i] = (pow_2[i-1]*2)%mod;
    fact[0] = 1;
    for(int i=1;i<=2000;i++)
        fact[i] = (fact[i-1]*i)%mod;
    for(int i=0;i<=2000;i++)
        inv[i] = poww(fact[i], mod-2);
    int n,m;
    in_I(n);
    in_I(m);
    int l[m];
    for(int i=0;i<m;i++)
    {
        in_I(l[i]);
    }
    sort(l, l+m);
    int pre_val = 1, pre_n = l[0]-1;
    int nxt_val, nxt_n;
    long long ans = 1;
    for(int i=0;i<m;i++)
    {
        if(i == m-1)
        {
            nxt_n = n-l[i];
            ans =  (ans*combi(pre_n+nxt_n, pre_n))%mod;
            pre_n += nxt_n;
        }else
        {
            nxt_n = l[i+1]-l[i]-1;
            if(nxt_n == 0)
                nxt_val = 1;
            else
                nxt_val = pow_2[nxt_n-1];
            ans = (ans*((nxt_val*combi(pre_n+nxt_n, pre_n))%mod))%mod;
            pre_n += nxt_n;
            pre_val = ans;
        }
    }
    cout<<ans<<endl;
}
