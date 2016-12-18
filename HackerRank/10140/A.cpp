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
    int foo[26];
    for(int i = 0;i<26;i++)
        in_I(foo[i]);
    char str[100];
    in_S(str);
    int h = 0;
    int i;
    for(i = 0;str[i];i++){
        h = max(h, foo[str[i]-'a']);
    }
    printf("%d\n", i*h);
}
