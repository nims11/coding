/*
    Nimesh Ghelani (nims11)

    BFS
    create a dependency graph and use priority queue to traverse.
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
int n,m;
vector<int>ans;
int neigh[101][101] = {{0}};
int indeg[101] = {0};

int main()
{
    in_I(n);
    in_I(m);
    int tmp1,tmp2,tmp3;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&tmp1,&tmp2);
        while(tmp2--)
        {
            in_I(tmp3);
            neigh[tmp3][tmp1] = 1;
            indeg[tmp1]++;
        }
    }
    int start;
    priority_queue<int> BFS;
    for(int i=1;i<=n;i++)
    if(!indeg[i])BFS.push(-i);

    int visited[101] = {0};
    while(!BFS.empty())
    {
        int curr = -BFS.top();
        BFS.pop();
        ans.push_back(curr);
        visited[curr] = 1;
        for(int i=1;i<=n;i++)
        {
            if(neigh[curr][i])
            {
                indeg[i]--;
                if(indeg[i]==0 && !visited[i])
                BFS.push(-i);
            }
        }
    }
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]);
    newline;
}
