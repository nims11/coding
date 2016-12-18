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
int par[100010][20];
vector<int> neigh[100010];
int depth[100010], sz[100010];
int lg2[100010];
int dep(int idx){
    sz[idx] = 1;
    for(int i = 0;i<neigh[idx].size();i++){
        int v = neigh[idx][i];
        if(!depth[v]){
            par[v][0] = idx;
            int curV = idx;
            int curIdx = 1;
            while(par[curV][curIdx-1]){
                par[v][curIdx] = par[curV][curIdx-1];
                curV = par[v][curIdx];
                curIdx++;
            }
            depth[v] = depth[idx]+1;
            sz[idx] += dep(v);
        }
    }
    return sz[idx];
}
int lca(int u, int v){
    while(depth[u] != depth[v]){
        if(depth[u] > depth[v]){
            int idx = 0;
            int curV = par[u][idx];
            while(curV && depth[curV] >= depth[v])
                curV = par[u][++idx];
            --idx;
            u = par[u][idx];
        }else
            swap(u, v);
    }
    while(u != v){
        int idx = -1;
        int u1 = u, v1 = v;
        while(u1 && v1 && u1 != v1){
            idx++;
            u1 = par[u][idx];
            v1 = par[v][idx];
        }
        idx--;
        // cout<<u<<" "<<v<<endl;
        if(idx == -1){
            v = u = par[u][0];
            // cout<<u<<endl;
            break;
        }
        u = par[u][idx], v = par[v][idx];
    }
    return u;
}
int getPar(int u, int n){
    int ret = u;
    while(n){
        int idx = lg2[n];
        n -= (1<<idx);
        ret = par[ret][idx];
    }
    return ret;
}
int main()
{
    lg2[1] = 0;
    int curVal = 1;
    for(int i = 2;i<100010;i++){
        if(curVal*2 <= i)
            lg2[i] = lg2[i-1]+1, curVal *= 2;
        else
            lg2[i] = lg2[i-1];
    }
    int n;
    in_I(n);
    int u, v;
    for(int i = 0;i<n-1;i++){
        in_I(u);in_I(v);
        neigh[u].push_back(v);
        neigh[v].push_back(u);
    }
    int m;
    depth[1] = 1;
    dep(1);
    in_I(m);
    while(m--){
        int a, b;
        in_I(a);in_I(b);
        if(a == b){
            printf("%d\n", n);
            continue;
        }
        int v = lca(a, b);
        // cout<<v<<endl;
        if(depth[b] == depth[a]){
            int dist = depth[a] - depth[v] + depth[b] - depth[v];
            printf("%d\n", n - sz[getPar(a, dist/2-1)]
                    - sz[getPar(b, dist/2-1)]);
        }else{
            int dist = depth[a] - depth[v] + depth[b] - depth[v];
            if(dist%2 == 1)
                printf("0\n");
            else
                printf("%d\n", sz[getPar(depth[a]>depth[b]?a:b, dist/2)]
                        - sz[getPar(depth[a]>depth[b]?a:b, dist/2-1)]);
        }
    }
}
