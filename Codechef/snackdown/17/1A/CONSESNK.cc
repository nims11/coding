#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;

long long arr[100010];
int main(){
    in_T{
        long long N, L, A, B;
        in_L(N);
        in_L(L);
        in_L(A);
        in_L(B);
        for(int i = 0;i<N;i++){
            in_L(arr[i]);
        }
        sort(arr, arr + N);
        long long cur = A;
        priority_queue<long long> diff;
        long long ans = 0;
        for(int i = 0;i<N;i++){
            if(arr[i] > cur + L * 1LL * i){
                diff.push(-(arr[i] - (cur + L * 1LL * i)));
            }
            ans += abs(arr[i] - (cur + L *1LL* i));
        }
        long long prev_ans = ans;
        while(diff.size() > 0){
            long long next_delta = (-diff.top()) - (cur - A);
            long long max_delta = B - (cur + N * L);
            bool exit_ = false;
            if(max_delta < next_delta){
                next_delta = max_delta;
                exit_ = true;
            }

            cur += next_delta;
            prev_ans += next_delta * (N - diff.size());
            prev_ans -= next_delta * (diff.size());
            diff.pop();
            if(cur + L * 1LL * N <= B)
                ans = min(ans, prev_ans);
            else
                break;
            if(exit_)
                break;
        }
        printf("%lld\n", ans);
    }
}
