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
int arr[1000], tmp[1000];
int mod = 1000000007;
int pow_2[1001];
int fact[1001];
int inv[1001];
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
long long combinations(int n, int k) {
  long long res = fact[n];
  res = (res*((inv[n-k]*(long long)inv[k])%mod))%mod;
  return res;
}
int main()
{
    pow_2[0] = 1;
    for(int i=1;i<=1000;i++)
        pow_2[i] = (2*pow_2[i-1])%mod;
    fact[0] = 1;
    fact[1] = 1;
    for(long long i=2;i<=1000;i++)
        fact[i] = (i*fact[i-1])%mod;
    for(int i=0;i<=1000;i++)
        inv[i] = degree(fact[i]);
    in_T
    {
        int n;
        in_I(n);
        int tmp;
        for(int i=0;i<n;i++)
            in_I(tmp);
//        long long res = 0;
//        for(int i=n/2+1;i<=n;i++)
//        {
//            res = (res+ combinations(n,i))%mod;
//        }
//        printf("%d\n", res);
        if(n%2)
        {
            printf("%d\n", pow_2[n-1]);
        }else
        {
            int res = ((pow_2[n] - combinations(n,n/2))*inv[2])%mod;
            if(res<0)
            res += mod;
            printf("%d\n", res);
        }
    }
}
