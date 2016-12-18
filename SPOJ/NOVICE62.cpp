/*
 * DP
 * Use the recurrence a(n)=n*a(n-1) + (-1)^n
 Recurrence relation for derangements
 */
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int dp[1000001];
int M=1000000007;
int getans(int n)
{
	if(dp[n]!=-1)return dp[n];
	dp[n] = (((long long)n)*getans(n-1)%M + (n%2?-1:1))%M;
	return dp[n];
}
int main()
{
    int t;
    dp[0]=1;
    dp[1]=0;
    for(long long i=2;i<=1000000;i++)
    {
	    dp[i]=((i*dp[i-1])%M + (i%2?-1:1))%M;
    }
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
}
