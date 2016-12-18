#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)

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
string vals[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char order_c[] = {'Z', 'X', 'S', 'V', 'F', 'W', 'O', 'N', 'R', 'E'};
int order_n[] = {0, 6, 7, 5, 4, 2, 1, 9, 3, 8};
int req[10][26];
int main(){
    int z = 0;
    for(int i = 0;i<10;i++){
        string s = vals[i];
        for(char c: s){
            req[i][c-'A']++;
        }
    }
    int t;
    cin>>t;
    for(z = 1;z<=t;z++){
        string s;
        cin>>s;
        int foo[26] = {0};
        for(int i = 0;i<s.length();i++)
            foo[s[i]-'A']++;
        int lt[10] = {0};
        for(int i = 0;i<10;i++){
            int n = order_n[i];
            int c = order_c[i]-'A';
            lt[n] = foo[c]/req[n][c];
            for(int j = 0;j<26;j++){
                foo[j] -= lt[n]*req[n][j];
            }
        }
        cout<<"Case #"<<z<<": ";
        for(int i = 0;i<10;i++){
            while(lt[i]){
                cout<<i;
                lt[i]--;
            }
        }
        cout<<endl;
        // Graph g(38);
        // g.s = 0;
        // g.t = 37;
        // for(int i = 0;i<26;i++){
        //     g.addEdge(0, i+1, foo[i]);
        //     for(int j = 27;j<27+10;j++){
        //         g.addEdge(i+1, j, )
        //     }
        // }
    }
}
