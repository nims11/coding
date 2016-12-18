#include<iostream>
using namespace std;
int main()
{
	long a[3];
	cin>>a[0]>>a[1]>>a[2];
	while(a[0]!=0 && a[1]!=0 && a[2]!=0)
	{
		for(int i=0;i<3;i++)
			for(int j=i+1;j<3;j++)
				if(a[j]<a[j-1])
				{
					long tmp=a[j];
					a[j]=a[j-1];
					a[j-1]=tmp;
				}
		if(a[2]*a[2]==a[0]*a[0]+a[1]*a[1])
			cout<<"right\n";
		else
			cout<<"wrong\n";
		cin>>a[0]>>a[1]>>a[2];
	}
	return 0;
}
