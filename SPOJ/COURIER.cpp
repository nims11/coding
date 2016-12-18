//GQ
/*
    Nimesh Ghelani (nims11)

    Floyd Warshall + DP(simple)
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
int n,m,b;
int x,y,z;
const int INF = 1<<20;
pair<int, int> jobs[12];
int cnt;
int adj[100][100];
int dist[100][100];
int dp[100][1<<13];
int floyd_warshall()
{
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    dist[i][j]=adj[i][j];

    for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
}
int getans(int curr, int mask)
{
    if(dp[curr][mask]!=-1)
        return dp[curr][mask];

//    cout<<curr<<" "<<mask<<endl;
    int & ans = dp[curr][mask];
    ans=INF;
    for(int i=0;i<cnt;i++)
    {
        if(mask & (1<<i))
        {
            int foo = dist[curr][jobs[i].first] + dist[jobs[i].first][jobs[i].second] + getans(jobs[i].second, mask & (~(1<<i)));
            ans = min(ans, foo);
        }
    }
    return ans;
}
int main()
{
    in_T
    {
        scanf("%d%d%d",&n,&m,&b);
        b--;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                adj[i][j]=INF;
        for(int i=0;i<n;i++)
            adj[i][i]=0;
        for(int i=0;i<m;i++)
        {
            in_I(x);in_I(y);
            in_I(adj[x-1][y-1]);
            adj[y-1][x-1]=adj[x-1][y-1];
        }
        floyd_warshall();
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                cout<<dist[i][j]<<" ";
//            }
//            newline;
//        }
        int k;
        in_I(k);
        cnt=0;
        while(k--)
        {
            scanf("%d%d%d",&x,&y,&z);
            while(z--)
            {
                jobs[cnt++] = make_pair(x-1,y-1);
            }
        }
        int mask = 0;
        for(int i=0;i<cnt;i++)
            mask |= 1<<i;
        for(int i=0;i<n;i++)
            {
                dp[i][0]=dist[b][i];
                for(int j=1;j<=mask;j++)
                dp[i][j]=-1;
            }
        printf("%d\n",getans(b,mask));
    }
}
