/*
    Nimesh Ghelani (nims11)
*/
#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
int dp[401][51][401];
int dp2[401][51];
int arr[401], pre[401];
int main()
{
    int n, k;
    cin>>n>>k;
    for(int i = 1;i<=n;i++)
        cin>>arr[i];
    for(int i = 1;i<=n;i++)
        pre[i] = pre[i-1] + arr[i];
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=k;j++){
            for(int k = 1;k<=i;k++){
                dp[i][j][k] = dp2[i-k][j-1] + pre[i]-pre[i-k];
            }
        }
    }
}
