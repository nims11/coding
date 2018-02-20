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
    int n;
    cin>>n;
    int ans = 0;
    for(int i  =1; i < n; i++){
        if((n-i)%i == 0)
            ans++;
    }
    cout<<ans<<endl;
}
