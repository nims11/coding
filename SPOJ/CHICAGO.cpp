//GQ
/*
Given many 2-way streets with start and end coordinates and safety percentage, the objective is to find the path with highest safety.
perform a DFS. Instead of storing bool values in visited[i], store the current highest safety percentage from that path to end.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<map>

#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp3=a;a=b;b=tmp3;}
using namespace std;
struct street
{
    int i;
    int p;
};
int n,m,tmp1,tmp2,tmp3;
street tmps;
vector<street> neigh[200];
double visited[200];
void getans(int start)
{
    int ans=0;
    for(int i=0;i<neigh[start].size();i++)
    {
        street k=neigh[start][i];
        if(visited[k.i]<(visited[start]*k.p)/100)
        {
            visited[k.i]=(visited[start]*k.p)/100;
            getans(k.i);
        }
    }
}
int main()
{
    while(1)
    {
        in_I(n);
        if(n==0)return 0;
        in_I(m);
        for(int i=0;i<=n;i++)visited[i]=0,neigh[i].clear();
        for(int i=0;i<m;i++)
        {
            in_I(tmp1);in_I(tmp2);in_I(tmp3);
            tmps.i=tmp2;tmps.p=tmp3;
            neigh[tmp1].push_back(tmps);
            tmps.i=tmp1;
            neigh[tmp2].push_back(tmps);
        }
        visited[1]=100;
        getans(1);
        printf("%.6lf percent\n",visited[n]);
    }
}

