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
vector<int> adj[1001];
int color[1001];
int n, k, x, y;
int main()
{
    in_T
    {
        in_I(n);
        for(int i=1;i<=n;i++)
        {
            color[i] = -1;
            adj[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
            in_I(k);
            while(k--)
            {
                in_I(y);
                adj[i].push_back(y);
                adj[y].push_back(i);
            }
        }
        bool flag = true;
        for(int i=1;i<=n;i++)
        {
            queue<int> BFS;
            if(color[i] == -1)
            {
                color[i] = 0;
                BFS.push(i);
            }
            while(!BFS.empty() && flag)
            {
                int x = BFS.front();
                BFS.pop();
                for(int j=0;j<adj[x].size();j++)
                {
                    if(color[adj[x][j]] == -1)
                    {
                        color[adj[x][j]] = !color[x];
                        BFS.push(adj[x][j]);
                    }else
                    {
                        if(color[adj[x][j]] == color[x])
                        {
                            flag = false;
                            i = n+1;
                            break;
                        }
                    }
                }
            }
        }
        if(!flag)
        {
            printf("-1");
        } else
        for(int i=1;i<=n;i++)
            printf("%c", (color[i]?'R':'L'));
        newline;
    }
}
