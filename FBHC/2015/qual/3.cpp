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
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)
#define BE(a) a.begin(), a.end()

using namespace std;
int M, N;
string grid[200];
map<char, char> mapp;
bool allowed[200][200][4];
set<char> defaultBlocked = {'0', '1', '2', '3', '#'};
void processTurretTargets(int i, int j, bool* allowStates, int targetStates){
    if(defaultBlocked.count(grid[i][j])){
        for(int k = 0;k<4;k++)
            allowed[i][j][k] = false, allowStates[k] = true;
        if(grid[i][j] >='0' && grid[i][j] <= '3'){
            int curTurret = grid[i][j] - '0';
            int activeOn = (targetStates-curTurret+4)%4;
            allowStates[activeOn] = false;
        }
    }else{
        for(int k = 0;k<4;k++)
            allowed[i][j][k] &= allowStates[k];
    }
}
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main()
{
    mapp['^'] = '0';
    mapp['>'] = '1';
    mapp['v'] = '2';
    mapp['<'] = '3';
    pair<int, int> S, G;
    int z = 0;
    in_T{
        z++;
        cout<<"Case #"<<z<<": ";
        cin>>M>>N;
        for(int i = 0;i<M;i++){
            cin>>grid[i];
            for(int j = 0;j<N;j++){
                for(int k = 0;k<4;k++)
                    allowed[i][j][k] = 1;
                if(mapp.find(grid[i][j]) != mapp.end())
                    grid[i][j] = mapp[grid[i][j]];
                else if(grid[i][j] == 'S')
                    S = {i, j};
                else if(grid[i][j] == 'G')
                    G = {i, j};
            }
        }
        for(int i = 0;i<M;i++){
            bool allowStates[4];
            for(int j = 0;j<4;j++)
                allowStates[j] = true;
            for(int j = 0;j<N;j++){
                processTurretTargets(i, j, allowStates, 1);
            }
            for(int j = 0;j<4;j++)
                allowStates[j] = true;
            for(int j = N-1;j>=0;j--){
                processTurretTargets(i, j,allowStates, 3);
            }
        }

        for(int i = 0;i<N;i++){
            bool allowStates[4];
            for(int j = 0;j<4;j++)
                allowStates[j] = true;
            for(int j = 0;j<M;j++){
                processTurretTargets(j, i,allowStates, 2);
            }
            for(int j = 0;j<4;j++)
                allowStates[j] = true;
            for(int j = M-1;j>=0;j--){
                processTurretTargets(j, i, allowStates, 0);
            }
        }
//#define allowedDebug
#ifdef allowedDebug
        for(int i = 0;i<M;i++){
            for(int j = 0;j<N;j++){
                for(int k = 0;k<4;k++)
                    cout<<allowed[i][j][k]<<",";
                cout<<" ";
            }
            cout<<endl;
        }
#endif

        queue<pair<pair<int, int>, int> > BFS;
        map<pair<pair<int, int>, int>, int> visited;
        for(int i = 0;i<M;i++)
            for(int j = 0;j<N;j++)
                for(int k = 0;k<4;k++)
                    visited[{{i, j}, k}] = 1000000000;
        visited[{S, 0}] = 0;
        BFS.push({S, 0});
        while(!BFS.empty()){
            pair<pair<int, int>, int>x = BFS.front();
            BFS.pop();
            int nextState = (x.second+1)%4;
            pair<int, int> pos = x.first;
            for(int i = 0;i<4;i++){
                int nI = pos.first+dx[i];
                int nJ = pos.second+dy[i];
                if(nI < M && nI >= 0 && nJ < N && nJ >= 0 && allowed[nI][nJ][nextState]){
                    if(visited[{{nI, nJ}, nextState}] > visited[x]+1){
                        visited[{{nI, nJ}, nextState}] = visited[x]+1;
                        BFS.push({{nI, nJ}, nextState});
                    }
                }
            }
        }
        int res = 1000000000;
        for(int i = 0;i<4;i++)
            res = min(res, visited[{G, i}]);
        if(res == 1000000000)
            cout<<"impossible"<<endl;
        else
            cout<<res<<endl;
    }
}
