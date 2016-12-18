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
int n, k;
vector<int> neigh[400];
bool visited[400];
int max2[400][2];
int maxn=0;
int DFS(int n)
{
    visited[n]=true;
    for(int i=0;i<neigh[n].size();i++)
    {
        if(!visited[neigh[n][i]])
        {
            int x=DFS(neigh[n][i]);
            if(x>max2[n][0]){max2[n][1]=max2[n][0];max2[n][0]=x;}
            else if(max2[n][1]<x)max2[n][1]=x;

        }

    }
    int tmp=max2[n][0]+max2[n][1];
    if(tmp>maxn)
        maxn=tmp;
    return max2[n][0]+1;

}

int dia(int *visi, int root){
    for(int i = 0;i<=n;i++)
    {
     visited[i] = max2[i][0] = max2[i][1] = 0;   
     if(visi[i] == -1)
         visited[i] = -1;
    }
    maxn = 0;
    DFS(root);
    return maxn;
}
int getans(int root){
    int visited[n+1];
    for(int i = 0;i<=n;i++)
        visited[i] = -1;
    queue<int> BFS;
    BFS.push(root);
    visited[root] = 0;
    int K = n-k-1;
    while(K>0){
        int x = BFS.front();
        BFS.pop();
        for(int i = 0;i<neigh[x].size();i++){
            int v = neigh[x][i];
            if(visited[v] == -1){
                visited[v] = visited[x]+1;
                BFS.push(v);
                K--;
            }
        }
    }
    int max1 = root, max2 = root;
    for(int i = 1;i<=n;i++){
        if(visited[max2] < visited[i])
            max2 = i;
        if(visited[max2] > visited[max1])
            swap(max1, max2);
    }
    return dia(visited, root);
}
int main()
{
    in_I(n);
    in_I(k);
    int u, v;
    for(int i = 0;i<n-1;i++){
        in_I(u);in_I(v);
        neigh[u].push_back(v);
        neigh[v].push_back(u);
    }
    int res = 1e9;
    for(int i = 0;i<n;i++){
        res = min(res, getans(i+1));
    }
    cout<<res<<endl;
}
