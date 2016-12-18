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
int n;
struct edge{
    int u, v, c;
    int numNodes;
}edges[100010];
vector<int> adj[100010];
int visited[100010];
int dfs(int u){
    int ret = 1;
    for(int i = 0;i<adj[u].size();i++){
        edge & E = edges[adj[u][i]];
        int v = (u==E.u?E.v:E.u); 
        if(!visited[v]){
            visited[v] = 1;
            E.numNodes = dfs(v);
            ret += E.numNodes;
        }
    }
    return ret;
}
int main()
{
    int u, v, c;
    in_I(n);
    for(int i = 0;i<n-1;i++){
        in_I(u);in_I(v);in_I(c);
        edges[i+1].u = u, edges[i+1].v = v, edges[i+1].c = c;
        edges[i+1].numNodes=0;
        adj[u].push_back(i+1);
        adj[v].push_back(i+1);
    }
    int q;
    in_I(q);
    double curAns = 0;
    visited[1] = 1;
    dfs(1);
    double NN = (n*1LL*(n-1)*1LL*(n-2));
    for(int i = 1;i<=n-1;i++){
        long long x = edges[i].numNodes;
        long long y = n-x;
        int c = edges[i].c;
        curAns += 6*c*(x*(x-1)*y)/NN;
        swap(x, y);
        curAns += 6*c*(x*(x-1)*y)/NN;
    }
    int X, Y;
    while(q--){
        in_I(X);
        in_I(Y);
        int diff = edges[X].c-Y;
        edges[X].c = Y;

        long long x = edges[X].numNodes;
        long long y = n-x;
        int c = diff;
        curAns -= 6*c*(x*(x-1)*y)/NN;
        swap(x, y);
        curAns -= 6*c*(x*(x-1)*y)/NN;
        printf("%.10lf\n", curAns);
    }
}
