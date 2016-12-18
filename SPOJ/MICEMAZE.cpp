/*
    Nimesh Ghelani (nims11)
    BFS
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;
#define P_I(a) printf("%d",a)

using namespace std;
int main()
{
    int N,E,T;
    in_I(N);in_I(E);in_I(T);
    int M;
    in_I(M);
    int graph[102][102]={{0}},a,b,c;
    for(int i=0;i<M;i++)
    {
        in_I(a);in_I(b);in_I(c);
        graph[a][b]=c;
    }
    int distance[102];
    for(int i=0;i<102;i++)
    distance[i]=1<<30;
    distance[E]=0;
    queue<int> BFS;
    BFS.push(E);
    while(!BFS.empty())
    {
        int k=BFS.front();
        BFS.pop();
        for(int i=1;i<=N;i++)
        {
            if(graph[i][k])
            {
                if(distance[i]>distance[k]+graph[i][k])
                {
                    distance[i]=distance[k]+graph[i][k];
                    BFS.push(i);
                }
            }
        }
    }
//    for(int i=0;i<=N;i++)
//    cout<<i<<" "<<distance[i]<<endl;
    sort(distance,distance+N+1);
    int ans=0;
    for(int i=0;i<N;i++)
    {
        if(distance[i]>T)break;
        ans++;
    }
    cout<<ans<<endl;
}
