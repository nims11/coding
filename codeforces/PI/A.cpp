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
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)
int main()
{
    int n;
    in_I(n);
    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        in_I(arr[i]);
    }
    vector<int> arr2 = arr;
    sort(BE(arr2));
    for(int i = 0;i<n;i++){
        int idx = lower_bound(BE(arr2), arr[i]) - arr2.begin();
        int res = (mod*2);
        if(idx > 0)res = min(res, abs(arr2[idx-1] - arr[i]));
        if(idx < arr.size()-1)
            res = min(res, abs(arr2[idx+1] - arr[i]));
        cout<<res<<" "<<max(abs(arr2[0] - arr[i]), abs(arr[i] - arr2[arr2.size()-1]))<<endl;
    }
}
