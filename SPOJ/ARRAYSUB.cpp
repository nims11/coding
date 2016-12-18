/*
    max in a window
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector <int> arr;
	int n,k,tmp;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		arr.push_back(tmp);
	}
	cin>>k;
	int max=0,maxi;
	for(int i=0;i<k;i++)
		if(arr[i]>=max)
		{
			max=arr[i];
			maxi=i;
		}
	cout<<max<<" ";
	for(int i=k;i<n;i++)
	{
		if(maxi<=i-k)
		{
			max=0;
			int x=maxi;
			for(int j=i;j>x;j--)
				if(arr[j]>=max)
				{
					max=arr[j];
					maxi=j;
				}

		}else
		if(arr[i]>=max)
		{
			max=arr[i];
			maxi=i;
		}
		cout<<max<<" ";
	}
	cout<<endl;

	return 0;
}
