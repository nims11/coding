//GQ
/*
Objective: To find the longest path containing consecutive letters staring from 'A' in a given grid.

Solution: Simple application of DFS+DP
*/
#include<cstdio>
#define DM(a,b) if(grid[a][b]==x+1){k=DFS(grid,a,b,dp);if(k>ans)ans=k;}
int DFS(char grid[][52],int i,int j,int dp[][52])
{
    if(dp[i][j]!=0)
    return dp[i][j];

    int ans=0,k;
    int x=grid[i][j];
    DM(i-1,j-1)
    DM(i-1,j)
    DM(i-1,j+1)
    DM(i,j-1)
    DM(i,j+1)
    DM(i+1,j-1)
    DM(i+1,j)
    DM(i+1,j+1)

    dp[i][j]=ans+1;
    return ans+1;
}
int main()
{
    int r,c;
    int curr=1;
    while(1)
    {
        char grid[52][52]={{0}};
        int dp[52][52]={{0}};
        scanf("%d%d",&r,&c);
        if(r==0)return 0;
        for(int i=1;i<=r;i++)
        {
            scanf("%s",grid[i]+1);
        }
        int max=0;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                if(grid[i][j]=='A')
                {
                    int k=DFS(grid,i,j,dp);
                    if(k>max)max=k;
                }
            }
        }
        printf("Case %d: %d\n",curr,max);
        curr++;
    }
}
