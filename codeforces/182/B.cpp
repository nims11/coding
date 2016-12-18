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
int adj[100][100];
int pt[100][2];
int a[100];
struct node
{
    int mini;
    int idx;
    int cur;
    friend bool operator<(const node &a, const node &b)
    {
        return a.mini>b.mini;
    }
}tmp;
int visited[300];
int main()
{
    int n,d;
    in_I(n);
    in_I(d);
    for(int i=1;i<n-1;i++)
        in_I(a[i]);
    for(int i=0;i<n;i++)
    {
        in_I(pt[i][0]);
        in_I(pt[i][1]);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            adj[i][j] = abs(pt[i][0]-pt[j][0]) + abs(pt[i][1]-pt[j][1]);
    priority_queue<node> BFS;
    tmp.mini = 0;
    tmp.idx = 0;
    tmp.cur = 0;
    BFS.push(tmp);
    while(!BFS.empty())
    {
        tmp = BFS.top();
        BFS.pop();
        if(visited[tmp.idx])continue;
        visited[tmp.idx] = 1;
        if(tmp.idx == n-1)
            break;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                node tmp2;
                tmp2.idx = i;
                tmp2.cur = tmp.cur - d*adj[i][tmp.idx];
                tmp2.mini = tmp.mini;
                if(tmp2.cur<0)
                {
                    tmp2.mini -= tmp2.cur;
                    tmp2.cur = 0;
                }
                tmp2.cur += a[i];
                BFS.push(tmp2);
            }
        }
    }
    printf("%d\n", tmp.mini);
}
