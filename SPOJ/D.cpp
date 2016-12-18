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
#include<climits>
using namespace std;
#define INF INT_MAX
int main()
{
    int n,m,a,b,c;
    in_I(n);
    in_I(m);
    long long adj[n+1][n+1];
    for(i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            adj[i][j] = INF;
    for(int i=1;i<=n;i++)
        adj[i][i] = 0;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d", &a,&b,&c);
        adj[a][b] = c;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(adj[i][k]+adj[k][j]<adj[i][j])
                adj[i][j] = adj[i][k]+adj[k][j];

    int max2[n+1][2];
    for(int i=1;i<=n;i++)
    {
        max2[i][0] = max2[i][1] = adj[i][1];
        for(int j=2;j<=n;j++)
        {
            if(adj[i][j]>=max2[i][0])
            {
                max2[i][1] = max2[i][0];
                max2[i][1] = adj[i][j];
            }else
            {
                if(adj[i][j]>max2[i][1])
                {
                    max2[i][1] = adj[i][j];
                }
            }
        }
    }
    int ans =INF;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            int x,y,a,b;
            x =
        }
    }
}
