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

int dp[100010][32];
string s, t;
int hashes_1[100010], hashes_2[100010];
const int mod = 1000000007;
const int base = 31;
#define MUL(a, b) (((a) * 1LL * (b)) % mod)
#define ADD(a, b) (((a) + 0LL + (b)) % mod)

void compute_prefix_hash(string &str, int *hashes){
    hashes[0] = 0;
    for(int i = 0; i < str.size(); i++){
        hashes[i+1] = ADD(MUL(hashes[i], base), str[i] - 'a' + 1);
    }
}
int power[100010];
int get_substr_hash(int *prefix_hashes, int st, int end){
    int len = end - st + 1;
    int result = prefix_hashes[end+1] - MUL(prefix_hashes[st], power[len]);
    result %= mod;
    if(result < 0)
        result += mod;
    return result;
}

int get_lcp(int s_i, int t_i){
    int st = 0, end = min(s.length() - s_i, t.length() - t_i);
    while(st < end){
        int mid = (st + end + 1) / 2;
        if(get_substr_hash(hashes_1, s_i, s_i + mid - 1) == get_substr_hash(hashes_2, t_i, t_i + mid - 1)){
            st = mid;
        }else
            end = mid-1;
    }
    return st;
}

int main(){
    power[0] = 1;
    for(int i = 1;i<=100002;i++)
        power[i] = MUL(power[i-1], base);
    int n, m, x;
    cin>>n>>s>>m>>t>>x;
    compute_prefix_hash(s, hashes_1);
    compute_prefix_hash(t, hashes_2);

    for(int i = 0;i<=n;i++)
        for(int j = 0;j<=x;j++)
            dp[i][j] = -1;
    dp[0][0] = 0;
    string ans = "NO";
    for(int i = 0;i <n;i++){
        for(int j = 0; j <=x; j++){
            if(dp[i][j] == -1)
                continue;
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(j+1 <= x){
                int lcp = get_lcp(i, dp[i][j]);
                if(lcp > 0){
                    dp[i+lcp][j+1] = max(dp[i][j] + lcp, dp[i+lcp][j+1]);
                    if(dp[i][j] + lcp == t.length())
                        ans = "YES";
                }
            }
        }
    }
    cout<<ans<<endl;
}
