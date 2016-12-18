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
struct foo
{
    int a,b,c;
    friend bool operator<(const foo &a,const foo &b)
    {
        return a.b<b.b;
    }
}bar[2000];
int main()
{
    in_T
    {
        int n;
        in_I(n);
        int dp[49]={0};
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&bar[i].a,&bar[i].b,&bar[i].c);
        }
        sort(bar,bar+n);
        for(int i=0;i<n;i++)
        {
            if(dp[bar[i].b]<dp[bar[i].a]+bar[i].c)
            {
                for(int j=bar[i].b;j<49;j++)
                dp[j]=dp[bar[i].a]+bar[i].c;
            }
        }
        cout<<dp[48]<<endl;
    }
}
