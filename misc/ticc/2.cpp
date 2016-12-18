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
int main()
{
    int n;
    in_I(n);
    int arr[n];
    long long dp[n];
    for(int i=0;i<n;i++){
        in_I(arr[i]);
    }
    dp[0] = 0;
    for(int i = 1;i<n;i++){
        dp[i] = 1e18;
        for(int j = 1;i-j>=0;j<<=1)
            dp[i] = min(dp[i], dp[i-j]+(long long)abs(arr[i]-arr[i-j]));
    }
    cout<<dp[n-1]<<endl;
}
