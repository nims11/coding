/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int n,m, grid[100][100], height[100][100];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
pair<int, int> tmp;
int main()
{
    in_T
    {
        in_I(n);in_I(m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                in_I(grid[i][j]);
        for(int i=1;i<n-1;i++)
            for(int j=1;j<m-1;j++)
                height[i][j]=100000;
        for(int i=0;i<m;i++)
            height[0][i]=grid[0][i], height[n-1][i]=grid[n-1][i];
        for(int i=0;i<n;i++)
            height[i][0]=grid[i][0], height[i][m-1] = grid[i][m-1];
        queue<pair<int, int> > BFS;
        int minh,x,y;

        for(int i=0;i<m;i++)
            BFS.push(make_pair(0,i)), BFS.push(make_pair(n-1,i));
        for(int i=1;i<n-1;i++)
            BFS.push(make_pair(i,0)), BFS.push(make_pair(i,m-1));
        while(!BFS.empty())
        {
            tmp = BFS.front();
            BFS.pop();
            x = tmp.first, y = tmp.second;
            for(int i=0;i<4;i++)
            {
                int x1 = x+dir[i][0],y1 = y+dir[i][1];
                if(x1>0 && x1<n && y1>0 && y1<m)
                {
                    if(height[x1][y1]>height[x][y])
                    {
                        if(height[x1][y1]==grid[x1][y1])
                        {

                        }else
                        {
                            height[x1][y1] = height[x][y];
                            if(height[x1][y1]<grid[x1][y1])
                                height[x1][y1] = grid[x1][y1];
                            BFS.push(make_pair(x1,y1));
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                if(height[i][j]>grid[i][j])
                    ans+=height[i][j]-grid[i][j];
            }
        }
        cout<<ans<<endl;
    }
}
