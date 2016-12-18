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
#include<set>
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
int visited[100001];
int main()
{
    in_T
    {
        int n,m,src, dest;
        scanf("%d%d%d%d", &n, &m, &src, &dest);
        for(int i=1;i<=n;i++)
        visited[i] = 1<<30;
        vector<pair<int, int> > neigh[n+1];
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d%d%d\n", &a, &b, &c);
            neigh[a].push_back(make_pair(b,c));
            neigh[b].push_back(make_pair(a,c));
        }
        priority_queue<pair<int, int> > BFS;
        BFS.push(make_pair(0, src));
        int ans = -1;
        visited[src] = 0;
        while(!BFS.empty())
        {
            pair<int, int> tmp = BFS.top();
            BFS.pop();
            if(tmp.second == dest)
            {
                         ans = -tmp.first;
                         break;
            }
            for(int i=0;i<neigh[tmp.second].size();i++)
            {
                    if(visited[neigh[tmp.second][i].first]>visited[tmp.second]+neigh[tmp.second][i].second)
                    {
                       visited[neigh[tmp.second][i].first] = visited[tmp.second]+neigh[tmp.second][i].second;
                       BFS.push(make_pair(-visited[neigh[tmp.second][i].first], neigh[tmp.second][i].first));
                    }
            }
        }
        if(ans == -1)
        cout<<"NONE"<<endl;
        else
        cout<<ans<<endl;
    }
}



