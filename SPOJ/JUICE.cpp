/*
    Nimesh Ghelani (nims11)
    DP
    dp[i], when ith fruit appears
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
    int cc = 0;
    in_T
    {
        cc++;
        int n;
        in_I(n);
        int dp[n+2];
        dp[0] = 0;
        dp[n+1] = 0;
        pair<int, int> arr[n+1];
        for(int i=1;i<=n;i++)
        {
            in_I(arr[i].first);
            in_I(arr[i].second);
        }
        sort(arr+1, arr+n+1);
        for(int i=1;i<=n;i++)
        {
//            while(i<n && arr[i].first==arr[i+1].first)
//            {
//                dp[i] = dp[i-1];
//                i++;
//            }
            dp[i] = dp[i-1];
            int foo = 0;
            int till=1;
            for(int j=1;j<=n && arr[i].first>=arr[j].first;j++)
            {
                if(arr[j].second>=arr[i].first)
                {
                    foo++;
                }
                till = j;
            }

            for(int j=1;j<=till;j++)
            {
                int bar = j-1;
                int tmp = (arr[j].second>=arr[i].first);
                while(j<till && arr[j].first==arr[j+1].first)
                {
                    j++;
                    tmp+=(arr[j].second>=arr[i].first);
                }
                if(foo<=2)
                    dp[i] = max(dp[i], dp[bar]);
                else
                    dp[i] = max(dp[i],dp[bar]+foo);
                foo -= tmp;
            }
//            cout<<arr[i].first<<" "<<arr[i].second<<" "<<dp[i]<<endl;
        }
        printf("Case #%d: %d\n", cc, dp[n]);
    }
}

