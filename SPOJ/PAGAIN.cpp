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
#define MAXX 65536
int sieve[MAXX+4];
int cnt = 0;
int primes[6550];
bool isPrime(unsigned int n)
{
    if(n==1)
    return 0;
  int len=cnt;
  int limit=sqrt(n);
  for(int i=0;i<len && primes[i]<=limit;i++)
    if(n%primes[i]==0)
      return false;
    return true;
}
void generatePrimes()
{
    for(int i=2;i<=MAXX;i++)
    {
        if(!sieve[i])
        {
            primes[cnt++] = i;
            for(long long j = i*(long long)i;j<=MAXX;j+=i)
                sieve[j] = 1;
        }
    }
}
long long n;
unsigned int N;
int main()
{
    generatePrimes();
    in_T
    {
        in_L(n);
        if( n > 4294967291LL )
        {
            printf("4294967291\n");
            continue;
        }
        N = n;
        n--;
        if(n!=2 && n%2 == 0)n--;
        while(!isPrime(n))
        {
            n-=2;
        }
        printf("%lld\n", n);
    }
}
