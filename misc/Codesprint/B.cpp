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
#include<cassert>
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
const int mod = 1000000007;
long long POW(long long n, long long r){
    long long res = 1;
    while(r>0){
        if(r&1)
            res = (res*n)%mod;
        r >>= 1;
        n = (n*n)%mod;
    }
    return res;
}
long long fact[1000001], inv[1000001];
long long C(int n, int r){
    if(n < 0 || n > 1000000 || r < 0 || r > 1000000)
        return 10;
    return (fact[n]*((inv[r]*inv[n-r])%mod))%mod;
}
int main()
{
    fact[0] = 1;
    for(int i = 1;i<=1000000;i++)   fact[i] = (fact[i-1]*i)%mod;
    for(int i = 0;i<=1000000;i++)   inv[i] = POW(fact[i], mod-2);
    in_T{
        int m,n;
        in_I(m);in_I(n);
        printf("%lld\n", C(m+n-2, m-1));
    }

}
