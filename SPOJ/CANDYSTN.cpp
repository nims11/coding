/*
    Nimesh Ghelani (nims11)
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
int n,m,prev,curr,min_A, min_B;
int main()
{
    in_T
    {
        scanf("%d%d",&n,&m);
        in_I(prev);
        min_A = n, min_B =0;
        int coll=0;
        int ans = 1;
        int bag = n;
        for(int i=1;i<m;i++)
        {
            in_I(curr);
            if(prev==curr)coll--;
            else{
            bag-=curr-prev;
            coll += curr-prev;
            }
            min_A = min(min_A, bag);
            min_B = min(min_B, coll);
            prev=curr;
        }
        ans = 1-min_B;
        if(min_A - ans<0)
        ans=-1;
        printf("%d\n",ans);
    }
}
