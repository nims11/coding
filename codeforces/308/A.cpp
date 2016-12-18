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
int grud[101][101];
int main()
{
    int n;
    in_I(n);
    int x1, y1, x2, y2;
    int res = 0;
    while(n--){
        in_I(x1);in_I(y1);in_I(x2);in_I(y2);
        res += (x2-x1+1)*(y2-y1+1);
    }
    cout<<res<<endl;
}
