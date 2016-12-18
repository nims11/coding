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
class EDGE
{
    public:
    static int id;
    int id2;
    int u,v,w;
    int u1,v1,w1;
    EDGE(int u,int v,int w)
    {
        id2 = id++;
        this->u = u;
        this->v = v;
        this->w = w;
    }
    void set_vr(int u,int v,int w)
    {
        this->u1 = u;
        this->v1 = v;
        this->w1 = w;
    }
};
int EDGE::id = 0;
class FlowNet
{
    public:
    map<int,vector<EDGE> > adj;
    map<int, int > flow;
    FlowNet()
    {

    }
    void add_vertex(int vertex)
    {
        adj[vertex];
    }
    vector<EDGE> get_edges(int vertex)
    {
        return adj[vertex];
    }
    void add_edge(int u,int v,int w=0)
    {
        EDGE edge(u,v,w);
        EDGE redge(v,u,0);
        edge.set_vr(v,u,0);
        redge.set_vr(u,v,w);
        adj[u].push_back(edge);
        adj[v].push_back(redge);
        flow[edge.id2] = 0;
        flow[redge.id2] = 0;
    }

    int max_flow(int source,int sink)
    {

    }
};
int main()
{

}
