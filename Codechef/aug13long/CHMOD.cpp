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
int n, x, a, b, m;
int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int cnt[25][100001];
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
int main()
{
    in_I(n);
    for(int i = 1; i<=n; i++)
    {
        in_I(x);
        for(int j = 0; j<25; j++)
            while(x%primes[j] == 0)
             x /= primes[j], cnt[j][i]++;

        for(int j = 0; j<25; j++)
        {
            cnt[j][i] += cnt[j][i-1];
//            cout<<cnt[j][i]<<" ";
        }
//        newline;
    }
    in_T
    {
        scanf("%d%d%d", &a, &b, &mod);
        long long res = 1;
        for(int i = 0; i<25; i++)
        {
//            cout<<primes[i]<<" "<<cnt[i][b]-cnt[i][a-1]<<endl;
            res = (res*POW(primes[i], cnt[i][b]-cnt[i][a-1]))%mod;
        }
        printf("%lld\n", res);
    }
}
