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
#define P_I(a) printf("%d",a)

using namespace std;
struct vertex;
struct edge;
struct chain;
struct vertex
{
    vector<edge*> adj;
    edge* parent_edge;
    int heavy_chain_id;
    int tree_id;
    int size,depth;
    void init()
    {
        parent_edge = NULL;
        heavy_chain_id = tree_id = -1;
        size = depth =0;
    }
};
struct edge
{
    vertex *u,*v;
    chain* host_chain;
    int weight;
    void init()
    {
        u = v = NULL;
        host_chain = NULL;
    }
};
struct node
{
    int left_max_sum, right_max_sum, max_sum, sum, left_min_sum, right_min_sum, min_sum;
};
struct chain
{
    vector<int> weights;
    vertex *head;int size;
    node *TREE;
    int *sign;

    // Chain Methods
    void build()
    {
        size = weights.size();
        TREE = new node[size*4];
        sign = new int[size*4];
        build_segment_tree(1, 0, size-1);
    }
    node query(vertex *u, vertex *v)
    {
        int x,y;
        x = u->depth-head->depth,
        y = v->depth-head->depth-1;
        return query_segment_tree(1, 0, size-1, x, y);
    }
//    int update(edge *e, int w)
//    {
//        weights[e->u->depth-head->depth] = w;
//        update_segment_tree(1, 0, size-1, e->u->depth-head->depth);
//    }

    //Segment Tree Methods
    void build_segment_tree(int NODE,int a,int b)
    {
        sign[NODE] = 1;
        if(a==b)
        {
            TREE[NODE].sum = weights[a];
            if(weights[a]<0)
            {
                TREE[NODE].left_max_sum = TREE[NODE].right_max_sum = TREE[NODE].max_sum = 0;
                TREE[NODE].left_min_sum = TREE[NODE].right_min_sum = TREE[NODE].min_sum = weights[a];
            }
            else
            {
                TREE[NODE].left_max_sum = TREE[NODE].right_max_sum = TREE[NODE].max_sum = weights[a];
                TREE[NODE].left_min_sum = TREE[NODE].right_min_sum = TREE[NODE].min_sum = 0;
            }
            return;
        }
        int mid=(a+b)/2;
        int left=2*NODE,right=2*NODE+1;
        build_segment_tree(left,a,mid);
        build_segment_tree(right,mid+1,b);

        TREE[NODE].left_max_sum = max(TREE[left].left_max_sum, TREE[left].sum+TREE[right].right_max_sum);
        TREE[NODE].sum = TREE[left].sum + TREE[right].sum;
        TREE[NODE].right_max_sum = max(TREE[right].right_max_sum, TREE[right].sum + TREE[left].right_max_sum);
        TREE[NODE].max_sum = max(TREE[left].right_max_sum + TREE[right].left_max_sum, max(TREE[left].max_sum, TREE[right].max_sum));

        TREE[NODE].left_min_sum = min(TREE[left].left_min_sum, TREE[left].sum+TREE[right].right_min_sum);
        TREE[NODE].right_min_sum = min(TREE[right].right_min_sum, TREE[right].sum + TREE[left].right_min_sum);
        TREE[NODE].min_sum = min(TREE[left].right_min_sum + TREE[right].left_min_sum, min(TREE[left].min_sum, TREE[right].min_sum));
    }
    node query_segment_tree(int NODE,int a,int b,int x,int y, int carry=1)
    {
        if(x<=a && y>=b)return TREE[NODE];
        int mid=(a+b)/2;
        int left=2*NODE,right=2*NODE+1;
        if(y<=mid)return query_segment_tree(left,a,mid,x,y);
        if(x>mid)return query_segment_tree(right,mid+1,b,x,y);

        node left_query=query_segment_tree(left,a,mid,x,y);
        node right_query=query_segment_tree(right,mid+1,b,x,y);
        node ans;

        ans.left_max_sum = max(left_query.left_max_sum, left_query.sum+right_query.right_max_sum);
        ans.sum = left_query.sum + right_query.sum;
        ans.right_max_sum = max(right_query.right_max_sum, right_query.sum + left_query.right_max_sum);
        ans.max_sum = max(left_query.right_max_sum + right_query.left_max_sum, max(left_query.max_sum, right_query.max_sum));

        return ans;
    }
//    void update_segment_tree(int NODE,int a,int b,int x)
//    {
//        if(a==b)
//        {
//            TREE[NODE]=weights[a];
//            return;
//        }
//        int mid=(a+b)/2;
//        int left=2*NODE,right=2*NODE+1;
//        if(x<=mid)
//        update_segment_tree(left,a,mid,x);
//        else
//        update_segment_tree(right,mid+1,b,x);
//
//        TREE[NODE] = max(TREE[left], TREE[right]);
//    }
};
struct Cycle
{
    vector<int> weights;
}cycle;
vertex *root[1000002] = {NULL};
edge *link_cycle[1000002] = {NULL};
int chain_cnt = 0;
int tree_cnt = 0;
vertex V[1000002];
edge E[1000002];
chain heavy_chains[1000002];
int N;
bool visited[1000002];
int build_cycle(int u, int par)
{
    visited[u] = true;
    for(int i=0;i<V[u].adj.size();i++)
    {
        int v = (V[u].adj[i]->u-V == u)?V[u].adj[i]->v-V:V[u].adj[i]->u-V;
        if(v != par)
        {
            if(visited[v])
            {
                V[v].depth = 0;
                V[v].tree_id = 0;
                V[u].tree_id = 0;
                V[u].depth = 1;
                return V[u].depth + 1;
            }else
            {
                int x = build_cycle(v, u);
                if(V[u].tree_id == 0)
                    return 0;
                V[u].tree_id = 0;
                V[u].depth = x;
                return x+1;
            }
        }
    }
    return 0;
}

void build(vertex *V, vertex* par=NULL)
{
    V->tree_id = tree_cnt;
    if(par == NULL)
    {
        root[tree_cnt] = V;
        V->depth = 0;
    }else
        V->depth = par->depth+1;

    V->size = 1;
    for(int i=0;i<V->adj.size();i++)
    {
        vertex *nxt = (V->adj[i]->u == V)?V->adj[i]->v:V->adj[i]->u;
        if(nxt != par && nxt->tree_id == -1)
        {
            nxt->parent_edge = V->adj[i];
            build(nxt, V);
            V->adj[i]->u = V;
            V->adj[i]->v = nxt;
            V->size += nxt->size;
        }
    }
}

void heavy_light_decomposition(vertex *V, chain *curr_chain = NULL)
{
    for(int i=0;i<V->adj.size();i++)
    {
        vertex *nxt = V->adj[i]->v;
        if(nxt!=V)
        {
            if(2*nxt->size >= V->size)
            {
                if(curr_chain == NULL)
                {
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
#define VVVV

int main()
{
    in_I(N);
    for(int i=1;i<=N;i++)
        V[i].init();
    int u,v,c;
    for(int i=0;i<N;i++)
    {
        scanf("%d%d%d", &u, &v, &c);
        E[i].init();
        E[i].u = &V[u];
        E[i].v = &V[v];
        E[i].weight = c;
        V[u].adj.push_back(&E[i]);
        V[v].adj.push_back(&E[i]);
    }
    build_cycle(1, 0);
    #ifdef VVVV
    cout<<"Cycle formed with depth: "<<endl;
    for(int i=1;i<=N;i++)
        if(V[i].tree_id == 0)
        cout<<i<<" "<<V[i].depth<<endl;
    #endif
    for(int i=1;i<=N;i++)
    {
        if(V[i].tree_id == 0)
        {
            for(int j=0;j<V[i].adj.size();j++)
            {
                int v = (V[i].adj[j]->u-V == i)?V[i].adj[j]->v-V:V[i].adj[j]->u-V;
                if(V[v].tree_id == -1)
                {
                    tree_cnt++;
                    build(&V[v]);
                    link_cycle[tree_cnt] = V[i].adj[j];
                    heavy_light_decomposition(&V[v]);
                }
            }
        }
    }

}
