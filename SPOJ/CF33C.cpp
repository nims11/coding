//GQ
/*
    Nimesh Ghelani (nims11)
    DP
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
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int n,tmp,sum[100004],dp1[100004],dp2[100004];
int main()
{
    in_T
    {
        in_I(n);
        sum[0]=0;
        dp1[0]=0;
        for(int i=1;i<=n;i++)
        {
            in_I(tmp);
            sum[i] = sum[i-1] + tmp;
            dp1[i] = max(sum[i]-sum[i-1] + dp1[i-1],-sum[i]);
        }
        dp2[0]=0;
        for(int i=1;i<=n;i++)
        {
            dp2[i] = max(sum[n-i+1]-sum[n-i]+dp2[i-1],-sum[n]+sum[n-i]);
        }
        int ans = -(1<<30);
        for(int i=0;i<=n;i++)
        ans = max(ans,dp1[i]+dp2[n-i]);
        cout<<ans<<endl;
    }
}
