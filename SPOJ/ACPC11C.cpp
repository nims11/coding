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

using namespace std;
int main()
{
    in_T
    {
        int sum = 0;
        int n, tmp;
        in_I(n);
        int arr[n], pre_sum[n];
        pre_sum[0] = 0;
        long long ans = 10000000000LL;
        for(int i=0;i<n;i++)
            {in_I(arr[i]);sum+=arr[i];}
        for(int i=1;i<n;i++)
        {
            pre_sum[i] = arr[i-1]+pre_sum[i-1];
        }
        for(int i=0;i<n;i++)
        {
//            cout<<pre_sum[i]<<endl;
            long long Q = min(pre_sum[i], sum-pre_sum[i]-arr[i]);
            ans = min(ans, 2*Q+(sum-arr[i]-Q));
//            cout<<" "<<ans<<endl;
        }
        printf("%lld\n", ans);
    }
}
