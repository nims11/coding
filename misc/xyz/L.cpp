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
long long  f(long long n){
    if(n < 2)
        return -1;
    if(n == 2)
        return 2;
    if(n%2 == 0)return f(n/2) + n;
    return f((n/2)*3 + 2) + (n/2 + 1)*2;
}
int main(){
    int n;
    cin>>n;
    cout<<f(n)<<endl;
}
