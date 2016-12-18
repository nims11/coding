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
bool dp1[100010][2], dp2[100010][2];
int a[100010];
int main()
{
    int n;
    in_I(n);
    for(int i = 1;i<=n;i++)
        in_I(a[i]);
    dp1[1][a[1]] = true, dp1[1][!a[1]] = false;
    dp2[1][a[n]] = true, dp2[n][!a[n]] = false;
    int zeros = (a[1] == 0);
    for(int i = 2;i<=n;i++){
        if(a[i] == 1)
            dp1[i][1] = true, dp1[i][0] = false;
        else
            dp1[i][1] = zeros, dp1[i][0] = dp1[i-1][1];
        if(a[i] == 0)
            zeros++;
    }
    for(int i = n-1;i>=1;i--){
        if(a[i] == 0)
            dp2[i][1] = true, dp2[i][0] = false;
        else
            dp2[i][1] = dp2[i+1][1], dp2[i][0] = dp2[i+1][0];
    }
    for(int i = 1;i<n;i++){
        if(dp1[i][1] && dp2[i+1][0]){
            cout<<"YES"<<endl;
        }
    }
    cout<<"NO"<<endl;
}
