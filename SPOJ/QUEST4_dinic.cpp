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
struct node{
    map<node*, int> edges;
}nodes[1000000];
int cnt = 0;
node* nxtNode(){
    nodes[cnt].edges.clear();
    return &nodes[cnt++];
}
const int INF = 150;
int max_flow_dinic(node *src, node *sink){
    int ret = 0;
    int prev[n+1];
    while(1){
        queue<int> BFS;
        memset(prev, 0, sizeof(prev));
        prev[src] = -1;
        BFS.push(src);
        while(!BFS.empty() && !prev[sink]){
            int curr = BFS.front();
            BFS.pop();
            for(int i = 1;i<=n;i++)
                if(!prev[i] && res[curr][i])
                    prev[i] = curr, BFS.push(i);
        }
        if(!prev[sink])
            break;
        for(int i = 1;i<=n; i++){
            if(res[i][sink] && prev[i]){
                int inc = res[i][sink];
                for(int u = prev[i], v = i; u>=0; inc = min(inc, res[u][v]), v = u, u = prev[u]);
                for(int u = i, v = sink; u>=0; res[u][v]-=inc, res[v][u]+=inc, v = u, u = prev[u]);
                ret += inc;
            }
        }
    }
    return ret;
}
int main()
{
    in_T
    {
        int n, x, y;
        in_I(n);
        cnt = 0;
        node *source = nxtNode(), *sink = nxtNode();
        node *row[120], *col[120];
        for(int i = 0;i<120;i++){
            row[i] = nxtNode(), col[i] = nxtNode();
            source->edges[row[i]] = 1;
            row[i]->edges[source] = 0;

            sink->edges[col[i]] = 0;
            col[i]->edges[sink] = 1;
        }
        for(int i = 0;i<n;i++){
            in_I(x);in_I(y);
            row[x]->edges[col[y]] = 1;
            col[y]->edges[row[x]] = 0;
        }
        printf("%d\n", max_flow(source, sink));
    }
}
