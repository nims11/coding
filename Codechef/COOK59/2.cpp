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
long long fact[100010];
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)
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
int main()
{
    fact[0] = 1;
    for(int i = 1;i<=100009;i++)
        fact[i] = (fact[i-1]*i)%mod;
    in_T{
        int N;
        in_I(N);
        int ones = 0, rest = 0;
        map<long long, int> foo;
        long long x;
        long long deno = 1, num = 0;
        for(int i = 0;i<N;i++){
            in_L(x);
            if(x != 1 && foo.find(x) == foo.end())
                foo[x] = 0;
            if(x != 1)
            foo[x]++;
            if(x == 1)
                ones++;
            else
                rest++;
        }
        if(rest == 0){
            if(N%2 == 0)
                printf("0\n");
            else
                printf("1\n");
            continue;
        }
        for(auto it = foo.begin(); it!=foo.end(); it++){
            deno = MUL(deno, fact[it->second]);
            num = ADD(num, it->second);
        }
        long long bar = MUL(num, POW(deno, mod-2));
        long long res = 0;
        // cout<<bar<<endl;
        for(int i = 0;i<=ones;i+=2){
            int onesLeft = ones-i;
            int left = N - i - 1;
            long long poww = POW(fact[onesLeft], mod-2);
            if(onesLeft == 0)
                poww = 1;
            res = ADD(res, MUL(MUL(fact[left], bar), poww));
            // cout<<res<<endl;
        }
        printf("%lld\n", res);
    }
}
