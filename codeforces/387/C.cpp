#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;
vector<int> evts[2000010];
int busy[101];
int main(){
    int n, q;
    in_I(n);in_I(q);
    int cur_t = 0;

    for(int i = 0;i<q;i++){
        int t, k, d;
        in_I(t);in_I(k);in_I(d);
        do{
            for(int x: evts[cur_t])
                busy[x] = 0;
            cur_t++;
        }while(cur_t < t);
        int ans = 0;
        vector<pair<int, int>> tmpp;
        for(int j = 0;j<n && k>0;j++){
            if(!busy[j]){
                ans += j+1;
                tmpp.push_back({j, cur_t + d - 1});
                k--;
            }
        }

        if(k){
            printf("-1\n");
        }else{
            for(pair<int, int> x: tmpp){
                busy[x.first] = 1;
                evts[x.second].push_back(x.first);
            }
            printf("%d\n", ans);
        }
    }
}
