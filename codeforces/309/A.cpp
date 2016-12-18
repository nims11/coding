/*
    Nimesh Ghelani (nims11)
*/
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
long long fact[2000000], inv[2000000];
int POW(long long r, long long n)
{
    int ans = 1;
    while(n>0)
    {
        if(n&1)
            ans = (ans*r)%mod;
        n >>= 1;
        r = (r*r)%mod;
    }
    return ans;
}
long long C(int n, int k){
    return MUL(fact[n], MUL(inv[k], inv[n-k]));
}
int main()
{
    fact[0] = 1;
    for(int i = 1;i<2000000;i++)
        fact[i] = MUL(i, fact[i-1]);
    for(int i = 0;i<2000000;i++)
        inv[i] = POW(fact[i], mod-2);
    long long res = 1;
    int k;
    vector<int> c;
    in_I(k);
    for(int i = 0;i<k;i++){
        int x;
        in_I(x);
        c.push_back(x);
    }
    int tot = c[0];
    for(int i = 1;i<c.size();i++){
        res = MUL(res, C(tot+c[i]-1, c[i]-1));
        tot += c[i];
    }
    cout<<res<<endl;
}
