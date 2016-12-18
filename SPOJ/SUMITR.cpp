#include<iostream>
using namespace std;int main(){int t,n,i,j,dp[100][100];cin>>t;while(t--){cin>>n;for(i=0;i<n;i++){for(j=0;j<i+1;j++)cin>>dp[i][j];}for(i=n-2;i>=0;i--){for(j=0;j<i+1;j++){dp[i][j]+=max(dp[i+1][j],dp[i+1][j+1]);}}cout<<**dp<<"\n";}}
