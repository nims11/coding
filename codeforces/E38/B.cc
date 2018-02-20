#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

const int INF = INT_MAX;
using namespace std;

int main(){
    int n;
    in_I(n);
    int ans = 1e9;
    vector<int> arr(n);
    for(int i  =0; i < n;i++){
        in_I(arr[i]);
    }

    for(int i = 0; i < n; i++){
        int t1 = arr[i] - 1;
        int t2 = (i+1 == n?0:(1000000 - arr[i+1]));
        int t3 = (i==0?0:(arr[i-1] - 1));
        int t4 = 1000000 - arr[i];
        ans = min(ans, min(max(t1, t2), max(t3, t4)));
    }
    cout<<ans<<endl;
}
