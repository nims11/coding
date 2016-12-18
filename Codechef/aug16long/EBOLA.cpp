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
int N, M, K, S;
int w[10010];
vector<int> neigh[10010];
const int INF = 1e9;
int dist[10010];
vector<int> revDist[10010];
int main(){
    in_I(N);in_I(M);in_I(K);in_I(S);
    for(int i = 0;i<N;i++){
        in_I(w[i+1]);
    }
    for(int i = 0;i<M;i++){
        int u, v;
        in_I(u);
        in_I(v);
        neigh[u].push_back(v);
        neigh[v].push_back(u);
    }
    for(int i = 1;i<=N;i++)
        dist[i] = INF;
    queue<int> bfs;
    bfs.push(S);
    dist[S] = 0;
    while(!bfs.empty()){
        int u = bfs.front();
        bfs.pop();
        for(int v: neigh[u]){
            if(dist[v] > 1 + dist[u]){
                dist[v] = 1 + dist[u];
                revDist[dist[v]].push_back(v);
                bfs.push(v);
            }
        }
    }
    vector<pair<int, int>> all;
    for(int i = 1;i<=N;i++)
        if(dist[i] != 0 && dist[i] != INF)
            all.push_back({w[i], i});
    sort(all.begin(), all.end());
    std::reverse(all.begin(), all.end());
    vector<int> sav;
    set<int> savSet;
    for(int t = 1;t<=K;t++){
        int cur = -1;
        for(int i=0;i<revDist[t].size();i++){
            if(cur == -1)
                cur = 0;
            if(w[revDist[t][i]] > w[revDist[t][cur]]){
                cur = i;
            }
        }
        if(cur != -1){
            sav.push_back(revDist[t][cur]);
            savSet.insert(revDist[t][cur]);
        }
    }
    int idx = 0;
    while(sav.size() < K && idx < all.size()){
        if(savSet.find(all[idx].second) == savSet.end()){
            sav.push_back(all[idx].first);
            savSet.insert(all[idx].first);
        }
        idx++;
    }
    while(sav.size() < K)
        sav.push_back(1);
    for(int i = 0;i<K;i++){
        if(1 <= sav[i]  && sav[i] <= N){
            cout<<sav[i]<<" ";
        }else
            cout<<1<<" ";
    }
    cout<<endl;
}
