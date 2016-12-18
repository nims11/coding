#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> primes;
bool isPalin(int n)
{
int t1=n;
int t2=0;
while(t1>0)
{
    t2=t2*10+t1%10;
    t1/=10;
}
return t2==n;
}
bool isPrime(int n)
{
	int uLimit=sqrt(n);
	int size=primes.size();
	for(int i=1;primes[i]<=uLimit && i<size;i++)
	if(n%primes[i]==0)
	return false;
	return true;
}
int main()
{
	primes.push_back(2);

	int n;
	//cin>>n;
	n=99000;
	if(n%2==0)
	n++;
	int ul=sqrt(1003001);
	for(int i=3;i<=ul;i+=2)
	{
		if(isPrime(i))
		primes.push_back(i);
	}


	while(1)
	{
		if(isPrime(n))
		{
			if(isPalin(n))
			{
				cout<<n<<endl;
				return 0;
			}
		}
		n+=2;
	}
	return 0;
}
