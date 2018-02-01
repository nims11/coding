#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;
int arr[100010];
long long pref[100010];
int mini_l[100010];
int mini_r[100010];
int n;
long long getans(int h, int idx){
    long long tot = pref[n];
    long long sum = h + h * (h-1);
    return tot - sum;
}
int main(){
    in_T{
        in_I(n);
        for(int i = 1;i<=n;i++){
            in_I(arr[i]);
            pref[i] = pref[i-1] + arr[i];
        }
        mini_l[0] = 0;
        mini_r[n+1] = 0;
        for(int i = 1;i<=n;i++){
            mini_l[i] = min(mini_l[i-1], arr[i] - i);
        }
        for(int i = n;i>=1;i--){
            mini_r[i] = min(mini_r[i+1], arr[i] - (n-i+1));
        }
        long long ans = 1e18;
        for(int i = 1;i<=n;i++){
            int actual_h_l = mini_l[i] + i;
            int actual_h_r = mini_r[i] + (n-i+1);
            int actual_h = min(actual_h_l, actual_h_r);
            actual_h = min(actual_h, arr[i]);
            ans = min(ans, getans(actual_h, i));
        }
        printf("%lld\n", ans);
    }
}
