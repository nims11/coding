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

const int MAXN = 100010;
vector<int> neigh[MAXN];
struct LogCache {
    int LOG2[MAXN];
    LogCache();
};
LogCache::LogCache(){
    int curr = 2;
    LOG2[1] = 0;
    for(int i = 2; i<=100001;i++){
        if(i == curr){
            curr <<= 1;
            LOG2[i] = LOG2[i-1] + 1;
        }else
            LOG2[i] = LOG2[i-1];
    }
}

struct LCA {
    static LogCache logCache;
    int par[MAXN][20], depth[MAXN], sz[MAXN];
    int dfs(int idx);
    void build(int root){depth[root] = 1; dfs(root);}

    // Get nth parent
    int getPar(int u, int n);
    int lca(int u, int v);
}lca;
LogCache LCA::logCache;
int LCA::dfs(int idx){
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
            sz[idx] += dfs(v);
        }
    }
    return sz[idx];
}
int LCA::getPar(int u, int n){
    int ret = u;
    while(n){
        int idx = logCache.LOG2[n];
        n -= (1<<idx);
        ret = par[ret][idx];
    }
    return ret;
}
int LCA::lca(int u, int v){
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
        if(idx == -1){
            v = u = par[u][0];
            break;
        }
        u = par[u][idx], v = par[v][idx];
    }
    return u;
}
int N;
int A[100010];
int p1[100010];
int p2[100010];
int tmp[100010];
void findPath(int u, int v, int *p){
    int par = lca.lca(u, v);
    int ptrL = 0, ptrR;
    while(u != par){
        p[ptrL++] = A[u];
        u = lca.getPar(u, 1);
    }
    p[ptrL++] = A[u];

    ptrR = 0;
    while(v != par){
        tmp[ptrR++] = A[v];
        v = lca.getPar(v, 1);
    }
    ptrR--;
    while(ptrR>=0){
        p[ptrL++] = tmp[ptrR--];
    }
    p[ptrL] = 0;
}
void putPath(int u, int v, int *p){
    int par = lca.lca(u, v);
    int ptrL = 0, ptrR;
    while(u != par){
        A[u] = p[ptrL++];
        u = lca.getPar(u, 1);
    }
    A[u] = p[ptrL++];

    ptrR = 0;
    while(v != par){
        tmp[ptrR++] = v;
        v = lca.getPar(v, 1);
    }
    ptrR--;
    while(ptrR>=0){
        A[tmp[ptrR--]] = p[ptrL++];
    }
}
int main()
{
    int Q;
    in_I(N);in_I(Q);
    for(int i = 0;i<N;i++){
        in_I(A[i+1]);
    }
    for(int i = 0;i<N-1;i++){
        int u, v;
        in_I(u);
        in_I(v);
        neigh[u].push_back(v);
        neigh[v].push_back(u);
    }
    lca.build(1);
    while(Q--){
        int op, u, v;
        in_I(op);in_I(u);in_I(v);
        findPath(u, v, p1);
        if(op == 1){
            putPath(v, u, p1);
        }else if(op == 2){
            int u1, v1;
            in_I(u1);in_I(v1);
            findPath(u1, v1, p2);
            bool eq = true;
            for(int i = 0;p1[i];i++){
                if(p1[i] != p2[i]){
                    eq = false;
                    break;
                }
            }
            printf(eq?"Yes\n":"No\n");
        }else if(op == 3){
            int u1, v1;
            in_I(u1);in_I(v1);
            putPath(u1, v1, p1);
        }
    }
}
