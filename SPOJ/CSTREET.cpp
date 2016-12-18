/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}

using namespace std;
int rank[1004],sum[1004],p,n,m,a,b,c;
struct foo
{
    int a,b,wt;
    friend bool operator<(const foo &a,const foo &b)
    {
        return a.wt<b.wt;
    }
}bar;
vector<struct foo> path;
void kruskal()
{
    for(int i=0;i<path.size();i++)
    {
        if(rank[path[i].a]!=rank[path[i].b])
        {
            if(rank[path[i].a]<rank[path[i].b])
            {
                int tmp=rank[path[i].b];
                for(int j=1;j<=n;j++)
                {
                    if(rank[j]==tmp)
                    {
                        rank[j]=rank[path[i].a];
                    }
                }
                sum[rank[path[i].a]]+=path[i].wt+sum[tmp];
            }else
            {
                int tmp=rank[path[i].a];
                for(int j=1;j<=n;j++)
                {
                    if(rank[j]==tmp)
                    rank[j]=rank[path[i].b];
                }
                sum[rank[path[i].b]]+=path[i].wt+sum[tmp];
            }
        }
    }
}
int main()
{
    in_T
    {
        in_I(p);in_I(n);in_I(m);
        path.clear();
        for(int i=1;i<=n;i++)
        {rank[i]=i;sum[i]=0;}
        for(int i=0;i<m;i++)
        {
            in_I(bar.a);in_I(bar.b);in_I(bar.wt);
            path.push_back(bar);
        }
        sort(path.begin(),path.end());
        kruskal();
        printf("%d\n",sum[1]*p);
    }
}
