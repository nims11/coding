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
#include<sstream>
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
        string str1, str2;
        cin.ignore(1);
       getline(cin, str1);
       getline(cin, str2);
       stringstream ss1(str1), ss2(str2);
       int tmp1, tmp2;
       while(ss1>>tmp1)
       {
           ss2>>tmp2;
           vertices[tmp1-1].neigh.push_back(tmp2-1);
       }
       index=0;
       connected = 0;
       for(int i=0;i<n;i++)
           if(vertices[i].index == -1)
                strongconnect(i);

        map<int, int> foo;
        map<int, int>::iterator it;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            it = foo.find(vertices[i].component);
            if(it == foo.end())
            {
                foo[vertices[i].component] = 1;
            }else
            it->second++;
        }
        for(it = foo.begin();it!=foo.end();it++)
            ans = max(ans, it->second);
        cout<<ans<<endl;
   }
}
