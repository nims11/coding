#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<int> primes;

bool isPrime(long n)
{
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
    primes.push_back(i);
  }
}
int main()
{
  long t,n,n2;
  generatePrimes(500000);
  cin>>t;
  int len=primes.size();
  for(long z=0;z<t;z++)
  {
    cin>>n;
    //cout<<n<<endl;
    
    n2=n;
    cout<<"A "<<n<<endl;
    double num2=1,den=1;
    for(int i=0;primes[i]<=n && i<len;i++)
    {
      //int flag=0;
      if(n%primes[i]==0)
      {
	
      double x=primes[i];
      while(n%primes[i]==0)
      {
	n/=primes[i];
// 	if(flag==0)
// 	{den=den*(primes[i]-1);
// 	flag=1;x*=primes[i];}
	x*=primes[i];
      }
	num2*=(x-1);
	den*=(primes[i]-1);
      }
    }
    if(n>1)
    {num2=num2*(n*n-1);den*=(n-1);}
    long sum=num2/den-n2;
    cout<<sum<<endl;
  }
  return 0;
}
