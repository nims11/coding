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
set<int> lower[1003];
int indeg[1003];
int n, r;
int ans[1003];
set<int> rev[1003];
void dfs(int idx, int a)
{
    ans[idx] = a;
    for(set<int>::iterator it = lower[idx].begin(); it != lower[idx].end();it++)
        if(ans[*it]<a+1)
            dfs(*it, a+1);

}
int main()
{
    int z = 0, x, y;
    in_T
    {
        z++;
        in_I(n);
        in_I(r);

        for(int i=0;i<n;i++)
            lower[i].clear(),
            indeg[i] = 0,
            ans[i] = -1,
            rev[i+1].clear();
        while(r--)
        {
            scanf("%d%d", &x, &y);
            lower[y].insert(x);
            indeg[x]++;
        }
        for(int i=0;i<n;i++)
            if(!indeg[i])
                dfs(i, 1);
        int maxi = 0;
        for(int i=0;i<n;i++)
        {
            rev[ans[i]].insert(i);
            maxi = max(maxi, ans[i]);
        }
        printf("Scenario #%d:\n", z);
        for(int i=1;i<=maxi;i++)
        {
            for(set<int>::iterator it = rev[i].begin(); it != rev[i].end(); it++)
                printf("%d %d\n", i, *it);
        }
    }
}
