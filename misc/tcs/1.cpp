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
long long getans(long long F, long long B, long long T, long long FD, long long BD){
    if(FD <= F) return FD;
    long long diff = F-B;
    long long steps = (FD-F)/diff + ((FD-F)%diff != 0);
    long long last_dist = steps*diff;
    steps = steps*(F+B) + (FD-last_dist);
    return steps;
}
int main(){
    in_T{
        long long F, B, T, FD, BD;
        in_L(F);
        in_L(B);
        in_L(T);
        in_L(FD);
        in_L(BD);
        long long diff = F-B;
        if(FD <= F){
            printf("%lld F\n", (FD)*T);
        }else
        if(diff < 0){
                printf("%lld B\n", (F+getans(B,F,T,BD+F,FD-F)) * T);
        }
        else if(diff == 0){
            printf("No Ditch\n");
        }else{
                printf("%lld F\n", getans(F,B,T,FD,BD) * T);
        }
    }
}
