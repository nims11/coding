#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

const int INF = INT_MAX;

const int mod = 1000000007;

using namespace std;

int main(){
    long long n;
    cin>>n;

    n++;
    if(n%2 == 0)
        cout<<(n/2)<<endl;
    else if(n == 1){
        cout<<0<<endl;
    }else
        cout<<n<<endl;
}
