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
int n,m, c, d;
multiset<int> foo[100];
int P[10000];
int main()
{
    in_T
    {
        in_I(n);in_I(m);
        for(int i=0;i<n;i++)
            foo[i].clear();
        for(int i = 0; i < m ; i++)
            in_I(P[i]);
        for(int i = 0; i < n; i++)
        {
            in_I(c);
            while(c--)
            {
                in_I(d);
                foo[i].insert(-d);
            }
        }
        int ans = 0;
        for(int i = 0 ; i<m; i++)
        {
            if(foo[P[i]].begin() != foo[P[i]].end())
            {
                ans -= *foo[P[i]].begin();
                foo[P[i]].erase(foo[P[i]].begin());
            }
        }
        cout<<ans<<endl;
    }
}
