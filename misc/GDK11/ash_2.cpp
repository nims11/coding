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
    int N;
    // for(int N = 0;N<=1000;N++){
    cin>>N;
    int res = 0;
    for(int n = 0;n<=N;n++){
    int c = 5;
    int ans = 0;
    do{
        ans += n/c;
        c*= 5;
    }while(c <= n);
    if(ans%2 == 0)
        res++;
    }
    cout<<res<<endl;
    // }
}
