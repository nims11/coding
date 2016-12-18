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
struct node{
    int parent;
    vector<int> children;
    node(){
        parent =  0;
    }
};
vector<int> neigh[10001];
vector<int> depth[10001];
int N, maxDepth;
void dfs(int idx, int parent, node nodes[], int cnt=1){
    depth[cnt].push_back(idx);
    maxDepth = max(maxDepth, cnt);
    nodes[idx].parent = parent;
    for(int i = 0;i<neigh[idx].size();i++){
        if(parent != neigh[idx][i])
            dfs(neigh[idx][i], idx, nodes, cnt+1), nodes[idx].children.push_back(neigh[idx][i]);
    }
}
int main()
{
    in_T{
        in_I(N);
        int n = N;
        maxDepth = 0;
        node nodes[N+1];
        for(int i = 1;i<=n;i++)
            neigh[i].clear(), depth[i].clear();
        for(int i = 1;i<n;i++){
            int x, y;
            in_I(x);in_I(y);
            neigh[x].push_back(y);
            neigh[y].push_back(x);
        }
        dfs(1, 0, nodes);
        int res = 0;
        int rootDepth = 1, leafDepth = maxDepth;
        int turn = 0;
        int curLeafSize = depth[leafDepth].size();
        while(rootDepth<=leafDepth){
            if(turn&1){
                curLeafSize--;
                if(curLeafSize == 0)
                    curLeafSize = depth[--leafDepth].size();
            }else{
                rootDepth++;
            }
            turn++;
            
        }
        cout<<turn<<endl;
/*        while(trees.size() > 0){
            if(turn&1){
                
            }else { // remove root
                set<int> tmp;
                for(set<int>::iterator it = trees.begin(); it != trees.end(); it++){
                    for(int i = 0;i<nodes[*it].children.size(); i++){
                        for(int j = 0;j<nodes)
                    }
                }
            }
        }*/
    }
}
