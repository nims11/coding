/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
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
int n;
struct vertex
{
    vector<int> neigh;
    int index, component, lowlink;
}v_tmp, vertices[1000];
int i_tmp,tmp2;
int indeg[1000];
bool visited[1000];
stack<int> DFS;
int index;
int connected;
void strongconnect(int id)
{
    vertices[id].index = vertices[id].lowlink = index;
    index++;
    DFS.push(id);
    visited[id] = true;
    int w;
    for(int j=0;j<vertices[id].neigh.size(); j++)
    {
        w = vertices[id].neigh[j];
        if(vertices[w].index == -1)
        {
            strongconnect(w);
            vertices[id].lowlink = min(vertices[id].lowlink, vertices[w].lowlink);
        }else if(visited[w])
            vertices[id].lowlink = min(vertices[id].lowlink, vertices[w].index);
    }
    if(vertices[id].lowlink == vertices[id].index)
    {
        do{
            w = DFS.top();
            DFS.pop();
            visited[w] = false;
            vertices[w].component = connected;
        }while(id != w);
        connected++;
    }
}
int main()
{
   in_T
   {
       in_I(n);
       for(int i=0;i<n;i++)
            vertices[i].neigh.clear(), vertices[i].index=-1, visited[i] = false, indeg[i]=0;
       for(int i=0;i<n;i++)
       {
          in_I(i_tmp);
          while(i_tmp--)
          {
              in_I(tmp2);
              vertices[tmp2-1].neigh.push_back(i);
          }
       }
       index=0;
       connected = 0;
       for(int i=0;i<n;i++)
           if(vertices[i].index == -1)
                strongconnect(i);


        for(int i=0;i<n;i++)
        for(int j=0;j<vertices[i].neigh.size();j++)
        {
            if(vertices[i].component != vertices[vertices[i].neigh[j]].component)
                indeg[vertices[vertices[i].neigh[j]].component]++;
        }
        int zeroes= 0;
        int z;
        for(int i=0;i<connected;i++)
            if(indeg[i]==0)
            {
                zeroes++;
                z = i;
            }
        if(zeroes!=1){printf("0\n");continue;}
        int ans=0;
        for(int i=0;i<n;i++)
            if(vertices[i].component == z)
                ans++;
        printf("%d\n", ans);
   }
}
