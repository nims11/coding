#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

const int INF = INT_MAX;
using namespace std;
char grid[100][100];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int main(){
    int n, m;
    in_I(n);
    in_I(m);
    pair<int, int> S, E;
    for(int i = 0; i < n; i++){
        in_S(grid[i]);
        for(int j = 0; j < m;j++){
            if(grid[i][j] == 'S'){
                S = {i, j};
            }
            if(grid[i][j] == 'E')
                E = {i, j};
        }
    }
    char cmd[200];
    in_S(cmd);
    int cmdlen = strlen(cmd);
    vector<int> ass = {0, 1, 2, 3};
    int valid = 0;
    do{
        auto cur = S;
        bool _valid = true;
        for(int i = 0; i < cmdlen; i++){
            int dir = cmd[i] - '0';
            dir = ass[dir];
            cur.first += dy[dir];
            cur.second += dx[dir];
            if(cur.first < 0 || cur.first >= n || cur.second < 0 || cur.second >= m || grid[cur.first][cur.second] == '#'){
                _valid = false;
                break;
            }
            if(cur == E)
                break;
        }
        if(_valid && cur != E)
            _valid = false;
        valid += _valid;
    } while(next_permutation(ass.begin(), ass.end()));
    cout<<valid<<endl;
}
