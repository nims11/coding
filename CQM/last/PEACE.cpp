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
int N, M, X, Y;
int visited[100001];
vector<pair<int, int> > neigh[100001];
int isCycle[100001];
int dfs(int u, int par = -1){
    visited[u] = 1;
    int ret = -1;
    for(int i = 0;i<neigh[u].size();i++){
        if(neigh[u][i].first == par)continue;
        if(visited[neigh[u][i].first] == 1){
            isCycle[neigh[u][i].second] = 1;
            ret = neigh[u][i].first;
        }else{
            int t = dfs(neigh[u][i].first, u);
//            cout<<u<<" "<<neigh[u][i].first<<" "<<t<<endl;
            if(t != -1 && t != u)
            {
                ret = t;
                isCycle[neigh[u][i].second] = 1;
            }
            if(t == u){
                isCycle[neigh[u][i].second] = 1;
            }
        }
    }
    visited[u] = 2;
    return ret;
}
int main()
{
    while(scanf("%d %d", &N, &M) != EOF){
//        cout<<endl<<endl;
        for(int i = 0;i<N;i++)
            neigh[i].clear(), visited[i] = 0;
        for(int i = 0;i<M;i++){
            isCycle[i] = 0;
            in_I(X);in_I(Y);
            neigh[X].push_back(make_pair(Y, i));
            neigh[Y].push_back(make_pair(X, i));
        }
        dfs(0);
        int res = 0;
        for(int i = 0;i<M;i++)
            res += (isCycle[i] == 0);
        printf("%d\n", res);
    }
}
