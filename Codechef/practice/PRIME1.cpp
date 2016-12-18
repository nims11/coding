#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> primes;
bool isPrime(long n)
{
    if(n==1)
    return false;
	int uLimit=sqrt(n);
	int size=primes.size();
	for(int i=0;primes[i]<=uLimit && i<size;i++)
	if(n%primes[i]==0)
	return false;
	return true;
}
int main()
{
	primes.push_back(2);
	int ul=sqrt(1000000000);
	for(int i=3;i<=ul;i+=2)
	{
		if(isPrime(i))
		    primes.push_back(i);
	}

	int t;
	cin>>t;
	while(t--)
	{
	    long n,m;
	    cin>>m>>n;
	    if(m==2 || m==1)
	    {
	        cout<<2<<endl;
	        m=3;
	    }else
	    if(m%2==0)
	    m++;

	    for(long i=m;i<=n;i+=2)
	    if(isPrime(i))
	    cout<<i<<endl;
	    cout<<endl;
	}


	return 0;
}
