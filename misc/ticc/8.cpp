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
int mod = 1000000007;
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
long long fact[100], inv[100];
bool valid(int N, int R, int S){
    if(R < N && S < N)
        return false;
    if(abs(R-S) <= 1)
        return false;
    if(max(R, S) > N && abs(R-S)>2)
        return false;
    return true;
}
inline int mul(long long a, long long b){
    return (a*b)%mod;
}
int main()
{
    fact[0] = 1;
    for(int i = 1;i<100;i++)
        fact[i] = (fact[i-1]*i)%mod;
    for(int i = 0;i<100;i++)
        inv[i] = POW(fact[i], mod-2);
    int N, R, S;
    in_I(N);
    in_I(R);
    in_I(S);
    long long res = 0;
    if(!valid(N, R, S)){
        cout<<0<<endl;
        return 0;
    }
    if(max(R, S) == N)
        res = mul(fact[R+S-1], mul(inv[N-1], inv[R+S-N]));
    else{
        res = mul(fact[2*N-2], mul(inv[N-1], inv[N-1]));
        int tar = min(R, S);
        int iter = tar - (N-1);
        res = mul(res, POW(2, iter));
    }
    cout<<res<<endl;
}
