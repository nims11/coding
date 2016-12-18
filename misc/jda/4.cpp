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
int adj[101][101];
const int INF = 1e9;
int main()
{
    int N, R, C1, C2, P;
    in_I(N); in_I(R);
    for(int i = 0;i<R;i++){
        in_I(C1);in_I(C2);in_I(P);
        adj[C1][C2] = adj[C2][C1] = P;
    }
    int S, D, T;
    in_I(S);
    in_I(D);
    in_I(T);
    queue<pair<int, int> > BFS;
    BFS.push(make_pair(S, INF));
    int vis[101] = {0};
    int bk[101] = {0};
    vis[S] = INF;
    bk[S] = -1;
    while(!BFS.empty()){
        pair<int, int> cur = BFS.front();
        for(int i = 1;i<=N;i++){
            if(max(cur.second, adj[cur.first][i]) > vis[i]){
                vis[i] = max(cur.second, adj[cur.first][i]);
                BFS.push(make_pair(i, vis[i]));
            }
        }
    }
}
