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
    in_T{
        int n;
        in_I(n);
        int arr[n];
        for(int i = 0;i<n;i++){
            in_I(arr[i]);
        }
        sort(arr, arr+n);
        vector<int> cnt;
        int curcnt = 1;
        for(int i = 1;i<n;i++){
            if(arr[i] == arr[i-1]){
                curcnt++;
            }else{
                // cout<<arr[i]<<" "<<arr[i-1]<<endl;
                cnt.push_back(curcnt);
                curcnt = 1;
            }
        }
        cnt.push_back(curcnt);
        sort(BE(cnt));
        if(cnt.size() == 1){
            cout<<n<<endl;
        }
    }
}
