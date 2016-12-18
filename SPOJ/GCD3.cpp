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
char str[411], str2[411];
int k;
int main(){
in_T{
    in_S(str);
    in_S(str2);
    in_I(k);
    int len = strlen(str);
    if((str[len-1] - '0') % 2){
        printf("1\n");
    }else{
        for(int i = 0;i<k;i++){
            int carry = 0, tmp;
            for(int j = 0;str[j];j++){
                tmp = carry*10+(str[j]-'0');
                carry = tmp&1;
                str[j] = '0' + tmp/2;
            }
            if((str[len-1] - '0') % 2 || i == k-1){
                printf("%d\n", (1<<(i+1)));
                break;
            }
        }
    }
}
}
