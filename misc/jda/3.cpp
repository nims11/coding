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
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int main()
{
    int N;
    in_I(N);
    int grid[N][N];
    pair<int, int> start;
    pair<int, int> end;
    int visited[N][N];
    for(int i = 0;i<N;i++)for(int j = 0;j<N;j++){
        char ch;
        cin>>ch;
        if(ch == 'S') grid[i][j] = 0, start = make_pair(i, j);
        else if(ch == 'E') grid[i][j] = 1, end = make_pair(i, j);
        else if(ch == 'P') grid[i][j] = 1;
        else grid[i][j] = -1;
        visited[i][j] = 1000000;
    }
    visited[start.first][start.second] = 0;
    queue<pair<int, int> > BFS;
    BFS.push(start);
    while(!BFS.empty()){
        pair<int, int> cur = BFS.front();
        BFS.pop();
        for(int i = 0;i<4;i++){
            pair<int, int> nxt = make_pair(dx[i]+cur.first, dy[i]+cur.second);
            if(nxt.first >= 0 && 
                    nxt.first <N && 
                    nxt.second >=0 && 
                    nxt.second <N && 
                    grid[nxt.first][nxt.second] != -1 &&
                    visited[nxt.first][nxt.second] > visited[cur.first][cur.second] + 1
                    ){
                visited[nxt.first][nxt.second] = visited[cur.first][cur.second] + 1;
                BFS.push(nxt);
            }
        }
    }
    printf("%d\n", visited[end.first][end.second]);
}
