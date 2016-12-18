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
    in_T{
        long long n, s;
        cin>>n>>s;
        int i;
        for(i = 1;i<=n;i++){
            if(s - i < n-i)
                break;
            s -= i;
        }
        printf("%lld\n", n+1-i);
    }
}
