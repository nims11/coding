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
int dp[1000];
int arr[1000];
int pre[1001];
long long pref[1001], suff[1001];
int main()
{
    int n;
    while(in_I(n) != EOF)
    {
        for(int i = 0;i<n;i++)
            in_I(arr[i]), dp[i] = 1, pre[i] = -1;
        for(int i = 1;i<=n;i++)
            pref[i] = pref[i-1]+arr[i-1];
        int maxi = 0;
        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<i;j++)
                if(arr[i]>=arr[j] && dp[j]+1 > dp[i])
                {
                    dp[i] = dp[j]+1;
                    pre[i] = j;
                    if(dp[i] > dp[maxi])
                        maxi = i;
                }
        }
        vector<int> LIS;
        while(maxi != -1)
        {
            LIS.push_back(maxi);
//            cout<<maxi<<" ";
            maxi = pre[maxi];
        }
//        newline;
        int curr = LIS.size()-1;
        long long res = 0;
        for(int i = 0;i<LIS[curr];i++)
            res += arr[i]-LIS[curr];
        curr--;
//        cout<<res<<endl;
        while(curr >= 0)
        {
//            cout<<curr<<endl;
            pref[LIS[curr+1]] = 0;
            suff[LIS[curr]] = 0;
            for(int i = LIS[curr+1]+1;i<LIS[curr];i++)
                pref[i] = abs(arr[i]-arr[LIS[curr+1]])+pref[i-1];

            for(int i = LIS[curr]-1;i>LIS[curr+1];i--)
                suff[i] = abs(arr[i]-arr[LIS[curr]])+suff[i+1];
            long long add = suff[LIS[curr+1]+1];
            for(int i = LIS[curr+1]+1;i<LIS[curr];i++)
                add = min(add, pref[i]+suff[i+1]);
            res += add;
            curr--;
        }
//        cout<<res<<endl;
        for(int i = LIS[0]+1;i<n;i++)
            res += arr[LIS[0]]-arr[i];
        printf("%lld\n", res);
    }
}
