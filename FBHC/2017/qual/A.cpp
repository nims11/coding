#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;

int main(){
    int z = 0;
    in_T{
        z++;
        cout<<"Case #"<<z<<": ";
        int P, X, Y;
        in_I(P);in_I(X);in_I(Y);
        X -= 50;
        Y -= 50;
        if(X*X + Y*Y > 50*50){
            cout<<"white"<<endl;
        }else{
            swap(X, Y);
            double theta_1 = 2*acos(-1) * P/100.0;
            double theta_2 = atan2(Y, X);
            if(theta_1 > theta_2){
                cout<<"black"<<endl;
            }else
                cout<<"white"<<endl;
        }
    }
}
