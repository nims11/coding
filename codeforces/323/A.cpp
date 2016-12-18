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
int GCD(int a,int b){
    while(b){
        swap(a, b);
        b %= a;
    }
    return a;
}
int main(){
    int n;
    multiset<int> arr;
    in_I(n);
    for(int i = 0;i<n*n;i++){
        int x;
        in_I(x);
        arr.insert(-x);
    }
    vector<int> res;
    while(res.size() != n){
        int cur = -(*arr.begin());
        arr.erase(arr.begin());
        for(int i = 0;i<res.size();i++){
            int g = GCD(cur, res[i]);
            arr.erase(arr.find(-g));
            arr.erase(arr.find(-g));
        }
        res.push_back(cur);
    }
    for(int i = 0;i<res.size();i++)
        cout<<res[i]<<" ";
    cout<<endl;
}
