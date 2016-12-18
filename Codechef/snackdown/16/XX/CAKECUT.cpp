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
int N, M;
int xors[1511][1511];
vector<unsigned long long> compressedXors[1511];
char str[1511];
int main(){
    in_I(N);in_I(M);
    long long ans = 0;
    for(int i = 0;i<=1511/64;i++)
        compressedXors[0].push_back(0);
    for(int i = 1;i<=N;i++){
        in_S(str+1);
        unsigned long long x = 0;
        for(int j = 1;j<=M;j++){
            int bit = str[j]-'0';
            xors[i][j] = bit ^ xors[i-1][j] ^ xors[i][j-1] ^ xors[i-1][j-1];
            x = (x << 1) | xors[i][j];
            if(j % 64 == 0 || j == M){
                compressedXors[i].push_back(x);
                x = 0;
            }
        }
        for(int j = 0;j<i;j++){
            int cnt_0 = 0, cnt_1 = 0;
            for(int k = 0;k<compressedXors[i].size();k++){
                cnt_1 += __builtin_popcountll(compressedXors[j][k] ^ compressedXors[i][k]);
            }
            cnt_0 = M - cnt_1;
            // cout<<cnt_0<<" "<<cnt_1<<endl;
            ans += cnt_1 * (cnt_1 - 1) / 2;
            ans += cnt_0 * (cnt_0 + 1) / 2;
        }
    }
    cout<<ans<<endl;
}
