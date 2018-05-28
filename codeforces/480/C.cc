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
int set_parent[256];
int sizes[256];
int ranks[256];
int set_find(int x){
    if(set_parent[x] != x)
        set_parent[x] = set_find(set_parent[x]);
    return set_parent[x];
}

void set_union(int s1, int s2){
    if(s2 < s1)
        set_union(s2, s1);
    else{
        set_parent[s2] = s1;
        sizes[s1] += sizes[s2];
    }
}

int main(){
    int n, k;
    in_I(n);
    in_I(k);
    for(int i = 0; i < 256; i++)
        set_parent[i] = i, sizes[i] = 1;
    for(int i = 0; i < n; i++){
        int x;
        in_I(x);
        if(set_find(x) == x){
            for(int j = 1; j < k; j++){
                if(x-j >= 0){
                    int target = set_find(x-j);
                    int source = set_find(x);
                    if(target != source ){
                        if(sizes[target] + sizes[source] <= k)
                            set_union(target, source);
                        else
                            break;
                    }
                }
            }
        }
        printf("%d ", set_find(x));
    }
}
