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
char str[100];
const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main()
{
    in_T
    {
        int r, c;
        in_I(r);
        in_I(c);
        int g[r][c];
        for(int  i =0; i<r;i++)
            {
                in_S(str);
                for(int z = 0; str[z]; z++)
                {
                    if(islower(str[z]))
                        g[i][z] = str[z] - 'a' + 26;
                    else
                        g[i][z] = str[z] - 'A';
                }
            }
        int thres, dark;
        in_I(thres);
        in_I(dark);
        int tmp[r][c], back[r][c];
        for(int i = 0; i<r; i++)
            for(int j = 0; j<c; j++)
                tmp[i][j] = INF;
        for(int i = 0; i<r; i++)
            for(int j = 0; j<c; j++)
                back[i][j] = INF;
        queue<pair<int, int> > BFS;
        BFS.push(make_pair(0, 0));
        back[0][0] = 0;
        while(!BFS.empty())
        {
            pair<int, int> t = BFS.front();
            BFS.pop();
            for(int i = 0; i<4; i++)
            {
                int x = t.first + dx[i], y = t.second + dy[i];
                if(x>=0 && x<r && y>=0 && y<c && (g[x][y]-g[t.first][t.second])*(g[x][y]-g[t.first][t.second]) <= thres*thres)
                {
                    int u = INF;
                    if(g[x][y]>=g[t.first][t.second])
                        u = 1;
                    else
                        u = (g[x][y]-g[t.first][t.second])*(g[x][y]-g[t.first][t.second]);
                    u+=back[t.first][t.second];
                    if(u<back[x][y])
                    {
                        back[x][y] = u;
                        BFS.push(make_pair(x, y));
                    }
                }
            }
        }

        BFS.push(make_pair(0, 0));
        tmp[0][0] = 0;
        int ans = 0;
        while(!BFS.empty())
        {
            pair<int, int> t = BFS.front();
            BFS.pop();
            if(tmp[t.first][t.second]+back[t.first][t.second] <= dark && ans<g[t.first][t.second])
                ans = g[t.first][t.second];
            for(int i = 0; i<4; i++)
            {
                int x = t.first + dx[i], y = t.second + dy[i];
                if(x>=0 && x<r && y>=0 && y<c && (g[x][y]-g[t.first][t.second])*(g[x][y]-g[t.first][t.second]) <= thres*thres)
                {
                    int u = INF;
                    if(g[x][y]<=g[t.first][t.second])
                        u = 1;
                    else
                        u = (g[x][y]-g[t.first][t.second])*(g[x][y]-g[t.first][t.second]);
                    u+=tmp[t.first][t.second];
                    if(u<tmp[x][y])
                    {
                        tmp[x][y] = u;
                        BFS.push(make_pair(x, y));
                    }
                }
            }
        }
        cout<<ans<<endl;

    }
}
