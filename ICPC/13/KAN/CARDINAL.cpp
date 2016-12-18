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
int n, x;
int arr[101];
int masks[101];
int ans;
int sum;
pair<int, int> dp[101][1024];
pair<int, int> getans(int idx, int mask)
{
    if(dp[idx][mask].first != -1)
        return dp[idx][mask];
    pair<int, int> &ans = dp[idx][mask];
    ans = getans(idx+1, mask);
    if((mask & masks[idx]) == 0)
    {
        pair<int, int> tmp = getans(idx+1, mask|masks[idx]);
        tmp.second++;
        tmp.first += arr[idx];
        if(tmp.first > ans.first)
            ans = tmp;
        else if(tmp.first == ans.first && ans.second < tmp.second)
            ans = tmp;
    }
    return ans;
}
int main()
{
    while(in_I(n) != EOF)
    {
        for(int i=0;i<n;i++)
        {
            in_I(arr[i]);
            x = arr[i];
            masks[i] = 0;
            while(x)
            {
                masks[i] |= 1<<(x%10);
                x/=10;
            }
        }
        for(int i = 0;i<=n;i++)
            for(int j = 0;j<1024;j++)
                dp[i][j] = make_pair(-1, -1);
        for(int j = 0;j<1024;j++)
            dp[n][j] = make_pair(0, 0);
        printf("%d\n", getans(0, 0).second);
    }
}
