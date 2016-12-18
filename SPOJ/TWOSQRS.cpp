#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<long> primes;
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
int main()
{
    generatePrimes(1000000);
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        bool flag=true;
        for(int i=0;primes[i]<=n && i<primes.size();)
        {
            int count=0;
            while(n%primes[i]==0)
            {
                count++;
                n/=primes[i];
            }
            if((primes[i]-3)%4==0)
            {
                if(count%2==1)
                {flag=false;
                break;}
            }
            i++;
        }
        if((n-3)%4==0)flag=false;
        if(flag)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
