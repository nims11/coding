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
const long long mod = 1000000007;
#define MUL(a, b) (((a)*1LL*(b))%mod)
#define ADD(a, b) ((a+0LL+b)%mod)
long long POW(long long r, long long n){
    int ans = 1;
    while(n>0){
    if(n&1) ans = MUL(ans, r);
    n >>= 1;
    r = MUL(r, r);
    }
    return ans;
}
long long n, m;
int s1[100010];
int s2[100010];
long long powers[1000010];
pair<long long, long long> mult(pair<long long, long long> a, pair<long long, long long> b){
    return {MUL(a.first, b.first), a.second + b.second};
}
pair<long long, long long> summ(pair<long long, long long> a, pair<long long, long long> b){
    long long den = max(a.second, b.second);
    a.first = MUL(a.first, powers[den-a.second]);
    b.first = MUL(b.first, powers[den-b.second]);
    return {ADD(a.first, b.first), den};
}
pair<long long, long long> getans(int idx){
    if(idx == n)
        return {0,0};
    if(s1[idx] > 0 && s2[idx] > 0){
        if(s1[idx] > s2[idx])
            return {1,0};
        if(s1[idx] < s2[idx])
            return {0,0};
        return getans(idx+1);
    }
    if(s1[idx] == 0 && s2[idx] == 0){
        //eq
        pair<long long, long long> p_s = mult({1,1}, getans(idx+1));

        //w
        pair<long long, long long> p_w = {(m*(m-1)/2)%mod, 2};

        return summ(p_s, p_w);
    }else if(s1[idx] == 0){
        //eq
        pair<long long, long long> p_s = mult({1,1}, getans(idx+1));

        //w
        pair<long long, long long> p_w = {(m-s2[idx])%mod, 1};

        return summ(p_s, p_w);
    }else{
        //eq
        pair<long long, long long> p_s = mult({1,1}, getans(idx+1));

        //w
        pair<long long, long long> p_w = {(s1[idx]-1)%mod, 1};

        return summ(p_s, p_w);
    }
}
int main(){
    in_L(n);
    in_L(m);
    powers[0] = 1;
    for(int i = 1; i <= 1000010;i++){
        powers[i] = MUL(powers[i-1], m);
    }
    for(int i = 0; i < n; i++)
        in_I(s1[i]);
    for(int i = 0; i < n; i++)
        in_I(s2[i]);
    auto ans = getans(0);
    auto S = POW(POW(m, ans.second), (mod-2));
    cout<<MUL(ans.first, S)<<endl;
}
