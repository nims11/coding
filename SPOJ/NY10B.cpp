/*
    Nimesh Ghelani (nims11)
    Base conversion
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
int main()
{
    in_T
    {
        int t,b,x,y;
        scanf("%d%d%d%d", &t, &b, &x, &y);
        vector<int> foo, bar, res;
        while(x)
        {
            foo.push_back(x%b);
            x/=b;
        }
        while(y)
        {
            bar.push_back(y%b);
            y/=b;
        }
        for(int i=0;i<min(foo.size(), bar.size());i++)
            res.push_back((foo[i]+bar[i])%b);
        for(int i=min(foo.size(), bar.size()); i<max(foo.size(), bar.size());i++)
            if(foo.size()>bar.size())
                res.push_back(foo[i]);
            else
                res.push_back(bar[i]);
        int ans = 0;
        int baz = 1;
        for(int i=0;i<res.size();i++)
        {
            ans += baz*res[i];
            baz*=b;
        }
        printf("%d %d\n", t, ans);
    }
}
