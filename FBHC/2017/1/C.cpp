#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;

int main(){
    int z = 0;
    in_T{
        z++;
        cout<<"Case #"<<z<<": ";
        int N, M, K;
        in_I(N);in_I(M);in_I(K);
        int adj[N+1][N+1];
        long long dist[N+1][K+1][3];
        int vis[N+1][K+1][3];
        memset(adj, -1, sizeof(adj));
        memset(dist, -1, sizeof(dist));
        memset(vis, -1, sizeof(vis));
        for(int i = 0;i<M;i++){
            int x, y, g;
            in_I(x);in_I(y);in_I(g);
            adj[x][y] = g;
            adj[y][x] = g;
        }
        int pickup[N+1][K+1];
        int delivery[N+1][K+1];
        memset(pickup, 0, sizeof(pickup));
        memset(delivery, 0, sizeof(delivery));
        for(int i = 0;i<K;i++){
            int s, d;
            in_I(s);in_I(d);
            pickup[s][i+1] = 1;
            delivery[d][i+1] = 1;
        }

        priority_queue<pair<long long, pair<int, pair<int, int>>>> dij;
        dij.push({0, {1, {0, 0}}});
        long long ans = -1;
        while(!dij.empty()){
            auto top = dij.top();
            dij.pop();
            long long cost = -top.first;
            int node = top.second.first;
            int done = top.second.second.first;
            int cur_load = top.second.second.second;
            if(done == K){
                ans = cost;
                break;
            }
            if(vis[node][done][cur_load] == -1){
                vis[node][done][cur_load] = 1;
                for(int i = 1;i<=N;i++){
                    if(adj[node][i] != -1 && vis[i][done][cur_load] == -1){
                        long long new_cost = adj[node][i] + cost;
                        if(dist[i][done][cur_load] == -1 || dist[i][done][cur_load] > new_cost){
                            dist[i][done][cur_load] = new_cost;
                            dij.push({-new_cost, {i, {done, cur_load}}});
                        }
                    }
                }
                // pickup
                if(cur_load != 2 && done+cur_load < K && pickup[node][done+cur_load+1]){
                    if(vis[node][done][cur_load+1] == -1){
                        long long new_cost = cost;
                        if(dist[node][done][cur_load+1] == -1 || dist[node][done][cur_load+1] > new_cost){
                            dist[node][done][cur_load+1] = new_cost;
                            dij.push({-new_cost, {node, {done, cur_load+1}}});
                        }
                    }
                }
                // delivery
                if(cur_load != 0 && done < K && delivery[node][done+1]){
                    if(vis[node][done+1][cur_load-1] == -1){
                        long long new_cost = cost;
                        if(dist[node][done+1][cur_load-1] == -1 || dist[node][done+1][cur_load-1] > new_cost){
                            dist[node][done+1][cur_load-1] = new_cost;
                            dij.push({-new_cost, {node, {done+1, cur_load-1}}});
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}
