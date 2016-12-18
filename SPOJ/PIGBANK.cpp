#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
static long long dp[10005];
long long min(long long a,long long b)
{
	if(a==-1)
		return b;
	if(b==-1)
		return a;
	return a<b?a:b;
}
long long get_min(vector< pair <int,int> > &coins, int n, int W)
{
	long long val=-1;
	if(W==0)
		return 0;
	if(dp[W]!=-2)
		return dp[W];
	for(int i=0;i<n && (W-coins[i].first)>=0;i++)
	{
		long long x=get_min(coins,n,W-coins[i].first);
		if(x!=-1)
		val=min(val,coins[i].second+x);
	}
	dp[W]=val;
	return val;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int w1,w2,W;
		cin>>w1>>w2;
		W=w2-w1;
		int n;
		cin>>n;
		for(int i=1;i<=W;i++)
			dp[i]=-2;
		vector < pair <int,int> > coins(n);
		for(int i=0;i<n;i++)
		{
			int value,weight;
			cin>>value>>weight;
			coins[i].first=weight;
			coins[i].second=value;
		}
		sort(coins.begin(),coins.end());
		long long result=get_min(coins,n,W);
		if(result==-1)
			cout<<"This is impossible.\n";
		else
			cout<<"The minimum amount of money in the piggy-bank is "<<result<<".\n";
	}
	return 0;
}
