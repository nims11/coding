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
int dp[101][101];
//vector<pair<int, int> > neigh[101];
int adj[101][101];
int N, M;
const int INF = 1e9;
int getans(int city, int turns)
{
    if(dp[city][turns] != INF)
        return dp[city][turns];
    int &ret = dp[city][turns];
    if(turns == 0)
        return (ret = INF-1);

    for(int i = 0; i<N; i++)
    {
        if(adj[city][i] != INF)
        {
            int x = getans(i, turns-1);
            if(x != INF)
                ret = min(ret, adj[city][i] + x);
        }
    }
    return ret;
}
int x,y,z;
int main()
{
    in_T
    {
        in_I(N);in_I(M);
        for(int i = 0; i<N;i++)
            for(int j = 0;j<N;j++)
            adj[i][j] = INF;
        for(int i = 0;i<M;i++)
        {
            in_I(x);in_I(y);in_I(z);
            adj[y][x]  = min(z, adj[y][x]);
        }
        for(int i = 0;i<N;i++)
            for(int j = 0;j<=N;j++)
                dp[i][j] = INF;
        dp[0][0] = 0;
        for(int i = 1;i<N;i++)
        {
            for(int j = 1;j<=N;j++)
            {
                for(int k = 0;k<N;k++)
                    if(adj[i][k] != INF && dp[k][j-1] != INF)
                        dp[i][j] = min(dp[i][j], dp[k][j-1]+adj[i][k]);
            }
        }
        for(int i = 1;i<=N;i++)
            dp[N-1][i] = min(dp[N-1][i], dp[N-1][i-1]);
        int Q;
        in_I(Q);
        while(Q--)
        {
            in_I(x);
            y = dp[N-1][x+1];
            if(y != INF)
                printf("%d\n", y);
            else
                printf("Not Possible\n");
        }
    }
}
