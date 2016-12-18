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
char grid[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
pair<int, int> vis[100][100];
int COST[256];
const int inf = 1e9;
int main(){
    for(int i = 0;i<100;i++)
        for(int j = 0;j<100;j++)
            vis[i][j] = {inf, inf};
    COST['.']= 1;
    COST['F'] = 2;
    COST['M'] = 3;
    COST['#'] = -1;
    COST['G'] = 1;
    COST['S'] = 1;
    int N, M, K;
    in_I(N);
    in_I(M);
    in_I(K);
    for(int i = 0;i<N;i++)
        in_S(grid[i]);
    pair<int, int> st;
    pair<int, int> goal;
    for(int i = 0;i<N;i++)
        for(int j = 0;j<M;j++){
            if(grid[i][j] == 'S')
                st = {i,j};
            if(grid[i][j] == 'G')
                goal = {i,j};
        }

    priority_queue<pair<pair<int, int>, pair<int, int> > > dij;
    dij.push({{-1, K}, st});
    vis[st.first][st.second] = {1, K};
    while(!dij.empty()){
        pair<pair<int, int>, pair<int, int> > cur = dij.top();
        dij.pop();
        pair<int, int> pos = cur.second;
        pair<int, int> cost = cur.first;
        if(pos == goal){
            cout<<(-cost.first)<<endl;
            return 0;
        }
        for(int i = 0;i<4;i++){
            pair<int, int> newpos = {dx[i]+pos.first, dy[i]+pos.second};
            int stepcost = COST[grid[newpos.first][newpos.second]];
            if(stepcost == -1)
                continue;
            if(newpos.first >= 0 && newpos.first < N && newpos.second >= 0 && newpos.second < M){
                pair<int, int> newcost = {-cost.first, cost.second-stepcost};
                if(newcost.second < 0){
                    newcost.first++;
                    newcost.second = K - stepcost;
                    if(newcost.second < 0)continue;
                }
                
                if(vis[newpos.first][newpos.second] > newcost){
                    vis[newpos.first][newpos.second] = newcost;
                    newcost.first = -newcost.first;
                    dij.push({newcost, newpos});
                }
            }
        }
    }
    cout<<-1<<endl;
}
