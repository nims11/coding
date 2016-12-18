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
inline int mul(long long a, long long b){
    return (a*b)%mod;
}
inline int add(long long a, long long b){
    return (a+b)%mod;
}
int main()
{
    int N, M;
    in_I(N);
    in_I(M);
    int limit = sqrt(M);
    long long res = 0;
    for(int i = 1;i<=limit;i++){
        res = (res + POW(M/i, N-1))%mod;
        int multi = max(M/i, limit) - max(M/(i+1), limit);
        res = add(res, mul(multi, POW(i, N-1)));
    }
    cout<<res<<endl;
}
