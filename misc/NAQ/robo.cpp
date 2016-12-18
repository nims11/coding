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

long long GCD(long long a,long long b){
    while(b){
        swap(a, b);
        b %= a;
    }
    return a;
}
int main(){
    in_T{
        long long l1, a1, l2, a2, lt, at;
        in_L(l1);
        in_L(a1);
        in_L(l2);
        in_L(a2);
        in_L(lt);
        in_L(at);
        long long x=-1, y=-1;
        bool flag = false;
        for(int n1=1;n1<=10000;n1++){
            long long num = lt - l1*n1;
            long long den = l2;
            if(num*den > 0 && num % den == 0){
                long long n2 = num/den;
                if(n2 <= 0)
                    continue;
                if(a1*n1 + a2*n2 == at){
                    if(x != -1){
                        flag = true;
                        printf("?\n");
                        break;
                    }
                    x = n1, y = n2;
                }
            }
        }
        if(!flag){
            if(x != -1)
                printf("%lld %lld\n", x, y);
            else
                printf("?\n");
        }
    }
}
