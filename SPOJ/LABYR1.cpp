/*
 * Same as PT07Z
 Longest Path in a Tree
 */
#include<cstdio>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
int ddx[4]={0,0,1,-1};
int ddy[4]={1,-1,0,0};
char grid[1005][1005];
bool visited[1005][1005];
int max2[1005][1005][2];
int maxn;
int r,c;
int DFS(int s_i,int s_j)
{
    visited[s_i][s_j]=true;

    for(int i=0;i<4;i++)
    {
        int x=s_i+ddx[i];int y=s_j+ddy[i];
        if((x>=0 && x<r && y>=0 && y<c) && grid[x][y]=='.' && !visited[x][y])
        {
            int m=DFS(x,y);
            if(m>max2[s_i][s_j][0])
            {
                max2[s_i][s_j][1]=max2[s_i][s_j][0];
                max2[s_i][s_j][0]=m;
            }else
            if(max2[s_i][s_j][1]<m)
            max2[s_i][s_j][1]=m;
        }
    }

    int tmp=max2[s_i][s_j][0]+max2[s_i][s_j][1];
    if(tmp>maxn)
    maxn=tmp;
    return max2[s_i][s_j][0]+1;
}
int main()
{
    in_T
    {
        in_I(c);in_I(r);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            visited[i][j]=max2[i][j][0]=max2[i][j][1]=0;
        }
        maxn=0;

        for(int i=0;i<r;i++)
        in_S(grid[i]);

        int start_i,start_j;
        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        if(grid[i][j]=='.'){start_i=i;start_j=j;break;}
        DFS(start_i,start_j);
        printf("Maximum rope length is %d.\n",maxn);
    }
}





