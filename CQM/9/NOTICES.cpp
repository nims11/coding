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
int n,m,s,x,y,z;
vector<int> hostels;
vector<pair<int, int> > neigh[100001];
long long d[15][15];
const long long INF = 1000000000000000LL;
void bfs(int st){
    long long dist[n];
    for(int i = 0;i<n;i++)
        dist[i] = INF;
    dist[hostels[st]] = 0;
    queue<int> BFS;
    BFS.push(hostels[st]);
    while(!BFS.empty()){
        int cur = BFS.front();
        BFS.pop();
        for(int i=0;i<neigh[cur].size();i++){
            if(dist[cur]+neigh[cur][i].second < dist[neigh[cur][i].first]){
                dist[neigh[cur][i].first] = dist[cur]+neigh[cur][i].second;
                BFS.push(neigh[cur][i].first);
            }
        }
    }
    for(int i = 0;i<hostels.size();i++){
        d[i][st] = d[st][i] = dist[hostels[i]];
    }
}
long long dp[12][1<<12];
long long getans(int x, int mask = 0){
    if(dp[x][mask] != -1)
        return dp[x][mask];

    mask |= (1<<x);
    long long &ret = dp[x][mask];
    ret = INF;
    for(int i = 0;i<=s;i++){
        if(!(mask&(1<<i))){
            ret = min(ret, d[x][i]+getans(i, mask));
        }
    }
    if(ret == INF){
        ret = d[x][0];
    }
    return ret;
}
int main()
{
    while(in_I(n) != EOF){
        in_I(m);
        hostels.clear();
        for(int i = 0;i<n;i++)neigh[i].clear();
        while(m--){
            in_I(x);in_I(y);in_I(z);
            neigh[x].push_back(make_pair(y, z));
            neigh[y].push_back(make_pair(x, z));
        }
        hostels.push_back(0);
        in_I(s);
        for(int i = 0;i<s;i++)
        {
            in_I(x);
            hostels.push_back(x);
        }
        for(int i = 0;i<s+1;i++){
            for(int j = 0;j<s+1;j++)d[i][j] = INF;
            d[i][i] = 0;
        }
        for(int i = 0;i<s+1;i++){
            bfs(i);
        }
        for(int i = 0;i<=s;i++)
            for(int j = 0;j<=s;j++)
            for(int k = 0;k<=s;k++)
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
        for(int i = 0;i<=s;i++){
            for(int j = (1<<(s+1));j>=0;j--)
                dp[i][j] = -1;
        }
        printf("%lld\n", getans(0));
    }
}
