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
#define P_I(a) printf("%d\n",a)
//#define VVVV
using namespace std;
struct vertex;
struct edge;
struct chain;
struct vertex{
    vector<edge*> adj;
    edge* parent_edge;
    int heavy_chain_id;
    int size,depth;
    void init(){
        adj.clear();
        parent_edge = NULL;
        heavy_chain_id = -1;
        size = depth =0;
    }
};
struct edge{
    vertex *u,*v;
    chain* host_chain;
    int weight;
    void init(){
        u = v = NULL;
        host_chain = NULL;
    }

};
struct chain{
    vector<int> weights;
    vertex *head;int size;
    int *TREE;

    // Chain Methods
    void clear(){
        weights.clear();
    }
    void build(){
        size = weights.size();
        TREE = new int[size*4];
        build_segment_tree(1, 0, size-1);
    }
    int query(vertex *u, vertex *v){
        int x,y;
        x = u->depth-head->depth,
        y = v->depth-head->depth-1;
        return query_segment_tree(1, 0, size-1, x, y);
    }

    //Segment Tree Methods
    void build_segment_tree(int NODE,int a,int b){
        if(a==b){
            TREE[NODE] = weights[a];
            return;
        }
        int mid=(a+b)/2;
        int left=2*NODE,right=2*NODE+1;
        build_segment_tree(left,a,mid);
        build_segment_tree(right,mid+1,b);

        TREE[NODE] = TREE[left]+TREE[right];
    }
    int query_segment_tree(int NODE,int a,int b,int x,int y){
        if(x<=a && y>=b)return TREE[NODE];
        int mid=(a+b)/2;
        int left=2*NODE,right=2*NODE+1;
        if(y<=mid)return query_segment_tree(left,a,mid,x,y);
        if(x>mid)return query_segment_tree(right,mid+1,b,x,y);

        int left_query=query_segment_tree(left,a,mid,x,y);
        int right_query=query_segment_tree(right,mid+1,b,x,y);

        return left_query + right_query;
    }
};
vertex *root = NULL;
int chain_cnt = 0;
vertex V[10002];
edge E[10002];
chain heavy_chains[5002];
void build(vertex *V, vertex* par=NULL){
    if(par == NULL){
        root = V;
        V->depth = 0;
    }else
        V->depth = par->depth+1;

    V->size = 1;
    for(int i=0;i<V->adj.size();i++){
        vertex *nxt = (V->adj[i]->u == V)?V->adj[i]->v:V->adj[i]->u;
        if(nxt != par){
            nxt->parent_edge = V->adj[i];
            build(nxt, V);
            V->adj[i]->u = V;
            V->adj[i]->v = nxt;
            V->size += nxt->size;
        }
    }
}
void heavy_light_decomposition(vertex *V, chain *curr_chain = NULL){
    for(int i=0;i<V->adj.size();i++){
        vertex *nxt = V->adj[i]->v;
        if(nxt!=V){
            if(2*nxt->size >= V->size){
                if(curr_chain == NULL){
                    curr_chain = &heavy_chains[chain_cnt++];
                    curr_chain->head = V;
                }
                V->adj[i]->host_chain = curr_chain;
                curr_chain->weights.push_back(V->adj[i]->weight);
                heavy_light_decomposition(nxt, curr_chain);
                nxt->heavy_chain_id = V->heavy_chain_id = curr_chain-heavy_chains;
            }else
                heavy_light_decomposition(nxt);
        }
    }
}
vertex* LCA(vertex *u, vertex *v){
    #ifdef VVVV
    cout<<"FINDING LCA..."<<endl;
    #endif // VVVV
    int du,dv;
    vertex *hu, *hv;
    while(u!=v && (u->heavy_chain_id==-1 || u->heavy_chain_id!=v->heavy_chain_id)){
        if(u->heavy_chain_id == -1){
            du = u->depth;
            hu = u;
        }else
            du = heavy_chains[u->heavy_chain_id].head->depth, hu = heavy_chains[u->heavy_chain_id].head;

        if(v->heavy_chain_id == -1){
            dv = v->depth;
            hv = v;
        }else
            dv = heavy_chains[v->heavy_chain_id].head->depth, hv = heavy_chains[v->heavy_chain_id].head;
        if(du<dv){
            v = hv->parent_edge->u;
        }else{
            u = hu->parent_edge->u;
        }
    }
    if(u->depth < v->depth)
        return u;
    return v;
}
int query(vertex *u, vertex *v){
    //u is ancestor of v
    if(u == v)
        return 0;
    if(v->parent_edge->host_chain == NULL){  //Light
        return v->parent_edge->weight + query(u, v->parent_edge->u);
    }else{   //Heavy
        chain* host_chain = v->parent_edge->host_chain;
        if(host_chain->head->depth <= u->depth)
            return host_chain->query(u,v);
        else
            return host_chain->query(host_chain->head, v) + query(u, host_chain->head);
    }
}
int query_k(vertex *u, vertex *v, int k)
{
    if(k == 1)
        return v-V;
    if(v->parent_edge->host_chain == NULL)  //Light
        return query_k(u, v->parent_edge->u, k-1);
    else{   //Heavy
        chain* host_chain = v->parent_edge->host_chain;
        if(host_chain->weights.size()>= k)
            return query_k(u, v->parent_edge->u, k-1);
        else
            return query_k(u, host_chain->head, k-(v->depth-host_chain->head->depth));
    }
}
int main()
{
    in_T{
        int n,a,b,c;
        char str[10];
        in_I(n);
        root = NULL;
        chain_cnt = 0;
        for(int i=1;i<=n;i++)
            V[i].init();
        for(int i=0;i<n-1;i++){
            E[i].init();
            scanf("%d%d%d", &a, &b, &c);
            E[i].u = &V[a];
            E[i].v = &V[b];
            E[i].weight = c;
            V[a].adj.push_back(&E[i]);
            V[b].adj.push_back(&E[i]);
        }
        build(&V[1]);
        heavy_light_decomposition(&V[1]);
        for(int i=0;i<chain_cnt;i++)
            heavy_chains[i].build();
        #ifdef VVVV
        cout<<"Edges:"<<endl;
        for(int i=0;i<n-1;i++){
            cout<<i<<": "<<(E[i].u-V)<<" "<<(E[i].v-V)<<" "<<(E[i].host_chain == NULL?"light":"heavy")<<endl;
        }
        cout<<endl<<"Vertices:"<<endl;
        for(int i=1;i<=n;i++){
            cout<<i<<": "<<V[i].size<<" "<<V[i].depth<<" "<<(root == (V+i)?"root":"")<<endl;
        }
        #endif
        while(1){
            in_S(str);
            if(str[1] == 'I'){
                    // Distance between two nodes
                scanf("%d%d", &a, &b);
                #ifdef VVVV
                cout<<"QUERY "<<a<<" "<<b<<endl;
                #endif
                vertex *lca = LCA(&V[a], &V[b]);
                long long ans = 0;
                #ifdef VVVV
                cout<<"LCA: "<<lca-V<<endl;
                #endif
                ans = query(root, &V[a]);
                ans += query(root, &V[b]) - 2*query(root, lca);
                printf("%lld\n", ans);
            }
            else if(str[0] == 'K'){
                // cth node on path from a to b
                scanf("%d%d%d", &a, &b, &c);
                #ifdef VVVV
                cout<<"QUERY "<<a<<" "<<b<<" "<<c<<endl;
                #endif
                vertex *lca = LCA(&V[a], &V[b]);
                int total_nodes = V[a].depth-lca->depth + V[b].depth-lca->depth + 1;
                if(V[a].depth-lca->depth + 1 >= c)
                    P_I(query_k(lca, &V[a], c));
                else
                    P_I(query_k(lca, &V[b], total_nodes-c+1));
            }else
                break;
        }
        for(int i=0;i<chain_cnt;i++)
            heavy_chains[i].clear();
        cout<<endl;
    }
}
