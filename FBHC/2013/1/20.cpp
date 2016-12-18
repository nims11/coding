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
const long long M = 1000000007;
int fact[30001];
int inv[30001];
int degree(long long cur)
{
//    if(cur==0)return 1;
  int res = 1;
  int k = M-2;
  while (k)
  {
    if (k%2)
    {
      res = (res * cur)%M;
    }
    k /= 2;
    cur = (cur * cur) % M;
  }
  return res;
}

long long combinations(int n, int k) {
//    if(k==0)return 1;
  long long res = fact[n];
//  cout<<n<< " "<<k<<endl;
  res = (res*((inv[n-k]*(long long)inv[k])%M))%M;
  return res;
}
long long arr[10002];
int main()
{
    fact[1] = 1;
    fact[0] = 1;
    for(long long i=2;i<=30000;i++)
        fact[i] = (fact[i-1]*i)%M;
//    for(int i=0;i<400;i++)
//    combinations(4000,2000);
    for(int i=0;i<=30000;i++)
        inv[i] = degree(fact[i]);
    int c = 0;
    in_T
    {
        c++;
        int n, k;
        in_I(n);
        in_I(k);
        for(int i=0;i<n;i++)
            in_L(arr[i]);
        long long ans = 0;
        sort(arr, arr+n);
        for(int i=n-1;i>=k-1;i--)
        {
            ans = (ans + (arr[i]*combinations(i,k-1))%M)%M;
        }

        cout<<"Case #"<<c<<": "<<ans<<endl;
    }
}
