/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<stack>
#include<set>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int N, M, K;
vector<pair<int, int> > neigh[200010];
int u, v, y;
int visited[200010];
int curRun = 1;
void dfs(int idx){
    visited[idx] = curRun;
    for(int i = 0;i<neigh[idx].size();i++){
        int v = neigh[idx][i].first;
        if(visited[v] != curRun)
            dfs(v);
    }
}
vector<int> starts;
int res[200010];
bool dfsXor(int idx){
    visited[idx] = curRun;
    for(int i = 0;i<neigh[idx].size();i++){
        pair<int, int> xx = neigh[idx][i];
        int v = xx.first, c = xx.second;
        if(res[v] == -1){
            res[v] = res[idx]^c;
            if(!dfsXor(v))
                return false;
        }else{
            if(res[v] != (res[idx]^c)){
                return false;
            }

        }
    }
    return true;
}
int main()
{
    in_I(N);
    in_I(M);
    in_I(K);
    for(int i = 1;i<=N;i++)
        res[i] = -1;
    for(int i = 0;i<M;i++){
        in_I(u);in_I(v);in_I(y);
        neigh[u].push_back(make_pair(v, y));
        neigh[v].push_back(make_pair(u, y));
    }
    for(int i = 1;i<=N;i++){
        if(!visited[i]){
            dfs(i);
            starts.push_back(i);
        }
    }
    for(int i = 0;i<starts.size();i++){
        curRun++;
        if(i == starts.size()-1){
            res[starts[i]] = K-1;
        }else{
            res[starts[i]] = 0;
        }
        if(!dfsXor(starts[i])){
            printf("-1\n");
            return 0;
        }
    }
    for(int i = 1;i<=N;i++)
        printf("%d ", res[i]);
    newline;
}
