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
    int x;
    nodes[cnt].edges.clear();
    return &nodes[cnt++];
}
int find_path(node *src, node *dest){
    int ret = -1;
    map<node*, node*> backlink;
    queue<node*> BFS;BFS.push(src);
    backlink[src] = 0;
    while(!BFS.empty()){
        node *x = BFS.front();BFS.pop();
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
bool max_flow(node *src, node *sink){
    int ret = 0, path_capacity;
    while((path_capacity = find_path(src, sink)) != -1)
    {
        ret += path_capacity;
        if(ret >= 2)
            return true;
    }
    return false;
}
int n, m;
int x, y;
map<int, node*> node_map;
int main()
{
    in_T{
        in_I(n);in_I(m);
        if(cnt == 1000000)
            cnt = 0;
        node_map.clear();
        for(int i = 0;i<n;i++)
            nodes[i].edges.clear();
        while(m--){
            scanf("%d%d", &x, &y);
            if(node_map.find(x) == node_map.end()) node_map[x] = nxtNode();
            if(node_map.find(y) == node_map.end()) node_map[y] = nxtNode();
            node_map[x]->edges[node_map[y]] = 1;
            node_map[y]->edges[node_map[x]] = 1;
        }
        node *src = nxtNode();
        src->edges[node_map[1]] = 1;
        src->edges[node_map[3]] = 1;
        node_map[1]->edges[src] = 0;
        node_map[3]->edges[src] = 0;
        if(max_flow(src, node_map[2]))
            printf("YES\n");
        else
            printf("NO\n");
    }
}
