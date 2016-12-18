
/*
    Nimesh Ghelani (nims11)
    to find the number of common divisors of 2 numbers

    find the number of proper divisors of GCD.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<cmath>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;
#define P_I(a) printf("%d",a)

using namespace std;

vector<int> primes;
bool isPrime(int n)
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
void generatePrimes(int n)
{
  primes.push_back(2);
  for(int i=3;i<=n;i+=2)
  {
    if(isPrime(i))
    {primes.push_back(i);}
  }
}
int GCD(int a,int b)
{
	while(b>0)
	{
	   int temp=a;
	   a=b;
	   b=temp%b;
	}
      return a;
}
int main()
{
	int a,b,c;
	generatePrimes(1000000);
	in_T
	{
		in_I(a);in_I(b);
		c = GCD(a,b);
		int ans=1,tmp,curr=0;
		while(c>1)
		{
			tmp=0;
			while(c%primes[curr]==0)
			{
				tmp++;
				c/=primes[curr];
			}
			ans*=tmp+1;
			curr++;
		}
		printf("%d\n",ans);
	}
}
