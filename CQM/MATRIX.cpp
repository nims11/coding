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
char grid[54][54];
int t1[54][54], t2[54][54];
const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int main()
{
    int n, m;
    while(cin>>n>>m)
    {
        pair<int, int> st;
        for(int i=0; i<n;i++)
        {
            in_S(grid[i]);
            for(int j=0; grid[i][j]; j++)
            {
                if(grid[i][j] == '$')
                    st = make_pair(i, j);
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                t1[i][j] = t2[i][j] = INF;
        queue<pair<int, int> > BFS;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j] == 'F')
                    BFS.push(make_pair(i, j)), t1[i][j] = 0;
        while(!BFS.empty())
        {
            pair<int, int> tmp = BFS.front();
            BFS.pop();
            for(int i=0;i<4;i++)
            {
                int x = tmp.first + dx[i], y = tmp.second + dy[i];
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y] != '#' && t1[x][y]>t1[tmp.first][tmp.second]+1)
                {
                    t1[x][y] = t1[tmp.first][tmp.second]+1;
                    BFS.push(make_pair(x, y));
                }
            }
        }
        BFS.push(make_pair(st.first, st.second));
        t2[st.first][st.second] = 0;
        while(!BFS.empty())
        {
            pair<int, int> tmp = BFS.front();
            BFS.pop();
            for(int i=0;i<4;i++)
            {
                int x = tmp.first + dx[i], y = tmp.second + dy[i];
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y] != '#' && t2[x][y]>t2[tmp.first][tmp.second]+1)
                {
                    t2[x][y] = t2[tmp.first][tmp.second]+1;
                    BFS.push(make_pair(x, y));
                }
            }
        }
        int res = -INF;
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++)
            {
                if(t1[i][j] == INF && t2[i][j] != INF)
                {
                    res = -1;
                    i = n;
                    break;
                }else if(t1[i][j] != INF && t2[i][j] != INF)
                {
                    if(t1[i][j]>t2[i][j])
                        res = max(res, t1[i][j]);
                }
            }
        if(res == -INF)
            cout<<-1<<endl;
        else
            cout<<res<<endl;
    }
}
