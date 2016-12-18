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
char str[100010];
int main(){
    in_T{
        int k;
        in_S(str);
        in_I(k);
        vector<int> freq(26);
        int len = strlen(str);
        for(int i = 0;i<len;i++){
            freq[str[i]-'a']++;
        }
        sort(BE(freq));
        int res = 1e9;
        for(int i = 0;i<26;i++){
            int cur_res = 0;
            for(int j = 0;j<i;j++)
                cur_res += freq[j];
            for(int j = i+1;j<26;j++){
                cur_res += max(0, freq[j]-(k+freq[i]));
            }
            res = min(res, cur_res);
        }
        printf("%d\n", res);
    }
}
