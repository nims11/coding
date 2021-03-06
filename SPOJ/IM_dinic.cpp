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

const int INF = 2000000000;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<int> Q;
  
  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}
  
  void AddEdge(int from, int to, int cap) {
      G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
      if (from == to) G[from].back().index++;
      G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }

  long long BlockingFlow(int s, int t) {
      fill(dad.begin(), dad.end(), (Edge *) NULL);
      dad[s] = &G[0][0] - 1;
      
      int head = 0, tail = 0;
      Q[tail++] = s;
      while (head < tail) {
            int x = Q[head++];
            for (int i = 0; i < G[x].size(); i++) {
                Edge &e = G[x][i];
                if (!dad[e.to] && e.cap - e.flow > 0) {
                      dad[e.to] = &G[x][i];
                      Q[tail++] = e.to;
                    }
                  }
          }
      if (!dad[t]) return 0;
  
      long long totflow = 0;
      for (int i = 0; i < G[t].size(); i++) {
            Edge *start = &G[G[t][i].to][G[t][i].index];
            int amt = INF;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
                if (!e) { amt = 0; break; }
                amt = min(amt, e->cap - e->flow);
                  }
            if (amt == 0) continue;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
                e->flow += amt;
                G[e->to][e->index].flow -= amt;
                  }
            totflow += amt;
          }
      return totflow;
    }

  long long GetMaxFlow(int s, int t) {
      long long totflow = 0;
      while (long long flow = BlockingFlow(s, t))
        totflow += flow;
      return totflow;
    }
};
int main(){
    in_T{
        int n, m;
        scanf("%d%d", &n, &m);
        Dinic g(n+1);
        for(int i = 0;i<m;i++){
            int u, v;
            scanf("%d%d", &u, &v);
            g.AddEdge(u, v, 1);
        }
        g.AddEdge(0, 1, 1);
        g.AddEdge(0, 3, 1);
        // cout<<dinic::getMaxFlow(g)<<endl;
        printf(g.GetMaxFlow(0, 2) >= 2?"YES\n":"NO\n");
    }
}
