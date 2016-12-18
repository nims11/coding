/*
 * greedy
 * sort activities according to activities which end first.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
using namespace std;
int n,tmp1,tmp2;
struct bux
{
    int start,end;
    friend bool operator<(const bux &a,const bux &b)
    {
        if(a.end==b.end)return a.start>b.start;
        return a.end<b.end;
    }
};
int main()
{
    in_T
    {
        in_I(n);
vector<bux> foo;
        for(int i=0;i<n;i++)
        {
int a,b;bux tmp;
in_I(a);in_I(b);tmp.start=a;tmp.end=b;
foo.push_back(tmp);
        }
        std::sort(foo.begin(),foo.end());
        int ans=0;
        int curr=-1;
        for(int i=0;i<n;i++)
        {
            if(curr<=foo[i].start)
            {
                ans++;
                curr=foo[i].end;
            }
        }
        printf("%d\n",ans);
    }
}



