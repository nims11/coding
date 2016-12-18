#include<iostream>
using namespace std;
int main()
{
	int X[4],Xp[4];
	while(cin>>X[0]>>X[1]>>X[2]>>X[3]>>Xp[0]>>Xp[1]>>Xp[2]>>Xp[3])
	{
		if(X[0]==-1)
			return 0;
		int max=0;
		for(int i=0;i<4;i++)
		{
			int n;
			if(X[i]%Xp[i]!=0)
				n=X[i]/Xp[i]+1;
			else
				n=X[i]/Xp[i];
			if(n>max)
				max=n;
		}
		for(int i=0;i<4;i++)
			cout<<Xp[i]*max-X[i]<<" ";
		cout<<"\n";
	}
	return 0;
}
