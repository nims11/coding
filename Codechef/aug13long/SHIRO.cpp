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
#include<cassert>
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
int a[101];
int P[101];
double p[101];
int pre[101];
long double dp[10001];
int main()
{
    in_T
    {
        int tot = 0;
        memset(dp, 0, sizeof(dp));
        in_I(n);
        for(int i = 1; i<=n; i++)
        {
            in_I(a[i]);
            tot += a[i];
        }
        for(int i = 1; i<=n; i++)
        {
            in_I(P[i]);
            p[i] = P[i]/100.0;
        }
        dp[0] = 1.0f;
        int lt = tot;
        for(int i = 1; i <= n; i++)
        {
            for(int j = lt; j>=0; j--)
            {
                if(j-a[i]>=0)
                    dp[j] = dp[j]*(1-p[i]) + dp[j-a[i]]*p[i];
                else
                    dp[j] = dp[j]*(1-p[i]);
//                cout<<j<<" "<<dp[j]<<endl;
            }
        }
        long double sum = 0;
        for(int i = (tot+1)/2; i<=lt; i++)
        {
            sum += dp[i];
        }
        printf("%.7llf\n", sum);
    }

}
