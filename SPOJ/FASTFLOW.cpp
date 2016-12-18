#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
int u[60010], v[60010], rev[60010], N, nxt[60010];
long long cap[60010], flow[60010];
int edgeCnt = 0;
int cacheEdge[5010][5010];
int adj[5010];
void addEdge(int u1, int v1, int cap1){
    if(u1 == v1)return;
    if(cacheEdge[u1][v1] != 0){
        int x = cacheEdge[u1][v1];
        cap[x] += cap1;
        x = cacheEdge[v1][u1];
        cap[x] += cap1;
    }else{
        u[++edgeCnt] = u1;
        v[edgeCnt] = v1;
        cap[edgeCnt] = cap1;
        rev[edgeCnt] = edgeCnt+1;
        cacheEdge[u1][v1] = edgeCnt;

        u[++edgeCnt] = v1;
        v[edgeCnt] = u1;
        cap[edgeCnt] = cap1;
        rev[edgeCnt] = edgeCnt-1;
        cacheEdge[v1][u1] = edgeCnt;

        nxt[edgeCnt-1] = adj[u1];
        adj[u1] = edgeCnt-1;

        nxt[edgeCnt] = adj[v1];
        adj[v1] = edgeCnt;
    }
}
int dist[5010];
int adj_L[5010][5010];
int cnt_L[5010];
long long dfs(int idx, long long fl, int par=-1){
    // vis[idx] = 1;
    // cout<<idx<<endl;
    if(idx == N)
        return fl;
    long long totalFlowPassed = 0;
    for(int i = 0; i<cnt_L[idx]; i++){
        int e = adj_L[idx][i];
        // cout<<v[e]<<endl;
        if(v[e] != par && cap[e]-flow[e] > 0){
            long long flowPassed = dfs(v[e], min(fl, cap[e]-flow[e]), idx);
            fl -= flowPassed;
            flow[e] += flowPassed;
            flow[rev[e]] -= flowPassed;
            totalFlowPassed += flowPassed;
        }
    }
    return totalFlowPassed;
}
long long getBlockingFlow(){
    // Generate a Level Graph
    queue<int> BFS;
    memset(dist, -1, sizeof(dist));
    memset(cnt_L, 0, sizeof(cnt_L));
    BFS.push(1);
    dist[1] = 0;
    while(!BFS.empty()){
        int x = BFS.front();
        BFS.pop();
        for(int e = adj[x];e;e=nxt[e]){
            if(cap[e] - flow[e] <= 0)continue;
            if(dist[v[e]] == -1){
                dist[v[e]] = dist[u[e]] + 1;
                BFS.push(v[e]);
            }
            if(dist[v[e]] == 1 + dist[u[e]])
                adj_L[u[e]][cnt_L[u[e]]++] = e;
        }
    }
    if(dist[N] == -1)return 0;

    // Blocking flow
    return dfs(1, 1e18);
}
long long getMaxFlow(){
    long long maxflow = 0;
    while(long long blockingFlow = getBlockingFlow()){
        maxflow += blockingFlow;
    }
    return maxflow;
}
int main()
{
    int M, A, B, C;
    in_I(N);in_I(M);
    for(int i = 0;i<M;i++){
        scanf("%d%d%d", &A, &B, &C);
        addEdge(A, B, C);
    }
    printf("%lld\n", getMaxFlow());
}
