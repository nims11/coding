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
int r, c;
char grid[1002][1002];
int visited[1002][1002];
int dx[] = {0, 0, 1, -1};
pair<int, pair<int, int> >  tmp;
int dy[] = {1, -1, 0, 0};
const int INF = 1000000000;
int main()
{
    in_I(r);
    in_I(c);
    pair<int, int> S, E;
    for(int i=0;i<r;i++)
    {
        in_S(grid[i]);
        for(int j=0;j<c;j++)
            if(grid[i][j] == 'S')
                S = make_pair(i, j);
            else if(grid[i][j] == 'E')
                E = make_pair(i, j);
    }
    int ans = INF;
    for(int a = 0;a<r;a++)
    {
        for(int b=0;b<c;b++)
            visited[a][b] = INF;
    }
    queue<pair<int, pair<int, int> > > BFS;
    BFS.push(make_pair(0, E));
    visited[E.first][E.second] = 0;
    while(!BFS.empty())
    {
        tmp = BFS.front();
        BFS.pop();
        for(int i=0;i<4;i++)
        {
            int x = tmp.second.first + dx[i],
                y = tmp.second.second + dy[i];
            if(x>=0 && x<r && y>=0 && y<c && grid[x][y] != 'T' && visited[x][y]>tmp.first + 1)
            {
                visited[x][y] = tmp.first + 1;
                BFS.push(make_pair(tmp.first+1, make_pair(x, y)));
            }
        }
    }
    int ss = visited[S.first][S.second];
    ans = 0;
    for(int i=0;i<r;i++)
    {for(int j=0;j<c;j++)
    {
//        cout<<visited[i][j]<<" ";
        if(grid[i][j]>='0' && grid[i][j]<='9' && visited[i][j]<=ss)
        {
            ans += grid[i][j]-'0';
        }
    }
//    cout<<endl;
    }
    cout<<ans<<endl;
}
