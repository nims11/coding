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
    int n, m;
    cin>>n>>m;
    int res = 0;
    while(n+m >= 3 && n && m){
        if(n > m)n -= 2, m -= 1;
        else n -= 1, m -= 2;
        res++;
    }
    cout<<res<<endl;
}
