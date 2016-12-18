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

pair<int, int> row[301][301];
char grid[301][301];
vector<vector<int> > neigh;
int bw[100000]; // all -1s
int vis[100000];
int find_path(int n){
    if(vis[n])
        return 0;
    vis[n] = 1;
    for(int i = 0;i<neigh[n].size();i++)
        if(bw[neigh[n][i]] == -1 || find_path(bw[neigh[n][i]])){
            bw[neigh[n][i]] = n;
            return 1;
        }
    return 0;
}
int max_flow(){
    int res = 0;
    for(int i = 0;i<neigh.size();i++){
        if(neigh[i].size() == 0)
            continue;
        memset(vis, 0, sizeof(int)*neigh.size());
        res += find_path(i);
    }
    return res;
}
int main(){
    in_T{
        neigh.clear();
        int X, Y;
        in_I(X);
        in_I(Y);
        int cnt = 0;
        for(int i = 0;i<X;i++)
            for(int j = 0;j<Y;j++)
                while ((grid[i][j] = getchar()) < 'A');

        for(int i = 0;i<X;i++)
            for(int j = 0;j<Y;j++){
                if(i == 0 || grid[i-1][j] == 'A')
                    row[i][j].first = cnt++;
                else
                    row[i][j].first = row[i-1][j].first;
                if(j == 0 || grid[i][j-1] == 'A')
                    row[i][j].second = cnt++;
                else
                    row[i][j].second = row[i][j-1].second;
            }

        for(int i = 0;i<cnt;i++)
            neigh.push_back(vector<int> ());

        for(int i = 0;i<X;i++)
            for(int j = 0;j<Y;j++){
                if(grid[i][j] != 'H')
                    continue;
                neigh[row[i][j].first].push_back(row[i][j].second);
            }
        for(int i = 0;i<cnt;i++)
            bw[i] = -1;
        printf("%d\n", max_flow());
    }
}
