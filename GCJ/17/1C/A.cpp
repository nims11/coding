#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;
const double pi = acos(-1);
int main(){
    int z = 0;
    in_T{
        int N, K;
        in_I(N);
        in_I(K);
        vector<pair<long long, long long>> RH;
        for(int i = 0;i<N;i++){
            int R, H;
            in_I(R);in_I(H);
            RH.push_back({-R, H});
        }
        sort(BE(RH));
        long long ans = 0;
        for(int i = 0;i<N;i++){
            long long local_ans = RH[i].first * RH[i].first + 2 * -RH[i].first * RH[i].second;
            if(N-i >= K){
                vector<long long> tmp;
                for(int j = i+1;j<N;j++){
                    tmp.push_back(2* RH[j].first * RH[j].second);
                }
                sort(BE(tmp));
                for(int j = 0;j<K-1;j++){
                    local_ans += -tmp[j];
                }
            }
                ans = max(ans, local_ans);
        }
        printf("Case #%d: %.9lf\n", (++z),  ans * pi);
    }
}
