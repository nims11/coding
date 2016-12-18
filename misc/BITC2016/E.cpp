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

long long pts[102][2];
int main(){
    in_T{
        int N, K;
        in_I(N);
        in_I(K);
        for(int i = 0;i<N;i++){
            in_L(pts[i][0]);
            in_L(pts[i][1]);
        }
        long long ans = 1e18;
        for(int i = 0;i<N;i++){
            vector<pair<long long, int>> x;
            for(int j = 0;j<N;j++){
                x.push_back({abs(pts[i][0]-pts[j][0]) + abs(pts[i][1]-pts[j][1]),j});
            }
            sort(BE(x));
            long long center_x = 0;
            long long center_y = 0;
            for(int j = 0;j<K;j++){
                center_y += pts[x[j].second][1];
                center_x += pts[x[j].second][0];
            }
            center_y /= K;
            center_x /= K;
            long long ans2 = 0;
            for(int j = 0;j<K;j++){
                ans2 += abs(center_y-pts[x[j].second][1]) + abs(center_x-pts[x[j].second][0]);
            }
            ans = min(ans, ans2);
        }
        cout<<ans<<endl;
    }
}
