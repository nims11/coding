/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
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
int foo1[] = {1,-1,0,0};
int foo2[] = {0,0, 1, -1};
int main()
{
    in_T
    {
        int n,m;
        in_I(n);in_I(m);
        char grid[n+1][m+1];
        for(int i=0;i<n;i++)
            in_S(grid[i]);
        int ans[n][m];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ans[i][j] = 1<<29;
        queue<pair<int, int> > BFS;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1')
                {
                    ans[i][j] = 0;
                    BFS.push(make_pair(i,j));
                }
            }
        while(!BFS.empty())
        {
            pair<int, int> tmp = BFS.front();
            BFS.pop();
            for(int i=0;i<4;i++)
            {
                int r = tmp.first + foo1[i];
                int c = tmp.second + foo2[i];
                if(r>=0 && r<n && c>=0 && c<m)
                {
                    if(ans[r][c]>ans[tmp.first][tmp.second]+1)
                    {
                        ans[r][c]=ans[tmp.first][tmp.second]+1;
                        BFS.push(make_pair(r,c));
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                printf("%d", ans[i][j]);
                if(j!=m-1)printf(" ");
            }
            newline;
        }
    }
}
