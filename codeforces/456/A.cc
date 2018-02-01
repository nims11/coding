#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

const int INF = INT_MAX;
using namespace std;

int main(){
    long long A, B;
    long long x, y, z;
    cin>>A>>B>>x>>y>>z;
    long long X = 0, Y = 0, Z = 0;
    X = 2 * x + y;
    Z = y + 3 *z;
    cout<<(max(0LL, X - A) + max(0LL, Z-B))<<endl;
}
