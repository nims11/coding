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
int arr[100000];
int dp[100000];
void dfs(int idx){
    if(!dp[arr[idx]]){
        dp[arr[idx]] = 1;
        dfs(arr[idx]);
    }
}
int main()
{
    int n, t;
    in_I(n);in_I(t);
    for(int i = 1;i<=n-1;i++){
        in_I(arr[i]);
        arr[i]+=i;
    }
    dp[1] = 1;
    dfs(1);
    printf(dp[t]?"YES\n":"NO\n");
}
