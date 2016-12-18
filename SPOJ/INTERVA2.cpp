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
int n;
int BIT[200001];
int query(int idx)
{
    int ret = 0;
    while(idx>0)
    {
        ret += BIT[idx];
        idx -= idx & -idx;
    }
    return ret;
}
void update(int idx)
{
    while(idx<=n)
    {
        BIT[idx] ++;
        idx += idx & -idx;
    }
}
struct node
{
    int a,b;
    int idx;
}nodes[200000];
bool cmp1(const node &a, const node &b)
{
    return a.a<b.a;
}
bool cmp2(const node &a, const node &b)
{
    if(a.b == b.b)
        return a.a<b.a;
    return a.b>b.b;
}
int res[200000];
int main()
{
    while(in_I(n) != EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d", &nodes[i].a, &nodes[i].b);
            nodes[i].idx = i;
        }
        for(int i=0;i<=200000;i++)
            BIT[i] = 0;
        sort(nodes, nodes+n, cmp1);
        int curr = nodes[0].a;
        nodes[0].a = 1;
        for(int i=1;i<n;i++)
        {
            if(nodes[i].a!=curr)
            {
                curr = nodes[i].a;
                nodes[i].a = nodes[i-1].a+1;
            }else
                nodes[i].a = nodes[i-1].a;
        }
        sort(nodes, nodes+n, cmp2);
        curr = 0;
        res[nodes[0].idx] = 0;
        update(nodes[0].a);
        for(int i=1;i<n;i++)
        {
            if(nodes[i].b == nodes[i-1].b && nodes[i].a == nodes[i-1].a)
            curr++;
            else
            curr = 0;
            res[nodes[i].idx] = query(nodes[i].a)-curr;
            update(nodes[i].a);
        }
        for(int i=0;i<n;i++)
            printf("%d ", res[i]);
        newline;
    }
}
