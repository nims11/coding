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
vector<int> neigh[5001];
int N, M, K;
int cycleId[5001];
bool cycleBool[5001];
int dpInfo[5001][31];
int dpCycleInfo[5001][31];
int visited[5001];

long long getans(int idx, int par=-1, int normal=false){
    long long ret = 0;
    visited[idx] = 1;
    if(!normal && cycleBool[cycleId[idx]]){
        bool state = false;
        for(int i = 0;i<neigh[idx].size();i++){
            int v = neigh[idx][i];

            if(v == par)continue;
            
            if(!visited[v]){
                if(cycleId[idx] != cycleId[v]){
                    ret = ADD(ret, getans(v));
                    int dpInfoNew[K+1];
                    for(int j = 0;j<=K;j++)
                        dpInfoNew[j] = 0;
                    for(int j = 0;j<K;j++){
                        for(int k = 1;k<=K;k++){
                            if(j+k <= K){
                                dpInfoNew[j+k] = ADD(dpInfoNew[j+k], MUL(dpInfo[idx][k],dpInfo[v][j]));
                            }
                        }
                    }
                    for(int j = 1;j<=K;j++)
                        dpInfo[idx][j] = dpInfoNew[j];
                }else{

                }
            }
        }
    }else{
        dpInfo[idx][0] = 1;
        dpInfo[idx][1] = 1;
        for(int i = 0;i<neigh[idx].size();i++){
            int v = neigh[idx][i];
            if(v == par)continue;
            if(!visited[v]){
                ret = ADD(ret, getans(v));
                int dpInfoNew[K+1];
                for(int j = 0;j<=K;j++)
                    dpInfoNew[j] = 0;
                for(int j = 0;j<K;j++){
                    for(int k = 1;k<=K;k++){
                        if(j+k <= K){
                            dpInfoNew[j+k] = ADD(dpInfoNew[j+k], MUL(dpInfo[idx][k],dpInfo[v][j]));
                        }
                    }
                }
                for(int j = 1;j<=K;j++)
                    dpInfo[idx][j] = dpInfoNew[j];
            }
        }
        for(int i = 1;i<=K;i++){
            ret = ADD(ret, dpInfo[idx][i]);
        }
        return ret;
    }
}
int buildCycle(int idx, int par){
    cycleId[idx] = idx;
    int isCycle = -1;
    for(int i = 0;i<neigh[idx].size();i++){
        int v = neigh[idx][i];
        if(v != par){
            if(cycleId[v]){
                isCycle = cycleId[v];
            }
            int ret = buildCycle(v, idx);
            if(ret != -1)
                isCycle = ret;
        }
    }
    cycleId[idx] = isCycle;
    if(isCycle == idx){
        cycleBool[idx] = true;
        return -1;
    }
    return isCycle;
}
int main(){
    in_T{
        in_I(N);
        in_I(M);
        in_I(K);
        int u, v;
        for(int i = 1;i<=N;i++)
            neigh[i].clear(), cycleId[i] = 0, cycleBool[i] = false;
        for(int i = 0;i<M;i++){
            in_I(u);in_I(v);
            neigh[u].push_back(v);
            neigh[v].push_back(u);
        }
        buildCycle(1, -1);
        printf("%lld\n", getans(1));
    }
}
