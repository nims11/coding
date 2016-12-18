#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		int d;
		if(a+c==2*b)
			d=c+(b-a);
		else
			d=c*(b/a);
		cout<<d<<endl;
	}
	return 0;
}
