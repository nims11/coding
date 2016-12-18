/*
    Nimesh Ghelani (nims11)
    given 1/N! = 1/x + 1/y , objective is to find number of positive integral solution of x and y
    arrange the equation as N!(x+y)-xy=0 --> N!(x+y)-xy+N!^2=N!^2 --> (N!-a)(N!-b)=N!^2
   number of solutions here are the total number of divisors of N!. calulate it after getting the prime factors and their powers in N!^2. 
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
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
vector<int> primes;
bool isPrime(long n)
{
    if(n==1)
    return 0;
  int len=primes.size();
  int limit=sqrt(n);
  for(int i=0;i<len && primes[i]<=limit;i++)
    if(n%primes[i]==0)
      return false;
    return true;
}
void generatePrimes(long n)
{
  primes.push_back(2);
  for(long i=3;i<=n;i+=2)
  {
    if(isPrime(i))
    {primes.push_back(i);}
  }
}
const long long BASE=1000000;
const int BASE_pow=6;
int int_len(long long x)
{
    int count=0;
    do
    {
        x/=10;
        count++;
    }while(x!=0);
    return count;
}
void show(long long *n,int start)
{
    int i=start;
    for(;i>=0;i--)
    {
        int len=int_len(n[i]);
        for(int j=0;j<BASE_pow-len && i!=start;j++)
        printf("0");
        printf("%lld",n[i]);
    }
    printf("\n");
}
int n;
void getans()
{
    long long ans[10000];
    for(int i=0;i<10000;i++)
    ans[i]=0;
    ans[0]=1;
    int curr=0;

    for(int i=0;i<primes.size() && primes[i]<=n;i++)
    {
        int foo=0,bar=primes[i];
        while(n/bar!=0)
        {
            foo+=n/bar;
            bar*=primes[i];
        }
        foo=2*foo+1;
        int carry=0;
        for(int j=0;j<=curr;j++)
        {
            ans[j]=ans[j]*foo+carry;
            carry=ans[j]/BASE;
            ans[j]%=BASE;
        }
        if(carry)
        ans[++curr]=carry;
    }
    show(ans,curr);

}
int main()
{
    generatePrimes(50000);
    while(1)
    {
        in_I(n);
        if(n==0)return 0;
        getans();
    }
}


