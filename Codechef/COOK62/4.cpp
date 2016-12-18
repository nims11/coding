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
bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.second > b.second;
}
long long dp[5001][5001];
long long res[5001];
int main(){
    in_T{
        int n,x,y;
        in_I(n);
        vector<pair<int, int> > ab;
        for(int i = 0;i<n;i++){
            in_I(x);
            ab.push_back(make_pair(x, 0));
        }
        for(int j = 0;j<n;j++){
            in_I(x);
            ab[j].second = x;
            res[j+1] = -1;
        }
        sort(BE(ab), cmp);
        dp[0][0] = 0;
        res[0] = 0;
        for(int i = 1;i<=n;i++){
            dp[i][0] = 0;
            for(int j = 1;j<=i;j++){
                dp[i][j] = 0;
                dp[i][j] = max(dp[i][j], res[j-1]);
                dp[i][j] += ab[i-1].first + ab[i-1].second*1LL*(j-1);
            }
            for(int j = 1;j<=i;j++)
                res[j] = max(res[j], dp[i][j]);
        }
        for(int i = 1;i<=n;i++)
            printf("%lld ", res[i]);
        newline;
    }
}
