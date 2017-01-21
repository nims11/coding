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
#define MUL(a, b) (((a)*1LL*(b))%mod)
#define ADD(a, b) (((a)+0LL+(b))%mod)
int POW(long long r, long long n){
    int ans = 1;
    while(n>0){
    if(n&1) ans = MUL(ans, r);
    n >>= 1;
    r = MUL(r, r);
    }
    return ans;
}
int fact[5000], inv[5000];
void gen_fact(){
    fact[0] = 1;
    inv[0] = POW(fact[0], mod-2);
    for(int i = 1;i<5000;i++){
    fact[i] = MUL(i, fact[i-1]);
    inv[i] = POW(fact[i], mod-2);
    }
}
inline long long getans(long long cur, int n){
    /* cout<<cur<<" "<<n<<endl; */
    return MUL(MUL(cur, inv[n]), fact[n-2]);
}
int main(){
    int z = 0;
    gen_fact();
    in_T{
        z++;
        cout<<"Case #"<<z<<": ";
        int N, M;
        in_I(N);
        in_I(M);
        if(z == 26)
            cerr<<N<<" "<<M<<endl;
        vector<int> R(N);
        int r_sum  = 0;
        for(int i = 0;i<N;i++){
            in_I(R[i]);
            r_sum += R[i];
        }
        if(z == 26)
            cerr<<r_sum<<endl;
        if(N == 1){
            cout<<M<<endl;
            continue;
        }
        long long ans = 0;
        vector<int> rems;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                if(i != j){
                    int rem = M-1;
                    rem -= 2*r_sum-R[i]-R[j];
                    if(rem >= 0){
                        /* cout<<rem<<endl; */
                        rems.push_back(rem);
                    }
                }
            }
        }
        sort(rems.begin(), rems.end());
        if(rems.size() == 0){
            cout<<0<<endl;
            continue;
        }
        long long cur = 1;
        long long cur_st = rems[0];
        for(int i = 1;i<=N;i++){
            cur = MUL(cur, rems[0]+i);
        }
        ans = ADD(ans, getans(cur, N));
        for(int i = 1;i<rems.size();i++){
            while(cur_st != rems[i]){
                cur_st += 1;
                cur = MUL(cur, POW(cur_st, mod-2));
                cur = MUL(cur, cur_st + N);
            }
            ans = ADD(ans, getans(cur, N));
        }
        cout<<ans<<endl;
    }
}
