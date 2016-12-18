#include<iostream>
#include<cmath>
int main()
{
	long long n;
	while(std::cin>>n)
	{
		if(n==-1)
			return 0;
		n--;
		if(n%3==0)
		{
			n/=3;
			double x=sqrt(1+4*n);
			if(floor(x)!=ceil(x) || (long long)floor(x)%2==0)
				std::cout<<"N\n";
			else
			{
				std::cout<<"Y\n";
			}
		}
		else std::cout<<"N\n";
	}
	return 0;
}
