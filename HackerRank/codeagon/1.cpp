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
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)
#define BE(a) a.begin(), a.end()

using namespace std;
int r_lt_10[] = {1, 1, 1, 3, 3, 15, 15, 105, 105, 105, 105};
int mod = 1000000000;
int POW(long long r, long long n)
{
    if(r == 0 && n == 0)
        return 0;
    long long ans = 1;
    r %= mod;
    while(n>0)
    {
        if(n&1)
            ans = (ans*r)%mod;
        n >>= 1;
        r = (r*r)%mod;
    }
    return ans;
}

int R(int n){
    if(n <= 10)return r_lt_10[n];
    int ret = pow(2, n/4+bool(n%4));
    ret = (ret*1LL*R(n/5+bool(n%5)))%mod;
    ret = (ret*1LL*R(n/10+bool(n%10)))%mod;
    return ret;
}
long long GCD(long long a,long long b)
{
        if(b==0)return a;
        return GCD(b,a%b);
}

void solve(int n){
    int r_n = R(n);
    int maxi = 0;
    for(int i = 0;i<=5;i++)
        for(int j = 0;j<=5;j++)
            if(GCD(r_n*1LL*i, r_n*1LL*j) == r_n)
                maxi = max(maxi, POW(r_n*1LL*i, r_n*1LL*j));
    printf("%d\n", maxi);
}
int main()
{
    in_T{
        int N;
        in_I(N);
        solve(N);
    }
}
