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
        long long ans = 1e18;
        while(cur + L * N <= B){
            long long cur_ans = 0;
            for(int i = 0;i<N;i++){
                cur_ans += abs(arr[i] - (cur + L * i));
            }
            ans = min(ans, cur_ans);
            cur ++;
        }
        cout<<ans<<endl;
    }
}
