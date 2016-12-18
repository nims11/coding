#include <bits/stdc++.h>
#define in_T int T;for(scanf("%d",&T);T--;)
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
int arr[200010];
long long sum[200010];
int n;
inline long long query(int i, int j){
    if(i > j)
        return query(1, n+1) - query(j, i);
    return sum[j-1] - sum[i-1];
}
inline bool contains(int i, int j, int k){
    if(i > j)
        return !contains(j, i, k);
    return i < k && k < j;
}
int s, t;
long long bestFarmingPath[2][200010];
int main(){
    in_T{
        in_I(n);
        for(int i = 1;i<=n;i++)
            in_I(arr[i]);
        for(int i = 1;i<=n;i++)
            sum[i] = sum[i-1] + arr[i];
        in_I(s);
        in_I(t);

        int r = s, l = s;
        for(int i = 1;;i++){
            r+=1;
            if(r > n)r = 1;
            l-=1;
            if(l < 1)l = n;
            if(i == n){
                bestFarmingPath[0][i] = min(bestFarmingPath[0][i-1], query(1, n+1)*2);
                bestFarmingPath[1][i] = min(bestFarmingPath[1][i-1], query(1, n+1)*2);
                break;
            }
            bestFarmingPath[0][i] = min(bestFarmingPath[0][i-1], query(s, r)*2);
            bestFarmingPath[1][i] = min(bestFarmingPath[1][i-1], query(l, s)*2);
        }

        long long ans = 1e18;
        // // direct
        // ans = min(query(s, t), query(t, s));
        // // double rotate
        // ans = min(ans, ans + query(1, n+1));
        if(s == t){
            ans = min(ans, 2*query(1, n+1));
        }
        // change direction
        for(int i = 1;i<=n;i++){
            if(i == s)continue;
            int diff_l, diff_r;
            diff_r = abs(i-s);
            diff_l = n - diff_r;
            if(i < s)
                swap(diff_l, diff_r);
            if(t == s){
                ans = min(ans, bestFarmingPath[0][diff_r] + bestFarmingPath[1][diff_l]);
                continue;
            }
            long long cur = 0;
            if(i == t){
                cur = min(query(s, i) + bestFarmingPath[1][diff_l],
                        query(i, s) + bestFarmingPath[0][diff_r]);
            }else
            if(contains(s, i, t)){
                cur = bestFarmingPath[1][diff_l] + query(s, i) + query(t, i);
            }else{
                cur = bestFarmingPath[0][diff_r] + query(i, s) + query(i, t);
            }
            ans = min(ans, cur);

        }
        printf("%lld\n", ans);
    }
}
