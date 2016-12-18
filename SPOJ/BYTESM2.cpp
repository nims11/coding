//GQ
/*
dp: travelling in weighted paths
*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int grid[102][102],dp[102][102];
        int h,w;
        cin>>h>>w;
        for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
        cin>>grid[i][j];

        for(int i=0;i<=h+1;i++)
        dp[i][0]=dp[i][w+1]=0;


        for(int i=0;i<=w+1;i++)
        dp[0][i]=dp[h+1][i]=0;
        for(int i=1;i<=w;i++)
        dp[1][i]=grid[1][i];

        for(int i=2;i<=h;i++)
        {
            for(int j=1;j<=w;j++)
            {
                dp[i][j]=grid[i][j]+max(max(dp[i-1][j-1],dp[i-1][j]),dp[i-1][j+1]);
            }
        }
        int max=0;
        for(int i=1;i<=w;i++)
        if(dp[h][i]>max)max=dp[h][i];

        cout<<max<<endl;
    }
    return 0;
}
