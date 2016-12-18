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

using namespace std;
vector< pair<int, int> > vertices[50001];
bool visited[50001];
int max2[50001][2];
int maxn;
int DFS(int n, int dist)
{
    visited[n]=true;
    for(int i=0;i<vertices[n].size();i++)
    {
        if(!visited[vertices[n][i].first])
        {
            int x=DFS(vertices[n][i].first, vertices[n][i].second);
            if(x>max2[n][0]){max2[n][1]=max2[n][0];max2[n][0]=x;}
            else if(max2[n][1]<x)max2[n][1]=x;
        }
    }
    int tmp=max2[n][0]+max2[n][1];
    if(tmp>maxn)
    maxn=tmp;
    return max2[n][0]+dist;
}
int main()
{
    in_T{
        int n;
        in_I(n);
        for(int i=0;i<=n;i++)
        {
            visited[i] = max2[i][0] = max2[i][1] = 0;
            vertices[i].clear();
        }
        maxn = 0;
        for(int i=0;i<n-1;i++)
        {
            int x,y,z;
            scanf("%d%d%d", &x,&y,&z);
            vertices[x].push_back(make_pair(y,z));
            vertices[y].push_back(make_pair(x,z));
        }
        DFS(1, 0);
        printf("%d\n", maxn);
    }
	return 0;
}
