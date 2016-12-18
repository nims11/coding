/*
    Nimesh Ghelani (nims11)
    given entry and exit time of people, find the maximum number of people present at a time.

    at every time instance, +1 for entry, -1 for exit.
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
int main()
{
    in_T
    {
        map<int, pair<int, int> > foo;
        map<int, pair<int, int> >::iterator it;
        int n;
        in_I(n);
        int a,b;
        for(int i=0;i<n;i++)
        {
            in_I(a);in_I(b);
            it = foo.find(a);
            if(it == foo.end())
            {
                foo[a] = make_pair(1,0);
            }else
                it->second.first++;
            it = foo.find(b);
            if(it == foo.end())
            {
                foo[b] = make_pair(0,1);
            }else
                it->second.second++;
        }
        int ans  =0 ;
        int curr=0;
        for(it = foo.begin(); it!=foo.end();  it++)
        {
            curr += it->second.first;
            ans = max(ans, curr);
            curr -= it->second.second;
        }
        cout<<ans<<endl;
    }
}
