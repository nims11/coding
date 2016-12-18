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
int n, m;
int visited[1<<16];
const int INF = 1e9;
int sw[100];
int main()
{
    int z = 0;
    in_T
    {
        z++;
        in_I(n);
        in_I(m);
        int cur_state = 0;
        int fin = (1<<n)-1;
        for(int i=0;i<(1<<n);i++)
            visited[i] = 1e9;
        queue<int> BFS;
        int x;
        for(int i=0;i<m;i++)
        {
            sw[i] = 0;
            for(int j = 0; j<n; j++)
            {
                in_I(x);
                sw[i] = (sw[i]<<1)|x;
            }
        }
        BFS.push(0);
        visited[0] = 0;
        while(!BFS.empty())
        {
            x = BFS.front();
            BFS.pop();
            if(x == fin)
                break;
            for(int i=0;i<m;i++)
            {
                int y = x^sw[i];
                if(visited[y]>visited[x]+1)
                {
                    visited[y] = visited[x]+1;
                    BFS.push(y);
                }
            }
        }
        if(visited[fin] != INF)
            printf("Case %d: %d\n", z, visited[fin]);
        else
            printf("Case %d: IMPOSSIBLE\n", z);
    }
}
