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
    long long a, b;
    in_L(a);
    in_L(b);
    long long a2 = (a*(a+1))/2;
    a2 %= a;
    long long a3 = 1;
    for(int i = 0;i<b;i++)
        a3 = (a3*a2)%a;
    cout<<a3<<endl;
}
