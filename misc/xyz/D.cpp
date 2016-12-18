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
    int n, w;
    cin>>n>>w;
    vector<int> arr(n);
    for(int i = 0;i<n;i++)
        cin>>arr[i];

    int st = 1, end = n;
    while(st < end){
        int mid = (st+end)/2;
        int wid = compute(arr, mid);
        if(wid < w)
            st = mid;
        else
            end = mid-1;
    }
}
