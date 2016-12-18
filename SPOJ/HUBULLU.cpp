#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b;
		cin>>a>>b;
		if(b==0)
			cout<<"Airborne wins\n";
		else
			cout<<"Pagfloyd wins\n";
	}
}
