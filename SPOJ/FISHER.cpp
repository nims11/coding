/*
    Nimesh Ghelani (nims11)
    dp[i][j] - minimum cost of reaching city i in time<=j;
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
const int INF = 1<<29;

int main()
{
    int n, t, time[50][50], cost[50][50], dp[50][1001];
    while(1)
    {
        in_I(n);
        in_I(t);
        if(n==0)return 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            in_I(time[i][j]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            in_I(cost[i][j]);
        for(int i=0;i<n;i++)
            for(int j=0;j<=t;j++)
                dp[i][j] = INF;
        queue<pair<int, pair<int, int> > > BFS; //time, cost, city
        pair<int, pair<int, int> > tmp;
        BFS.push(make_pair(0, make_pair(0, 0)));
        while(!BFS.empty())
        {
            tmp = BFS.front();
            BFS.pop();
            for(int i=0;i<n;i++)
            {
                if(i!=tmp.second.second && tmp.first+time[tmp.second.second][i]<=t && dp[i][tmp.first+time[tmp.second.second][i]]>tmp.second.first+cost[tmp.second.second][i])
                {
                    for(int j=tmp.first+time[tmp.second.second][i];j<=t && dp[i][j]>tmp.second.first+cost[tmp.second.second][i];j++)
                        dp[i][j]=tmp.second.first+cost[tmp.second.second][i];
                    BFS.push(make_pair(tmp.first+time[tmp.second.second][i], make_pair(tmp.second.first+cost[tmp.second.second][i], i)));
                }
            }
        }
        int ti = t;
        int st = dp[n-1][t];
        while(ti>=0 && st==dp[n-1][ti])ti--;
        ti++;
        printf("%d %d\n", dp[n-1][t], ti);
    }
}
