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
#define newline fprintf(fout, "\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) fprintf(fout, "%d",a)

using namespace std;
FILE *fin = fopen("defence.in", "r");
FILE *fout = fopen("defence.out", "w");
vector<int> neigh[500];
vector<int> neighID[500];
int viss[500];
int main()
{
    int N, M, S, T;
    fscanf(fin, "%d%d%d%d", &N, &M, &S, &T);
    int u, v;
    int visited[M+1];
    for(int i = 0;i<=M;i++)
        visited[i] = 0;
    int levels[M+1];
    for(int i = 0;i<=M;i++)
        levels[i] = 0;
    for(int i = 0;i<M;i++){
        fscanf(fin, "%d%d", &u, &v);
        neigh[u].push_back(v);
        neigh[v].push_back(u);
        neighID[u].push_back(i+1);
        neighID[v].push_back(i+1);
    }
    queue<int> BFS;
    queue<int> level;
    BFS.push(S);
    level.push(1);
    int minLevel = 1e9;
    while(!BFS.empty()){
        int x = BFS.front();
        BFS.pop();
        int l = level.front();
        level.pop();
        if(x == T){
            minLevel = min(minLevel, l);
            continue;
        }
        for(int i = 0;i<neigh[x].size();i++){
            if(!visited[neighID[x][i]]){
                viss[neigh[x][i]] = 1;
                level.push(l+1);
                visited[neighID[x][i]] = l+1;
                BFS.push(neigh[x][i]);
                if(levels[neighID[x][i]] == 0)
                    levels[neighID[x][i]] = l;
                else
                    levels[neighID[x][i]] = min(l, levels[neighID[x][i]]);
            }
        }
    }
    map<int, vector<int> > res;
    for(int i = 1;i<=M;i++)
        if(levels[i] != 0 && levels[i] < minLevel)
            res[levels[i]].push_back(i);
    int sz = res.size();
    fprintf(fout, "%d\n", sz);
    for(map<int, vector<int> >::iterator it = res.begin();it!= res.end();it++){
        fprintf(fout, "%d ", it->second.size());
        for(int j = 0;j<it->second.size();j++)
            fprintf(fout, "%d ", it->second[j]);
        fprintf(fout, "\n");
    }

/*    int sz = result.size();
    for(int i = 0;i<result.size();i++)
        sz -= (result[i].size() == 0);
    fprintf(fout, "%d\n", sz);
    for(int i = 0;i<result.size();i++){
        if(result[i].size() == 0)continue;
        fprintf(fout, "%d ", result[i].size());
        for(int j = 0;j<result[i].size();j++)
            fprintf(fout, "%d ", result[i][j]);
        fprintf(fout, "\n");
    }
    */
}
