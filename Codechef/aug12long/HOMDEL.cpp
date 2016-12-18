/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<queue>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int T[252][252],n;
int dist[252][252];
void shortest_path()
{
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    dist[i][j]=T[i][j];

    for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
}
int main()
{
    int s,g,d,t1,t2;
    in_I(n);
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    in_I(T[i][j]);
    int q;
    shortest_path();
    in_I(q);
    while(q--)
    {
        scanf("%d%d%d",&s,&g,&d);
        t1 = dist[s][g]+dist[g][d];
        t2 = t1 - dist[s][d];
//        cout<<t1<<" "<<t2<<" "<<t3<<endl;
        printf("%d %d\n",t1,t2);
    }
}
