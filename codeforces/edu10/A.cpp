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
    int h1, h2;
    cin>>h1>>h2;
    int a, b;
    cin>>a>>b;
    int day = 0;
    h1 += 8*a;
    if(h1 >= h2){
        cout<<0<<endl;
        return 0;
    }
    h1 -= 12*b;
    if(a <= b){
        cout<<-1<<endl;
        return 0;
    }
    while(true){
        day++;
        h1 += 12*a;
        if(h1 >= h2){
            cout<<day<<endl;
            return 0;
        }
        h1 -= 12*b;
    }
}
