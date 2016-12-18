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
int main()
{
    int n = 2;
    int curidx = 0;
    int curwt = 1000;
    int minuswt = -1000000000;
    cout<<(3 + 2*(n-1))<<endl;
    cout<<n*3<<endl;
    for(int i = 0;i<n;i++){
        cout<<curidx<<" "<<curidx+1<<" "<<curwt<<endl;
        cout<<curidx<<" "<<curidx+2<<" "<<1<<endl;
        cout<<curidx+1<<" "<<curidx+2<<" "<<minuswt<<endl;
        curidx += 2;
        curwt -= 2;
        minuswt /= 2;
    }
}
