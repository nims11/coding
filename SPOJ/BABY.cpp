
/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<cmath>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;
#define P_I(a) printf("%d",a)

using namespace std;
int n,curr[20],tar[20];int visited;
int dist[20][20];
int dp[1<<17][17];
int getans(int start)
{
	if(n==start)return 0;
	int &ans=dp[visited][start];
	if(ans==-1){
	    ans=1<<20;
		for(int j=0;j<n;j++)
		{
			if(((visited>>j)&1) == 0)
			{
				visited|=1<<j;
				ans=min(ans,dist[start][j]+getans(start+1));
				visited&=~(1<<j);
			}
		}
	}
	return ans;
}

int main()
{
	while(1)
	{
		in_I(n);
		while(!n)return 0;
		for(int i=0;i< 1<<n;i++)
			for(int j=0;j<n;j++)
				dp[i][j]=-1;

		visited=0;
		for(int i=0;i<n;i++)
		{
			in_I(curr[i]);
			curr[i]--;
		}
		for(int i=0;i<n;i++)
		{
			in_I(tar[i]);
			tar[i]--;
			for(int j=0;j<n;j++)
			{
				dist[j][i]=abs(i-j)+abs(tar[i]-curr[j]);
			}
		}

		printf("%d\n",getans(0));
	}
}
