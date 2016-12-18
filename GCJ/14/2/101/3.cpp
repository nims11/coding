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
int arr[100001];
int main()
{
    in_T{
        int N;
        in_I(N);

        int dp[2][101] = {0};
        for(int i = 1;i<=N;i++){
            in_I(arr[i]);
        }
        arr[0] = 1;

        for(int i = 2;i<=N;i++)
        {
            int x = (i%2);
            for(int j = 1;j<=arr[i];j++)
            {
                dp[x][j] = 0;
                for(int k = 1;k<=arr[i-1];k++)
                dp[x][j] = max(dp[x][j], dp[!x][k]+abs(j-k));
            }
        }
        int ans = 0;
        for(int i = 1;i<=arr[N];i++)
            ans = max(ans, dp[N&1][i]);
        printf("%d\n", ans);
    }
}
