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
int n;
int nxt[100010];
long long r[100010];
long long vis[100010], res[100010];
vector<int> neigh[100010];
int comp[100010];
int cnt;
int dfs(int idx){
    vis[idx] = -1;
    comp[idx] = idx;
    int ret;
    int v = nxt[idx];
    if(vis[v] == -1){
        vis[idx] = v;
        nxt[idx] = idx;
        return v;
    }
    if(vis[v] == 0)
        ret = dfs(v);
    else ret = -1;
    comp[idx] = comp[v];
    if(ret != -1)
        vis[idx] = ret, nxt[idx] = idx;
    else
        vis[idx] = idx;
    if(ret == idx)
        ret = -1;
    return ret;
}
long long dfs2(int idx, int par){
    if(vis[idx] == idx && nxt[idx] == idx){
        if(par == -1){
            long long ret = r[idx];
            for(int i = 0;i<neigh[idx].size();i++)
                ret += dfs2(neigh[idx][i], idx);
            return max(0LL, ret);
        }else
            return 0;
    }else{
        long long ret = (nxt[idx] == idx?0:r[idx]);
        for(int i = 0;i<neigh[idx].size();i++)
            ret += dfs2(neigh[idx][i], idx);
        return max(0LL, ret);
    }
}
int main()
{
    in_T{
        in_I(n);
        for(int i = 0;i<=n;i++)
            neigh[i].clear();
        for(int i = 0;i<n;i++){
            in_I(nxt[i+1]);
            neigh[nxt[i+1]].push_back(i+1);
        }
        for(int i = 0;i<n;i++)
            in_L(r[i+1]);
        for(int i = 0;i<=n;i++)
            res[i] = vis[i] = 0;
        for(int i = 1;i<=n;i++){
            if(vis[i] == 0)
                dfs(i);
        }
        long long ans = 0;
        for(int i = 1;i<=n;i++)
            res[vis[i]] += r[i];
        for(int i = 1;i<=n;i++)
            r[i] = res[vis[i]];

        for(int i = 1;i<=n;i++){
            if(nxt[i] == i && vis[i] == i)
                ans += dfs2(i, -1);
        }
        printf("%lld\n", ans);
    }
}
