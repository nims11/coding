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
    map<node*, int> edges;
}nodes[1000000];
int cnt = 0;
node* nxtNode(){
    nodes[cnt].edges.clear();
    return &nodes[cnt++];
}
const int INF = 150;
int find_path(node *src, node *dest)
{
    int ret = -1;
    map<node*, node*> backlink;
    queue<node*> BFS;
    BFS.push(src);
    backlink[src] = 0;
    while(!BFS.empty()){
        node *x = BFS.front();
        BFS.pop();
        if(x == dest){
            ret = 1000;
            while(backlink[x] != 0){
                node *pre = backlink[x];
                ret = min(ret, pre->edges[x]);
                x = pre;
            }
            x = dest;
            while(backlink[x] != 0){
                node *pre = backlink[x];
                pre->edges[x] -= ret;
                x->edges[pre] += ret;
                x = pre;
            }
            return ret;
        }
        for(map<node*, int>::iterator it = x->edges.begin(); it != x->edges.end(); it++)
            if(backlink.find(it->first) == backlink.end() && it->second)
                backlink[it->first] = x, BFS.push(it->first);
    }
    return ret;
}
int max_flow(node *src, node *sink)
{
    int ret = 0, path_capacity;
    while((path_capacity = find_path(src, sink)) != -1)
        ret += path_capacity;
    return ret;
}
int main()
{
    in_T
    {
        int n, x, y;
        in_I(n);
        cnt = 0;
        node *source = nxtNode(), *sink = nxtNode();
        node *row[120], *col[120];
        for(int i = 0;i<120;i++){
            row[i] = nxtNode(), col[i] = nxtNode();
            source->edges[row[i]] = 1;
            row[i]->edges[source] = 0;

            sink->edges[col[i]] = 0;
            col[i]->edges[sink] = 1;
        }
        for(int i = 0;i<n;i++){
            in_I(x);in_I(y);
            row[x]->edges[col[y]] = 1;
            col[y]->edges[row[x]] = 0;
        }
        printf("%d\n", max_flow(source, sink));
    }
}
