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
#include<set>
using namespace std;
int n,q, tmp1, tmp2;
int x,y,d;
map<int, vector<int> > Y;
map<int, vector<int> >::iterator it, it1, it2;
void solve()
{
    int res = 0;
    it1 = Y.lower_bound(x);
    it2 = Y.upper_bound(x+d);
    for(it = it1; it!=it2; it++)
    {
        res += upper_bound(it->second.begin(), it->second.end(), y+(x+d-it->first)) - lower_bound(it->second.begin(), it->second.end(), y);
    }
    printf("%d\n", res);
}
int main()
{
    scanf("%d%d", &n, &q);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d", &tmp1, &tmp2);
        Y[tmp1].push_back(tmp2);
    }
    for(it = Y.begin();it!=Y.end();it++)
        sort(it->second.begin(), it->second.end());
    while(q--)
    {
        scanf("%d%d%d", &x, &y, &d);
        solve();
    }
}
