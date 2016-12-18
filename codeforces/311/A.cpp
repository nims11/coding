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
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)
int main()
{
    int n;
    cin>>n;
    int min1, min2, min3, max1, max2, max3;
    cin>>min1>>max1>>min2>>max2>>min3>>max3;
    int x1, x2, x3;
    x3 = min3, x2 = min2;
    x1 = min(max1, n-x3-x2);
    if(x1 + x2 + x3 < n){
        int tot = n - x1;
        x3 = min3;
        x2 = min(max2, tot-x3);
        if(x2 + x3 < tot){
            x3 = tot - x2;
        }
    }
    cout<<x1<<" "<<x2<<" "<<x3<<endl;
}
