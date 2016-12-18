/*
    Nimesh Ghelani (nims11)
*/
#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
int n, m;
int main()
{
    in_T{
        in_I(n);
        in_I(m);
        int x, y;
        for(int i = 0;i<m;i++){
            in_I(x);in_I(y);
        }
        if(n%2 == 0)
            cout<<"Alex"<<endl;
        else
            cout<<"Artur"<<endl;
    }
}
