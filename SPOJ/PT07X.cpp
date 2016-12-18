/*
    Nimesh Ghelani (nims11)
    DP
    for each node, store the minimum size of vertex set if that node is included or not included.
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
vector<int> neigh[100000];
int n;
int dp[100000][2];
void getans(int node, int from)
{
//    cout<<node<<endl;
        dp[node][0] = 0;
        dp[node][1] = 1;
    for(int i=0;i<neigh[node].size();i++)
    {
        if(neigh[node][i]!=from)
        {
            if(dp[neigh[node][i]][0] == 1<<29)
                getans(neigh[node][i],node);
            dp[node][0] += dp[neigh[node][i]][1];
            dp[node][1] += min(dp[neigh[node][i]][1],dp[neigh[node][i]][0]);
        }
    }
}
int main()
{
    in_I(n);
    if(n==1){cout<<0<<endl;return 0;}
    int tmp1,tmp2;
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d",&tmp1,&tmp2);
        tmp1--,tmp2--;
        neigh[tmp1].push_back(tmp2);
        neigh[tmp2].push_back(tmp1);
    }
    for(int i=0;i<n;i++)
        dp[i][0] = dp[i][1] = 1<<29;
    getans(0,-1);
    cout<<min(dp[0][0],dp[0][1])<<endl;
}
