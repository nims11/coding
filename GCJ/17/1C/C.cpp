#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;

const long double eps = 1e-9;
int N, K;
long double tmp[100];
long double dp[100][100];
long double getans(vector<long double> &P, long double U, long double target){
    long double ret = 1;
    long double U2 = 0;
    int idx = 0;
    int i;
    for(i = P.size()-1;i>=int(P.size())-K;i--){
        U2 += max((long double)0, target-P[i]);
        tmp[i] = max(target, P[i]);
    }
    if(U2 > U)
        return -100;
    U -= U2;
    for(;i>=0;i--){
        long double rem = min(1-P[i], U);
        U -= rem;
        tmp[i] = rem + P[i];
    }

    dp[0][0] = 1;
    for(int i = 1;i<=N;i++){
        for(int j = 0;j<=i;j++){
            dp[i][j] = dp[i-1][j] * (1-tmp[i-1]);
            if(j > 0)
                dp[i][j] += dp[i-1][j-1] * tmp[i-1];
        }
    }
    ret = 0;
    for(int i = K;i<=N;i++)
        ret += dp[N][i];
    return ret;
}
int main(){
    int z = 0;
    int T;
    cin>>T;
    while(T--){
        z++;
        long double U;
        cin>>N>>K>>U;
        vector<long double> P;
        long double sum = 0;
        for(int i = 0;i<N;i++){
            long double X;
            cin>>X;
            P.push_back(X);
            sum += X;
        }
        sort(BE(P));
        long double st = 0, end = 1;
        int cnt = 0;
        long double ans;
        while(st < end){
            cnt++;
            if(cnt == 100000)
                break;
            long double mid = (st + end)/2;
            long double annn = getans(P, U, mid);
            if(annn > -1){
                ans = annn;
                st = mid;
            }else end = mid;
        }
        printf("Case #%d: %.9Lf\n", z, ans);
    }
}
