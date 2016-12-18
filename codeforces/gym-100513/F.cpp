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

int pref_max[200010];
int suff_max[200010];
int main(){
    int N, k;
    in_I(N);
    in_I(k);
    vector<int> arr(N);
    for(int i = 0;i<N;i++){
        in_I(arr[i]);
    }
    int cur_sum = 0;
    int cur_sum_suff = 0;
    for(int i = 0;i<N;i++){
        if(i >= k){
            cur_sum -= arr[i-k];
            cur_sum_suff -= arr[N-(i-k)-1];
        }
        cur_sum += arr[i];
        cur_sum_suff += arr[N-i-1];
        pref_max[i] = max(i==0?0:pref_max[i-1], cur_sum);
        suff_max[N-i-1] = max(suff_max[N-i], cur_sum_suff);
    }
    int ans = 0;
    for(int i = 0;i<N-1;i++){
        ans = max(ans, pref_max[i] + suff_max[i+1]);
    }
    cout<<ans<<endl;
}
