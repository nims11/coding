/*
    Nimesh Ghelani (nims11)
    dfs
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
int n, a, b;
vector<int> neigh[10000];
int res = 0;
int dfs(int node, int par = -1)
{
    int ret = 0;
    int foo = 0;
    for(int i=0;i<neigh[node].size();i++)
    {
        if(neigh[node][i]!=par)
        {
            foo++;
            ret += dfs(neigh[node][i], node);
        }
    }
    ret += foo+1;
//    cout<<ret<<endl;
    res += ret;
    return ret;
}
int main()
{
    in_T
    {
        in_I(n);
        for(int i=0;i<n;i++)
            neigh[i].clear();
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        res = 0;
        dfs(0);
        printf("%d\n", res);
    }
}
