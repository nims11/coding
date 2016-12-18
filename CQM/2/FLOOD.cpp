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
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<stack>
#include<set>
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
char grid[101][101];
int r, c;
bool visited[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main()
{
    in_T
    {
        in_I(r);
        in_I(c);
        for(int i = 0 ;i<r; i++)
            in_S(grid[i]);
        for(int i = 0 ;i<r; i++)
            for(int j = 0; j<c; j++)
            visited[i][j] = 0;
        int ans = 0;
        for(int i = 0 ;i<r; i++)
            for(int j = 0; j<c; j++)
            {
                if(!visited[i][j])
                {
                    queue<pair<int, int> > BFS;
                    BFS.push(make_pair(i, j));
                    visited[i][j] = 1;
                    bool flag = true;
                    while(!BFS.empty())
                    {
                        pair<int, int> xy = BFS.front();
                        BFS.pop();
                        int a = xy.first, b = xy.second;
                        for(int z = 0; z<4; z++)
                        {
                            int x = a + dx[z];
                            int y = b + dy[z];
                            if(x >= 0 && y >= 0 && x<r && y<c)
                            {
                                if(grid[x][y]<grid[a][b])
                                {
                                    flag = false;
                                }
                                if(grid[x][y] == grid[a][b] && !visited[x][y])
                                {
                                    visited[x][y] = 1;
                                    BFS.push(make_pair(x, y));
                                }
                            }
                        }
                    }
                    ans += flag;
                }
            }
        printf("%d\n", ans);
    }
}
