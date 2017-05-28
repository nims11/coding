#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;

int arr[100010];
pair<int, int> queries[100010];
int ans[100010];
int main(){
    in_T{
        int N, Q;
        in_I(N);
        in_I(Q);
        for(int i = 0;i<N;i++){
            in_I(arr[i]);
        }
        sort(arr, arr+N, std::greater<int>());
        for(int i = 0;i<Q;i++){
            in_I(queries[i].first);
            queries[i].second = i;
        }
        sort(queries, queries+Q, std::greater<pair<int, int>>());
        int kings_idx = -1;
        int eaten_idx = 0;
        int consumed = 0;
        for(int q = 0;q<Q;q++){
            while(kings_idx + 1 < N && arr[kings_idx + 1] >= queries[q].first){
                kings_idx++;
                if(q != 0 && eaten_idx > kings_idx){
                    consumed -= queries[q-1].first - arr[kings_idx];
                }
            }
            eaten_idx = max(eaten_idx, kings_idx + 1);
            if(q != 0)
                consumed -= (eaten_idx - kings_idx - 1) * (queries[q-1].first - queries[q].first);
            while(eaten_idx < N){
                int needed = queries[q].first - arr[eaten_idx];
                if(N - eaten_idx - 1 >= consumed + needed){
                    consumed += needed;
                    eaten_idx++;
                }
                else
                    break;
            }
            ans[queries[q].second] = eaten_idx;
        }
        for(int i = 0;i<Q;i++)
            printf("%d\n", ans[i]);
    }
}
