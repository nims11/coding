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
char str[5001];
int pref_sum[5001];
int pref_sum_min[5001];
int main(){
    in_S(str);
    int l = strlen(str);
    for(int i = 0;i<l;i++){
        pref_sum[i+1] = pref_sum[i] + (str[i] == '('?1:-1);
    }
    pref_sum_min[l] = pref_sum[l];
    for(int i = l-1;i>=0;i--){
        pref_sum_min[i] = min(pref_sum[i], pref_sum_min[i+1]);
    }

    for(int i = 0;i<l;i++){
        int pref2 = pref_sum[i];
        for(int j = i;j<l;j++){
            pref2 += (str[j] == ')'?1:-1);
            if(pref2 < 0)break;
            int sum = pref_sum[l] - pref_sum[j+1];
            int min_sum = (j+2<=l?pref_sum_min[j+2] - pref_sum[j+1]:0);
            if(pref2+sum == 0 && -min_sum <= pref2){
                printf("possible\n");
                return 0;
            }
        }
        if(pref_sum[i+1] < 0)
            break;
        if(i == l-1 && pref_sum[i+1] == 0){
            printf("possible\n");
            return 0;
        }
    }
    printf("impossible\n");
}
