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
    in_T{
        int N;
        long long C;
        in_I(N);in_L(C);
        C *= 2;
        if(C % N != 0){
            printf("No\n");
        }else{
            C /= N;
            int N2 = N-1;
            if(N2 < C){
                if((C - N2) % 2 == 0){
                    printf("Yes\n");
                    continue;
                }
            }
            if(N2 * 2 < C){
                if((C - N2*2) % 2 == 0){
                    printf("Yes\n");
                    continue;
                }
            }
            printf("No\n");
        }
    }
}
