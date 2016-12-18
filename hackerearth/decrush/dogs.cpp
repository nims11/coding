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
#define modMul(a, b) ((a*b)%mod)
using namespace std;
int dp1[1000001], dp2[1000001];
const int mod = 1000003;
inline int comb(int n, int r){
    return modMul(fact[n], modMul(inv[r], inv[n-r]));
}
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
    in_T{
        int D, C, N;
        in_I(D);
        in_I(C);in_I(N);
        int res = 0;
        for(int i = 0;i<=C+D;i++){
            long long numPow = (C+D)*N;
            long long coeff = comb(C+D, i);
            long long botReq = C*N-D - numPow;
            if(botReq >= 0){
                coeff = modMul(coeff, comb(C+D+botReq-1, botReq));
                res = (res+coeff)%mod;
            }
        }
        printf("%d\n", res);
    }
}
