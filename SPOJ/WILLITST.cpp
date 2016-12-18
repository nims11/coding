#include<iostream>
using namespace std;
int main()
{
	long long unsigned n;
	cin>>n;
	while(n%2==0)
	{
		n/=2;
	}
	if(n==1)
		cout<<"TAK\n";
	else
		cout<<"NIE\n";
	return 0;
}
