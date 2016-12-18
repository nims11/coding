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
const long long mod = 1000000007;
int n,a,b;
long long fact[1000001], inv[1000001];
int degree(long long cur)
{
  int res = 1;
  int k = mod-2;
  while (k)
  {
    if (k%2)
    {
      res = (res * cur)%mod;
    }
    k /= 2;
    cur = (cur * cur) % mod;
  }
  return res;
}
bool is_valid(int X)
{
    while(X)
    {
        if(X%10 != a && X%10 != b)
            return false;
        X /= 10;
    }
    return true;
}
int main()
{
    fact[0] = 1;
    for(int i=1;i<=1000000;i++)
        fact[i] = (fact[i-1]*i)%mod;
    for(int i=0;i<=1000000;i++)
        inv[i] = degree(fact[i]);
    cin>>a>>b>>n;
    long long ans = 0;
    for(int i=0;i<=n;i++)
    {
        if(is_valid(a*i + b*(n-i)))
            ans = (ans + ((((fact[n]*inv[i])%mod)*inv[n-i])%mod))%mod;
    }
    cout<<ans<<endl;
}
