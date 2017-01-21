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
    int Z = 0;
    in_T{
        Z++;
        cout<<"Case #"<<Z<<": ";
        int h, s;
        in_I(h);
        in_I(s);
        for(int i = 0;i<s;i++){
            int x, y, z;
            scanf("%dd%d%d", &x, &y, &z);
            cout<<x<<" "<<y<<" "<<z<<endl;
        }
    }
}
