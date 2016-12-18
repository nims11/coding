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
#define L long long
#define VVL vector<vector<long long> >
#define VL vector<long long>
#define VI vector<int>
#define VPII vector<pair<int, int> >
int N, K, P;
vector<int> neigh[1011];
int C[1011][32];
const L INF = numeric_limits<L>::max() / 4;

struct MinCostMaxFlow {
  int N;
  VVL cap, flow, cost;
  VI found;
  VL dist, pi, width;
  VPII dad;

  MinCostMaxFlow(int N) : 
    N(N), cap(N, VL(N)), flow(N, VL(N)), cost(N, VL(N)), 
    found(N), dist(N), pi(N), width(N), dad(N) {}
  
  void AddEdge(int from, int to, L cap, L cost) {
    this->cap[from][to] = cap;
    this->cost[from][to] = cost;
  }
  
  void Relax(int s, int k, L cap, L cost, int dir) {
    L val = dist[s] + pi[s] - pi[k] + cost;
    if (cap && val < dist[k]) {
      dist[k] = val;
      dad[k] = make_pair(s, dir);
      width[k] = min(cap, width[s]);
    }
  }

  L Dijkstra(int s, int t) {
    fill(found.begin(), found.end(), false);
    fill(dist.begin(), dist.end(), INF);
    fill(width.begin(), width.end(), 0);
    dist[s] = 0;
    width[s] = INF;
    
    while (s != -1) {
      int best = -1;
      found[s] = true;
      for (int k = 0; k < N; k++) {
        if (found[k]) continue;
        Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
        Relax(s, k, flow[k][s], -cost[k][s], -1);
        if (best == -1 || dist[k] < dist[best]) best = k;
      }
      s = best;
    }

    for (int k = 0; k < N; k++)
      pi[k] = min(pi[k] + dist[k], INF);
    return width[t];
  }

  pair<L, L> GetMaxFlow(int s, int t) {
    L totflow = 0, totcost = 0;
    while (L amt = Dijkstra(s, t)) {
      totflow += amt;
      for (int x = t; x != s; x = dad[x].first) {
        if (dad[x].second == 1) {
          flow[dad[x].first][x] += amt;
          totcost += amt * cost[dad[x].first][x];
        } else {
          flow[x][dad[x].first] -= amt;
          totcost -= amt * cost[x][dad[x].first];
        }
      }
    }
    return make_pair(totflow, totcost);
  }
};
long long dp[1011][32][32];
const long long inf = 1e18;
long long getans(int idx, int col, int parcol, int par=-1){
    if(dp[idx][col][parcol] != inf)
        return dp[idx][col][parcol];

    long long &ans = dp[idx][col][parcol];
    for(int i = 0;i<neigh[idx].size();i++){
        int v = neigh[idx][i];
        if(v != par){
            for(int c = 1;c<=K;c++){
                
            }
        }
    }
}
int main(){
    int z = 0;
    in_T{
        in_I(N);
        in_I(K);
        in_I(P);
        for(int i = 0;i<=N;i++)
            neigh[i].clear();

        for(int i = 1;i<=N;i++)
            for(int j = 1;j<=K;j++)
                in_I(C[i][j]);

        for(int i = 0;i<=N;i++)
            for(int j = 0;j<=K;j++)
                for(int k = 0;k<=K;k++)
                    dp[i][j][k] = inf;
        for(int i = 0;i<N-1;i++){
            int x, y;
            in_I(x);
            in_I(y);
            neigh[x].push_back(y);
            neigh[y].push_back(x);
        }
        long long ans = 1e18;
        for(int i = 1;i<=K;i++){
            ans = min(ans, getans(1, i, 0));
        }
        cout<<"Case #"<<(++z)<<": "<<ans<<endl;
    }
}
