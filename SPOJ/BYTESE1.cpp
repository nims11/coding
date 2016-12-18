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
int grid[100][100];
int dp[100][100];
const int INF = 2000000000;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main()
{
    in_T
    {
        int m,n,a,b,T;
        in_I(m);in_I(n);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            in_I(grid[i][j]), dp[i][j] = INF;
        in_I(a);in_I(b);in_I(T);
        queue< pair<int, int> > BFS;
        pair<int, int> x;
        BFS.push(make_pair(0,0));
        dp[0][0] = 0;
        while(!BFS.empty())
        {
            x = BFS.front();
            BFS.pop();
            int T = dp[x.first][x.second] + grid[x.first][x.second];
//            cout<<x.first<<" "<<x.second<<endl;
            for(int i=0;i<4;i++)
            {
                int X = x.first+dx[i], Y = x.second+dy[i];
                if(X>=0 && Y>=0 && X<m && Y<n)
                {
                    if(T<dp[X][Y])
                    {
                        dp[X][Y] = T;
                        BFS.push(make_pair(X,Y));
                    }
                }
            }
        }
        int ans = dp[a-1][b-1] + grid[a-1][b-1];
        if(T-ans>=0 && dp[a-1][b-1] != INF)
        {
            printf("YES\n%d\n", T-ans);
        }else
            printf("NO\n");
    }
}
