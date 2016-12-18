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
#include<cstring>
#include<cstdlib>
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
long long arr[10000];
int dp[2000];
void init()
{
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;
    dp[5] = 1;
    for(int i=6;i<2000;i++)
        dp[i] = 1 + min(dp[i-1], min(dp[i-2], dp[i-5]));
}
int main()
{
    init();
    in_T
    {
        in_I(n);
        for(int i=0;i<n;i++)
            in_L(arr[i]);
        sort(arr, arr+n);
        long long mini = arr[0];
        int res[6] = {0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=5;j++)
            {
                res[j] += dp[arr[i] - (mini-j)];
            }
//            cout<<res[0]<<endl;
        }
        int ans = res[0];
        for(int i=1;i<=5;i++)
            ans = min(ans, res[i]);
        printf("%d\n", ans);
    }
}
