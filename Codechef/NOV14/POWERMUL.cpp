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
vector<int> primes;
int sieve[31623];
long long vals[100001];
int mod;
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
pair<int, pair<int, int> > GCD(int a,int b)
{
    if(a == 0)
        return make_pair(b, make_pair(0, 1));
    else{
        pair<int, pair<int, int> > foo = GCD(b%a, a);
        return make_pair(foo.first, make_pair(foo.second.second-b/a*foo.second.first, foo.second.first));
    }
}
long long modInv(long long a, long long m){
    pair<long long, pair<long long, long long> > foo = GCD(a, m);
    return ((foo.second.first % m) + m)%m;
}

long long Pcnt[100001][32];
int main()
{
    primes.push_back(2);
    for(int i = 3;i<31623;i+=2){
        if(!sieve[i]){
            primes.push_back(i);
            for(int j = i*i;j<31623;j+=i)
                sieve[j] = 1;
        }
    }

    in_T{
        int N, M, Q;
        in_I(N);in_I(M);in_I(Q);
        mod = M;
        int lt = sqrt(M);
        int M2 = M;
        vector<int> factorsM;
        for(int i = 0;i<32;i++)
            Pcnt[1][i] = 0;

        for(int i = 0;i<primes.size() && primes[i]<=lt+1;i++){
            if(M2%primes[i] == 0)
                factorsM.push_back(primes[i]);
            while(M2%primes[i] == 0)
                M2 /= primes[i];
        }

        if(M2 > 1)
            factorsM.push_back(M2);
        vals[1] = 1;
        for(int i = 2;i<=N;i++){
            for(int j = 0;j<factorsM.size();j++)
                Pcnt[i][j] = Pcnt[i-1][j];
            vals[i] = vals[i-1];
            int i2 = i;
            for(int j = 0;j<factorsM.size();j++){
                while(i2%factorsM[j] == 0)
                    Pcnt[i][j] += i, i2/=factorsM[j];
            }
            vals[i] = (vals[i]*1LL*POW(i2, i))%M;
        }

        while(Q--){
            int r;
            in_I(r);
            long long off = 1;
            for(int i = 0;i<factorsM.size();i++){
                long long diff =Pcnt[N][i]-(Pcnt[r][i]+Pcnt[N-r][i]);
                assert(diff >= 0);
                off = (off*POW(factorsM[i], diff))%M;
            }
            long long res = vals[N];
            res = (res*modInv(vals[r], M))%M;
            res = (res*modInv(vals[N-r], M))%M;
            printf("%lld\n", (off*res)%M);
        }
    }
}
