/*
Objective: To find the nth number having atleast 3 distinct prime factors
Solution: Generate all required prime numbers and all solution. Then lookup the solutions in O(1) time.
*/
#include<iostream>
#include<cmath>
#include <vector>
using namespace std;
vector<int> primes;
int count=0;
int a[1000];
bool isPrime(int n)
{
    if(n==1)
    return false;
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
int main()
{
    generatePrimes(1500);
    for(int i=29;count<1000;i++)
    {//cout<<i<<endl;
        int primeC=0;
        for(int j=0;primes[j]<=i/2;j++)
        {
            if(i%primes[j]==0)
            {
                primeC++;
                if(primeC==3)
                {
                    a[count++]=i;
                    break;
                }
            }
        }

    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<a[n-1]<<endl;
    }
    return 0;
}
