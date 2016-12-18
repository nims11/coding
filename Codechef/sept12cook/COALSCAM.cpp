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
struct edge
{
    int a,b,c;
    friend bool operator<(const struct edge &a,const struct edge &b)
    {
        return a.c>b.c;
    }
}tmp;
int main()
{
    in_T
    {
        int n,m1,m2;
        cin>>n>>m1>>m2;
        vector<edge> M1(m1),M2(m2);
        vector<int> nodes(n);
        for(int i=0;i<m1;i++)
        {
            in_I(M1[i].a);
            in_I(M1[i].b);
            in_I(M1[i].c);
        }
        for(int i=0;i<m2;i++)
        {
            in_I(M2[i].a);
            in_I(M2[i].b);
            in_I(M2[i].c);
        }
        for(int i=0;i<n;i++)
            nodes[i]=i;

        sort(M1.begin(),M1.end());
        sort(M2.begin(),M2.end());
        long long profit=0,cost=0;
        for(int i=0;i<m2;i++)
        {
            if(nodes[M2[i].a]!=nodes[M2[i].b])
            {
                cost+=M2[i].c;
                profit+=M2[i].c;
                int x,y;
                if(nodes[M2[i].a]>nodes[M2[i].b])
                x=nodes[M2[i].b], y = nodes[M2[i].a];
                else
                y=nodes[M2[i].b], x = nodes[M2[i].a];

                for(int i=y;i<n;i++)
                {
                    if(nodes[i]==y)
                        nodes[i]=x;
                }
            }
        }
        for(int i=m1-1;i>=0;i--)
        {
            if(nodes[M1[i].a]!=nodes[M1[i].b])
            {
                cost+=M1[i].c;
                int x,y;
                if(nodes[M1[i].a]>nodes[M1[i].b])
                x=nodes[M1[i].b], y = nodes[M1[i].a];
                else
                y=nodes[M1[i].b], x = nodes[M1[i].a];

                for(int i=y;i<n;i++)
                {
                    if(nodes[i]==y)
                        nodes[i]=x;
                }
            }
        }
        int i=0;
        while(nodes[i]==0 && i<n)
            i++;
        if(i==n)
        {
            cout<<profit<<" "<<cost<<endl;
        }else
            cout<<"Impossible\n";
    }
}
