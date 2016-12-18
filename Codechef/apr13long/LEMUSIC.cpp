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
pair<int, int> foo[100001];
set<int> bar;
int main()
{
    in_T
    {
        bar.clear();
        in_I(n);
        for(int i=0;i<n;i++)
            scanf("%d%d", &foo[i].second, &foo[i].first);
        long long unsigned ans = 0;
        long long unsigned tmp = 0;
        sort(foo, foo+n);
        for(int i=0;i<n;i++)
        {
            if(bar.find(foo[i].second) != bar.end())
            {
                tmp += foo[i].first;
            }else
            {
                ans += (bar.size()+1)*(long long unsigned)foo[i].first;
                bar.insert(foo[i].second);
            }
        }
        ans += tmp*bar.size();
        cout<<ans<<endl;
    }
}
