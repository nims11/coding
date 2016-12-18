/*
    Nimesh Ghelani (nims11)
*/
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
int n, m, s, t;
vector<int> fw[100010], bw[100010];
int u[100010], v[100010], l[100010];
long long dist2s[100010], dist2t[100010];
int depth[100010];
int dp[100010];
int vis[100010];
int par[100010];
long long shortestDist;
int tcnt = 0;
bool isYes[100010];
map<pair<int, int>, int> dual;
int dfs(int idx){
    vis[idx] = true;
    if(dp[idx])return dp[idx];
    int ret = ++tcnt;
    depth[idx] = tcnt;
    dp[idx] = tcnt;
    for(int i = 0;i<fw[idx].size();i++){
        int e = fw[idx][i];
        if(dist2s[u[e]] + dist2t[v[e]] + l[e] == shortestDist || dist2s[v[e]] + dist2t[u[e]] + l[e] == shortestDist){
            if(vis[v[e]] == 0){
                par[v[e]] = idx;
                int r = dfs(v[e]);
                if(r > depth[idx])
                    isYes[e] = true;
                ret = min(ret, r);
            }else if(v[e] != par[idx])
                ret = min(ret, depth[v[e]]);
        }
    }
    for(int i = 0;i<bw[idx].size();i++){
        int e = bw[idx][i];
        if(dist2s[u[e]] + dist2t[v[e]] + l[e] == shortestDist || dist2s[v[e]] + dist2t[u[e]] + l[e] == shortestDist){
            if(vis[u[e]] == 0){
                // cout<<idx<<" "<<u[e]<<endl;
                par[u[e]] = idx;
                int r = dfs(u[e]);
                if(r > depth[idx])
                    isYes[e] = true;
                ret = min(ret, r);
            }else if(u[e] != par[idx])
                ret = min(ret, depth[u[e]]);
        }
    }
    return (dp[idx] = ret);
}
int main()
{
    in_I(n);in_I(m);in_I(s);in_I(t);
    int x, y, z;
    for(int i = 0;i<m;i++){
        in_I(x);in_I(y);in_I(z);
        fw[x].push_back(i);
        bw[y].push_back(i);
        u[i] = x, v[i] = y;
        l[i] = z;
    }
    for(int i = 1;i<=n;i++)
        dist2s[i] = dist2t[i] = 1e18;
    priority_queue<pair<long long, int> > dij;

    // compute dist from src
    dist2s[s] = 0;
    dij.push(make_pair(0, s));
    while(!dij.empty()){
        pair<long long, int> x = dij.top();
        dij.pop();
        long long cost = x.first;
        int node = x.second;
        for(int i = 0;i<fw[node].size();i++){
            int nxt = fw[node][i];
            if(cost + l[nxt] < dist2s[v[nxt]]){
                dist2s[v[nxt]] = cost + l[nxt];
                dij.push(make_pair(cost + l[nxt], v[nxt]));
            }
        }
    }

    // compute dist from dest
    dist2t[t] = 0;
    dij.push(make_pair(0, t));
    while(!dij.empty()){
        pair<long long, int> x = dij.top();
        dij.pop();
        long long cost = x.first;
        int node = x.second;
        for(int i = 0;i<bw[node].size();i++){
            int nxt = bw[node][i];
            if(cost + l[nxt] < dist2t[u[nxt]]){
                dist2t[u[nxt]] = cost + l[nxt];
                dij.push(make_pair(cost + l[nxt], u[nxt]));
            }
        }
    }

    shortestDist = dist2t[s];
    dfs(s);
    for(int i = 0;i<m;i++){
        if(isYes[i]){
            printf("YES\n");
        }else{
            long long dist = dist2s[u[i]] + l[i] + dist2t[v[i]];
            long long delta = dist - shortestDist + 1;
            cout<<dist<<" "<<shortestDist<<endl;
            if(dist == shortestDist){
                if(l[i] > 1)
                    printf("CAN 1\n");
                else
                    printf("NO\n");
            }else
            if(delta <= l[i]-1)
                printf("CAN %lld\n", delta);
            else
                printf("NO\n");
        }
    }
}
