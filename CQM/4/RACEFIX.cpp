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
int n, tot;
struct node{
    int a, b;
    int v1, v2;
}nodes[20001];
int v1, v2;
int main()
{
    while(scanf("%d%d", &n, &tot) != EOF)
    {
        for(int i = 0;i<tot;i++)
            in_I(nodes[i].v2);in_I(nodes[i].v2);
        v1 = nodes[tot-1].v1, v2 = nodes[n-1].v2;
        for(int i = 0;i<tot-1;i++)
        {
            nodes[i].a = v1-v2+nodes[i].v2-nodes[i].v1;
            nodes[i].b = n*(v2-nodes[i].v2);
        }
        int start =
    }
}
