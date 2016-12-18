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
struct Edge{
    // u -> v
    int u, v, cap, flow, rev;
    Edge(int u, int v, int cap, int flow, int rev):u(u),v(v),cap(cap),flow(flow), rev(rev){}
    int rcap(){return cap-flow;}
};

struct Graph{
    // Always numbered 0-based index
    int s, t, N;
    vector<vector<Edge>> neigh;
    Graph(int N):neigh(N),N(N){}

    void addEdge(int u, int v, int cap){
        neigh[u].push_back(Edge(u, v, cap, 0, neigh[v].size()));
        neigh[v].push_back(Edge(v, u, cap, 0, neigh[u].size()-1));
    }
};


namespace dinic {
    const int INF = 1e9;
    int dfs(int idx, int flow, vector<vector<Edge *>> &neigh, Graph &g, int sink, int par=-1){
        if(idx == sink)
            return flow;
        int totalFlowPassed = 0;
        for(Edge *e: neigh[idx]){
            if(e->v != par && e->rcap() >= 0){
                int flowPassed = dfs(e->v, min(flow, e->rcap()), neigh, g, sink, idx);
                flow -= flowPassed;
                // e->cap -= flowPassed;
                e->flow += flowPassed;
                // g.neigh[e->v][e->rev].cap += flowPassed;
                g.neigh[e->v][e->rev].flow -= flowPassed;
                totalFlowPassed += flowPassed;
            }
        }
        return totalFlowPassed;
    }
    long long getBlockingFlow(Graph &g){
        // Generate a Level Graph
        queue<int> BFS;
        vector<vector<Edge *>> g_L(g.N);
        int dist[g.N];
        memset(dist, -1, sizeof(dist));
        BFS.push(g.s);
        dist[g.s] = 0;
        while(!BFS.empty()){
            int u = BFS.front();
            BFS.pop();
            for(Edge &e: g.neigh[u]){
                if(e.rcap() <= 0)continue;
                if(dist[e.v] == -1){
                    dist[e.v] = dist[u]+1;
                    BFS.push(e.v);
                }
                // if(dist[e.v] == dist[u] + 1){
                if(dist[e.v] > dist[u]){
                    g_L[u].push_back(&e);
                }
            }
        }
        if(dist[g.t] == -1)return 0;

        // Blocking flow
        return dfs(g.s, INF, g_L, g, g.t);
    }
    long long getMaxFlow(Graph &g){
        long long maxflow = 0;
        while(long long blockingFlow = getBlockingFlow(g)){
            maxflow += blockingFlow;
        }
        return maxflow;
    }
}
int res[53][53];
int foo(char ch){
    if(ch >= 'a')
        return 27+ch-'a';
    return 1+ch-'A';
}
int main()
{
    int n, c;
    char ch1, ch2;
    in_I(n);
    memset(res, 0, sizeof(res));
    while(n--){
        while((ch1 = getchar()) < 'A');
        while((ch2 = getchar()) < 'A');
        in_I(c);
        if(ch1 < ch2)
            swap(ch1, ch2);
        res[foo(ch1)][foo(ch2)] += c;
    }
    Graph g(60);
    g.s = 1;
    g.t = 26;
    for(int i = 0;i<53;i++){
        for(int j = 0;j<53;j++)
            if(res[i][j])
                g.addEdge(i, j, res[i][j]);
    }
    printf("%d\n", dinic::getMaxFlow(g));
}
