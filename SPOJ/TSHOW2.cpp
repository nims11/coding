#include<iostream>
#include<vector>
using namespace std;
bool search_pair(vector <int> &x,int a,int b)
{
	for(int i=0;i<x.size()-1;i++)
		if(x[i]==a && x[i+1]==b)
			return true;
	return false;
}
int main()
{
	vector <int> fibo;
	fibo.push_back(0);
	fibo.push_back(1);
	int count=2;
	do{
		fibo.push_back((fibo[count-1]+fibo[count-2])%10);
		count++;
	}while(fibo[count-1]!=1 || fibo[count-2]!=0);
	int t;
	count-=2;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<fibo[(n-1)%count]<<endl;
	}
	return 0;
}
