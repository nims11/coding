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

int main(){
    in_T{
        int a;
        in_I(a);
        int grid_cache[20][20] = {0};

        // key = (-remaining, x, y)
        set<pair<int, pair<int, int>>> rem;
        map<pair<int, int>, int> rev_map;
        int n = 0;
        while(n * n < a)
            n++;
        n = max(n, 9);

        // 1,1 to n,n

        for(int i = 2; i < n; i++){
            for(int j = 2; j < n; j++){
                rem.insert({-9, {i, j}});
                rev_map[{i, j}] = -9;
            }
        }

        int resp_i, resp_j;
        while(true){
            auto &next_grid = rem.begin()->second;
            printf("%d %d\n", next_grid.first, next_grid.second);
            fflush(stdout);
            scanf("%d %d", &resp_i, &resp_j);
            if(resp_i == 0 && resp_j == 0)
                break;
            if(grid_cache[resp_i][resp_j] == 0){
                grid_cache[resp_i][resp_j] = 1;
                for(int i = resp_i - 1; i <= resp_i + 1; i++){
                    for(int j = resp_j - 1; j <= resp_j + 1; j++){
                        if(i >= 2 && i < n && j >= 2 && j < n){
                            rem.erase({rev_map[{i, j}], {i, j}});
                            rev_map[{i, j}]++;
                            rem.insert({rev_map[{i, j}], {i, j}});
                        }
                    }
                }
            }
        }
    }
}
