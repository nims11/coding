#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)

int main(){
    int z = 0;
    in_T{
        int N, A, B;
        in_I(N);in_I(A);in_I(B);
        long long tot = 0;
        double foo = 0;
        vector<long long> C;
        for(int i = 0;i<N;i++){
            int x;
            in_I(x);
            C.push_back(x);
            tot += x;
        }
        for(int i = 1;i<C.size();i++)
            C[i] += C[i-1];
        int cur = 0;
        double res = 0;
        int xx = A;
        while(A<B){
            long long x = A % tot;
            int idx = lower_bound(C.begin(), C.end(), x) - C.begin();
            res += 0.5 + ((idx==0?x:(x-C[idx-1])));
            A++;
        }
        printf("Case #%d: %.9Lf\n", ++z, res/double(B-xx));
        continue;
        long long prev = 0;
#define DEBUG(a) cout<<#a<<" = "<<a<<endl;
        long long left_seg_begin = A % tot;
        long long right_seg_end = B % tot;
        // DEBUG(left_seg_begin);
        // DEBUG(right_seg_end);
        long long mid_seg_size = (B-A+1) - (tot-left_seg_begin) - (right_seg_end+1);
        assert(mid_seg_size%tot == 0);
        mid_seg_size /= tot;
        for(long long c:C){

            //left
            {
                long long l1 = max(left_seg_begin, prev);
                long long l2 = c;
                if(l2 > l1){
                    double cur_ans = (l2-l1)*(l1+l2)/2.0 - (l2-l1)*prev;
                    foo += cur_ans;
                }
            }
            // DEBUG(foo);
            //right
            {
                long long l1 = prev;
                long long l2 = min(right_seg_end, c);
                if(l2 > l1){
                    double cur_ans = (l2-l1)*(l1+l2)/2.0 - (l2-l1)*prev;
                    foo += cur_ans;
                }
            }
            // DEBUG(foo);
            //mid
            {
                long long l1 = prev;
                long long l2 = c;
                if(l2 > l1){
                    double cur_ans = (l2-l1)*(l1+l2)/2.0 - (l2-l1)*prev;
                    foo += cur_ans*mid_seg_size;
                }
            }
            // DEBUG(foo);
            prev = c;
        }
        // DEBUG(foo);
        printf("Case #%d: %.9lf\n", ++z, foo/double(B-A));
    }
}
