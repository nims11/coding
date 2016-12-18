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
int n;
char grid[1001][1001];
long long dp[1001][1001];
bool foo[1001][1001];
bool visited[1001][1001];
const int mod = (1LL<<31)-1;
bool getans1()
{
    dp[0][0] = 1;
    foo[0][0] = true;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
    {
        if(grid[i][j] == '#')
        {
            dp[i][j] = 0;
            foo[i][j] = false;
            continue;
        }
        if(i-1>=0)
        {
            dp[i][j] += dp[i-1][j];
            foo[i][j] |= foo[i-1][j];
        }
        if(j-1>=0)
        {
            dp[i][j] += dp[i][j-1];
            foo[i][j] |= foo[i][j-1];
        }
        dp[i][j] %= mod;
    }
    if(!foo[n-1][n-1])
        return false;
    printf("%lld\n", dp[n-1][n-1]);
}
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0, 0};
void getans2()
{
    visited[0][0] = true;
    queue<pair<int, int> > BFS;
    BFS.push(make_pair(0, 0));
    while(!BFS.empty())
    {
        pair<int, int> tmp = BFS.front();
        BFS.pop();
        for(int i=0;i<4;i++)
        {
            int x = tmp.first+dx[i], y = tmp.second+dy[i];
            if(x>=0 && x<n && y>=0 && y<n && !visited[x][y] && grid[x][y] != '#')
            {
                visited[x][y] = true;
                BFS.push(make_pair(x, y));
                if(x == n-1 && y == n-1)
                {
                    printf("THE GAME IS A LIE\n");
                    return;
                }
            }
        }
    }
    printf("INCONCEIVABLE\n");
}
int main()
{
    in_I(n);
    for(int i=0;i<n;i++)
    {
        in_S(grid[i]);
    }
    if(!getans1())
    {
        getans2();
    }
}
