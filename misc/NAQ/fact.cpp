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
char str[1000100];
int main(){
    in_S(str);
    int l = strlen(str);
    if(l < 4){
        int x = atoi(str);
        int y = 1;
        for(int i = 1;i<=7;i++){
            y *= i;
            if(y == x){
                printf("%d\n", i);
                return 0;
            }
        }
    }else{
        double dig = 0;
        int i;
        for(i = 1;ceil(dig)<l;i++){
            dig += log10(i);
        }
        printf("%d\n", i-1);
    }
}
