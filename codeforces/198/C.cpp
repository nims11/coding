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
#include<cassert>
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
int occ[3000];
const int mod = 1000000007;
long long a[3000];
int arr[3000];
int fact[3000];
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
int C(int n, int k)
{
    return ((fact[n])*1LL*((POW(fact[k], mod-2)*1LL*POW(fact[n-k], mod-2))%mod))%mod;
}
int main()
{
    int n;
    cin>>n;
    a[0] = 1;
    a[1] = 0;
    for(int i = 2; i<=2000; i++)
    {
        a[i] = ((i-1)*(a[i-1]+a[i-2]))%mod;
    }
    fact[0] = 1;
    for(int i = 1; i<=2000; i++)
    {
        fact[i] = (1LL*fact[i-1]*i)%mod;
    }
    for(int i = 0; i<n; i++)
    {
        in_I(arr[i]);
        if(arr[i] != -1)
            occ[arr[i]] = 1;
    }
    int fx = 0, tot = 0;
    for(int i = 0; i<n;i++)
    {
        if(arr[i] == -1)
        {
            tot++;
            fx += (occ[i+1] == 0);
        }
    }
    long long res = 0;
    for(int i = fx; i<=tot; i++)
    {
        res += (C(tot, tot-i)*a[i])%mod;
        res %= mod;
    }
    cout<<res<<endl;
}
