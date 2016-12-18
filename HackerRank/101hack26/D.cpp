/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<stack>
#include<set>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
#define MAX_STR_SIZE 100001
#define MAX_AUX 20
int ranks[200];
int LOG2[MAX_STR_SIZE];
class suffix_array{
public:
    char str[MAX_STR_SIZE];
    struct node{
        int pos, tmp1, tmp2;
        friend bool operator<(const node &a, const node &b){
            if(a.tmp1 == b.tmp1)
                return a.tmp2<b.tmp2;
            return a.tmp1<b.tmp1;
        }
    }SA[MAX_STR_SIZE];
    int lcp_arr[MAX_STR_SIZE];
    int aux_lcp[MAX_STR_SIZE][MAX_AUX];
    int aux[MAX_AUX][MAX_STR_SIZE];
    int steps, cnt, len;
    void create();
    void gen_lcp_arr();
    int lcp(int x, int y);
    int lcp_RMQ(int x, int y);
}S;
void suffix_array::create(){
    len = strlen(str);
    for(int i = 0;i<len;i++){
        aux[0][i] = ranks[str[len-i-1]];
    }
    int pre = 0;
    cnt = 1;
    for(steps = 1;pre<len;steps++, cnt<<=1){
        for(int i=0;i<len;i++){
            SA[i].pos = i;
            SA[i].tmp1 = aux[steps-1][i];
            SA[i].tmp2 = (i+cnt<len)?aux[steps-1][i+cnt]:-1;
        }
        sort(SA, SA+len);
        aux[steps][SA[0].pos] = 0;
        for(int i=1;i<len;i++){
            if(SA[i].tmp1 == SA[i-1].tmp1 && SA[i].tmp2 == SA[i-1].tmp2)
                aux[steps][SA[i].pos] = aux[steps][SA[i-1].pos];
            else
                aux[steps][SA[i].pos] = i;
        }
        pre = cnt;
    }
}
int suffix_array::lcp(int x, int y){
    int ret = 0;
    if(x == y)return len-x;
    for(int k=steps-1;k>=0 && x<len && y<len; k--)
        if(aux[k][x] == aux[k][y]) x += 1<<k, y += 1<<k, ret += 1<<k;
    return ret;
}
void suffix_array::gen_lcp_arr(){
    lcp_arr[0] = 0;
    for(int i=1;i<len;i++)
        lcp_arr[i] = lcp(SA[i-1].pos, SA[i].pos);
    // for(int i = 0;i<len;i++)
    //     cout<<lcp_arr[i]<<" ";
    //         cout<<endl;

    for(int i=0;i<len;i++)
        aux_lcp[i][0] = lcp_arr[i];

    for(int j=1; 1<<j <= len; j++)
        for(int i=0; i+(1<<j)<=len; i++)
            aux_lcp[i][j] = min(aux_lcp[i][j-1], aux_lcp[i+(1<<(j-1))][j-1]);
}
int suffix_array::lcp_RMQ(int x, int y){
    x = aux[steps-1][x];
    y = aux[steps-1][y];
    if(x>y)
        swap(x, y);
    int k = LOG2[y-x];
    return min(aux_lcp[x+1][k], aux_lcp[y-(1<<k)+1][k]);
}
int rev[MAX_STR_SIZE];
long long dp[MAX_STR_SIZE];
int bar[MAX_STR_SIZE];
int main(){
    int cnt = 0;
    for(char ch = 'a';ch<='z';ch++)
        ranks[ch] = cnt++;
    int x = 0;
    for(int i=0;i<MAX_STR_SIZE;i++){
        if(1<<x <= i)
            x++;
        LOG2[i] = x-1;
    }
    in_S(S.str);
    S.create();
    S.gen_lcp_arr();
    for(int i = 0;i<S.len;i++)
        rev[S.SA[i].pos] = i;
    // for(int i = 0;i<S.len;i++)
    //     cout<<rev[i]<<" ";
    // cout<<endl;
    int len = S.len;
    int prevBar = -1;
    for(int i = 0;i<S.len;i++){
        int maxSize = max(S.lcp_arr[rev[len-i-1]], (rev[len-i-1] != S.len-1?S.lcp_arr[rev[len-i-1]+1]:-1));
        // cout<<maxSize<<endl;
        if(i == 0){
            if(maxSize == 0)
                dp[i] = 1, prevBar = 0;
            else
                dp[i] = 0, prevBar = -1;
            bar[i] = prevBar;
        }else{
            int newBar = i-maxSize;
            bar[i] = newBar;
            dp[i] = dp[i-1] + newBar + 1;
            // dp[i] += max(0, newBar - prevBar);
            prevBar = newBar;
        }
        // cout<<bar[i]<<" ";
    }
    // cout<<endl;
    // for(int i = 0;i<S.len;i++)
    //     cout<<dp[i]<<" ";
    // cout<<endl;
    int Q;
    in_I(Q);
    while(Q--){
        int L, R;
        in_I(L);in_I(R);
        L--, R--;
        int x = lower_bound(bar, bar+R+1, L) - bar;
        if(x > R)
            printf("0\n");
        else{
            long long res = dp[R] - (x==0?0:dp[x-1]);
            // cout<<res<<endl;
            res -= max(0LL, (L)*1LL*(R-x+1));
            printf("%lld\n", res);
        }
    }
}
