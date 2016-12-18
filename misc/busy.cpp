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
int dist[100][100];
char grid[100][100];
const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int res = INF;
void getans(vector<int> &sums, int idx=0, int s1=0, int s2=0){
    if(idx == sums.size()){
        res = min(res, max(s1, s2));
    }else{
        getans(sums, idx+1, s1+sums[idx], s2);
        getans(sums, idx+1, s1, s2+sums[idx]);
    }
}
int main()
{
    in_T{
        int m,n;
        in_I(m);in_I(n);
        int bulds = 0;
        pair<int, int> s;
        for(int i = 0;i<m;i++){
            in_S(grid[i]);
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j] == 'X')
                    s = make_pair(i, j);
                dist[i][j] = INF;
                bulds += (grid[i][j] == '$');
            }
        }
        queue<pair<int, int> > BFS;
        BFS.push(s);
        dist[s.first][s.second] = 0;
        while(!BFS.empty()){
            pair<int, int> s = BFS.front();
            BFS.pop();
            int i = s.first, j = s.second;
            for(int z = 0;z<4;z++){
                int x = i+dx[z], y = j+dy[z];
                if(x>=0 && x<m && y>=0 && y<n){
                    int cost = INF;
                    if(grid[i][j] == 'X' || grid[i][j] == '$' || grid[x][y] == 'X' || grid[x][y] == '$'){
                        cost = 2;
                    }else if(grid[i][j] == grid[x][y])
                        cost = 1;
                    else if(abs(grid[i][j] - grid[x][y]) == 1)
                        cost = 3;
                    if(cost < 4){
                        if(dist[i][j]+cost < dist[x][y]){
                            dist[x][y] = dist[i][j]+cost;
                            BFS.push(make_pair(x, y));
                        }
                    }
                }
            }
        }
        int tot = 0;
        vector<int> sums;
        for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
//            cout<<dist[i][j]<<" ";
            if(grid[i][j] == '$' && dist[i][j]<INF){
                tot += 2*dist[i][j];
                sums.push_back(2*dist[i][j]);
            }
        }
//        cout<<endl;
        }
        if(sums.size() != bulds){
            printf("-1\n");
            continue;
        }
        res = INF;
        getans(sums);
        printf("%d\n", res);
    }
}
