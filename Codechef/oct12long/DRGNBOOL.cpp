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
int main()
{
    in_T
    {
        int foo[101]={0};
        int n,m,tmp1,tmp2;
        in_I(n);
        in_I(m);
        for(int i=0;i<n;i++)
        {
            in_I(tmp1);in_I(tmp2);
            foo[tmp2]+=tmp1;
        }
        for(int i=0;i<m;i++)
        {
            in_I(tmp1);in_I(tmp2);
            foo[tmp2]-=tmp1;
        }
        int ans=0;
        for(int i=1;i<101;i++)
        {
            if(foo[i]<0)
                ans-=foo[i];
        }
        cout<<ans<<endl;
    }
}
