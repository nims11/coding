/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;
#define P_I(a) printf("%d",a)

using namespace std;
struct cylinder
{
    int o2,n2,wt;
//    friend bool operator<(const cylinder &a,const cylinder &b)
//    {
//        return a.wt<b.wt;
//    }
};
int n,ans;
cylinder cylinders[1002];
//void getans(int start,int o2,int n2,int curr)
//{
//    if(o2<=0 && n2<=0)
//    {
//        if(curr<ans)ans=curr;
//        return;
//    }
//    for(int i=start;i<n;i++)
//    {
//        if(curr+cylinders[i].wt<ans)
//        {
//            getans(i+1,o2-cylinders[i].o2,n2-cylinders[i].n2,curr+cylinders[i].wt);
//        }
//    }
//}
int main()
{
    in_T
    {
        int dp[200][200];
        for(int i=0;i<200;i++)
        {
            for(int j=0;j<200;j++)
            dp[i][j]=1<<30;
        }
        dp[0][0]=0;
        int o2,n2;
        in_I(o2);in_I(n2);
        in_I(n);
        for(int i=0;i<n;i++)
        {
            in_I(cylinders[i].o2);in_I(cylinders[i].n2);in_I(cylinders[i].wt);
        }
        ans=1<<30;
        for(int i=0;i<n;i++)
        {
            for(int j=170+o2;j>=cylinders[i].o2;j--)
            {
                for(int k=120+n2;k>=cylinders[i].n2;k--)
                {
                    dp[j][k]=min(dp[j][k],dp[j-cylinders[i].o2][k-cylinders[i].n2]+cylinders[i].wt);
                }
            }
        }
        for(int i=o2;i<200;i++)
        for(int j=n2;j<200;j++)
        if(dp[i][j]<ans)ans=dp[i][j];
//        getans(0,o2,n2,0);
        cout<<ans<<endl;
    }
}
