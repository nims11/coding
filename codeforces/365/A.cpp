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
        int N;
        in_I(N);
        int x = 0, y = 0;
        while(N--){
            int a, b;
            in_I(a);
            in_I(b);
            if(a > b)
                x++;
            else if(a < b)
                y++;
        }
        if(x == y){
            cout<<"Friendship is magic!^^"<<endl;
        }
        else if (x < y){
            cout<<"Chris"<<endl;
        }else cout<<"Mishka"<<endl;
}
