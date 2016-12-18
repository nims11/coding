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
int fact[800001];
int inv[400001];
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
int main()
{
    fact[1] = 1;
    fact[0] = 1;
    for(long long i=2;i<=800000;i++)
        fact[i] = (fact[i-1]*i)%M;
//    for(int i=0;i<400;i++)
//    combinations(4000,2000);
    for(int i=0;i<=400000;i++)
        inv[i] = degree(fact[i]);
    in_T
    {
        int n,m,a,b;
        scanf("%d%d%d%d", &n, &m, &a, &b);
        //int x=C(m+n, n) , z=C(b+n-a, b), y=C(b+n, b);
        int res = 0;
        for(int i=0;i<=m-b;i++)
        {
//            cout<<combinations(a-i-1+m-b, m-b)<<endl;
            res = (res+(combinations(a-1+m-b-i, m-b-i)*combinations(b+i+n-a, n-a))%M)%M;
        }
        printf("%d\n", res);
    }
}
