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
char grid[52][52];
pair<int, int> node[52][52];
int main()
{
    in_T{
        int r, c;
        in_I(r); in_I(c);
        neigh.clear();
        for(int i = 0;i<r;i++)in_S(grid[i]);
        for(int i = 0;i<r;i++)for(int j = 0;j<c;j++){
            if(grid[i][j] != '*')continue;
            if(i == 0 || grid[i-1][j] == '.'){
                neigh.push_back(vector<int>());
                node[i][j].first = neigh.size()-1;
            }else
                node[i][j].first = node[i-1][j].first;

            if(j == 0 || grid[i][j-1] == '.'){
                neigh.push_back(vector<int>());
                node[i][j].second = neigh.size()-1;
            }else
                node[i][j].second = node[i][j-1].second;
            neigh[node[i][j].first].push_back(node[i][j].second);
        }
        for(int i = 0;i<neigh.size();i++)
            bw[i] = -1;
        printf("%d\n", max_flow());
    }
}
