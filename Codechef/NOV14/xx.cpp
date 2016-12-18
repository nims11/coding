#include <functional>
#include <algorithm>
#include <iostream>
#include <climits>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

typedef long long        LL;
typedef pair<int, int>   pii;
typedef pair<int, pii>   piii;
typedef vector<int>      vi;
typedef vector<pii>      vii;
typedef vector<piii>     viii;

#ifdef _WIN32
#define getchar_unlocked getchar
#endif
inline void inpint( int &n  ) {
    n=0; register int ch = getchar_unlocked(); bool sign = 0;
    while(ch < 48 || ch > 57) { if(ch == '-') sign = 1; ch = getchar_unlocked();  }
    while(ch >= 48 && ch <= 57) { n = (n << 3) + (n << 1) + ch - 48, ch = getchar_unlocked();  }
    if(sign) n = -n;

}

inline int sqr(int x){return x * x;}
inline int cube(int x){return x * x * x;}
inline LL sqrLL(LL x){return x * x;}
inline LL cubeLL(LL x){return x * x * x;}

const LL LLINF      = 9223372036854775807LL;
const LL LLINF17    = 100000000000000000LL;
const int INF       = 2147483647;
const int INF9      = 1000000000;
const int MOD       = 1000000007;
const double eps    = 1e-7;
const double PI     = acos(-1.0);

#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)

#define RESET(a,b)   memset(a,b,sizeof(a)) 
#define SYNC         ios_base::sync_with_stdio(0);
#define SIZE(a)      (int)(a.size())
#define MIN(a,b)     (a) = min((a),(b))
#define MAX(a,b)     (a) = max((a),(b))
#define ALL(a)       a.begin(),a.end()
#define RALL(a)      a.rbegin(),a.rend()
#define SIZE(a)      (int)(a.size())
#define LEN(a)       (int)(a.length())

#define fi           first
#define se           second
#define pb           push_back
#define mp           make_pair

int dr[] = {1,0,-1,0,-1,1,1,-1};
int dc[] = {0,-1,0,1,1,1,-1,-1};
int t, n, m, q, maxprime;
bool isprime[100005];
vi primes;
LL seg[263000], cnt[100005], ans[100005];
pii queries[100005];
int fact[100005];
int primepos[100005];
int maxprimepos;

inline void make(int node, int left, int right){
    cnt[node] = 0;
    if(left == right){
        seg[node] = 1;
        return;

    }
    int mid = (left + right) >> 1;
    make(node << 1, left, mid);
    make(node << 1 | 1, mid + 1, right);
    seg[node] = 1;

}

inline LL fastpow(LL b, LL p){
    LL ret = 1;
    for(;p;p>>=1){
        if(p&1) ret *= b;
        b *= b;
        ret %= m;
        b %= m;

    }
    return ret;

}

inline void update(int node, int left, int right, int pos, LL val){
    if(pos > right || pos < left) return;
    if(left == right){
        seg[node] = val;
        return;

    }
    int mid = (left + right) >> 1;
    update(node << 1, left, mid, pos, val);
    update(node << 1 | 1, mid + 1, right, pos, val);
    seg[node] = (seg[node<<1] * seg[node<<1|1]) % m;

}

inline void go(int remove, int add){
    pii lol = mp(remove, add);

    while(fact[remove] || fact[add]){
        int maxfact = max(fact[remove], fact[add]);

        while(fact[remove] == maxfact){
            remove /= maxfact;
            cnt[primepos[maxfact]] -= lol.fi;

        }

        while(fact[add] == maxfact){
            add /= maxfact;
            cnt[primepos[maxfact]] += lol.se;

        }

        update(1, 1, maxprimepos, primepos[maxfact], fastpow(maxfact, cnt[primepos[maxfact]]));

    }

}

int main(){
    vi primes;
    RESET(isprime,1);
    int primeiter = 0;
    isprime[0] = isprime[1] = 0;
    for(int i = 2; i <= 100000; i++){
        if(isprime[i]){
            primes.pb(i);
            primepos[i] = ++primeiter;
            fact[i] = i;
            for(int j = i + i; j <= 100000; j += i){
                isprime[j] = 0;
                fact[j] = i;

            }

        }

    }

    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&m,&q);

        REPN(i,q){
            scanf("%d",&queries[i].se);
            queries[i].fi = min(queries[i].se, n - queries[i].se);
            queries[i].se = i;

        }
        sort(queries + 1, queries + 1 + q);

        for(int i = 0; i < SIZE(primes); i++){
            if(primes[i] <= n) maxprimepos = i + 1;

        }
        make(1,0,maxprimepos);

        int front = 1;
        for(int i = 1; i + i <= n; i++){
            int add = n - i + 1;
            int rem = i;

            go(rem, add);
            while(front <= q && queries[front].fi == rem){
                ans[queries[front++].se] = seg[1];

            }

        }

        REPN(i,q){
            printf("%lld\n",ans[i]);

        }

    }

    return 0;

}
