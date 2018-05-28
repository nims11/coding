#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

const int INF = INT_MAX;

const int mod = 1000000007;
using namespace std;
vector<int> divisors[100010];
struct trie{
    struct trie* child[2] = {NULL, NULL};
    int min_val = 1000000;
}tries[100010];

void add(int trie, int n){
    int mask = 1<<30;
    struct trie *cur = &tries[trie];
    while(mask){
        bool foo = mask & n;
        cur->min_val = min(cur->min_val, n);
        if(cur->child[foo] == NULL)
            cur->child[foo] = new struct trie;
        cur = cur->child[foo];
        cur->min_val = min(cur->min_val, n);
        mask >>= 1;
    }
}

int getans(int trie, int xor_2, int less_than){
    int mask = 1<<30;
    int ans = 0;
    struct trie *cur = &tries[trie];
    while(mask){
        bool foo = mask & xor_2;
        foo = !foo;
        if(cur->child[foo] != NULL && cur->child[foo]->min_val <= less_than){
            if(foo)
                ans |= mask;
            cur = cur->child[foo];
        }else if(cur->child[!foo] != NULL && cur->child[!foo]->min_val <= less_than){
            cur = cur->child[!foo];
            if(!foo)
                ans |= mask;
        }else
            return -1;

        mask >>= 1;
    }
    return ans;
}

int main(){
    for(int k = 1; k<=100000;k++){
        for(int i = k; i <= 100000; i += k)
            divisors[i].push_back(k);
    }
    int q;
    in_I(q);
    while(q--){
        int t;
        in_I(t);
        if(t == 1){
            int u;
            in_I(u);
            for(int divisor: divisors[u])
                add(divisor, u);
        }else{
            int x, k, s;
            in_I(x); in_I(k); in_I(s);
            if(x % k){
                printf("-1\n");
            }else{
                printf("%d\n", getans(k, x, s - x));
            }
        }
    }
}
