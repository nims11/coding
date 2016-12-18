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

int main(){
    int n;
    cin>>n;
    vector<int> foo(n);
    for(int i = 0;i<n;i++)
        cin>>foo[i];
    sort(BE(foo));
    vector<int> bar(n);
    int idx = 1;
    for(int i = n-1;i>=0;i--){ 
        if(idx >= n)
            idx = 0;
        bar[idx] = foo[i];
        idx += 2;
    }
    for(int x: bar)
        cout<<x<<" ";
    cout<<endl;
}
