#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;

int main(){
    int z = 0;
    in_T{
        z++;
        cout<<"Case #"<<z<<": ";
        vector<int> arr;
        int n;
        in_I(n);
        for(int i = 0;i<n;i++){
            int x;
            in_I(x);
            arr.push_back(x);
        }
        sort(arr.begin(), arr.end(), greater<int>());
        int st = 0, end = arr.size()-1;
        int ans = 0;
        while(st <= end){
            int cur_weight = arr[st];
            for(;end>st && cur_weight < 50;end--, cur_weight += arr[st]){
            }
            if(cur_weight >= 50)
                ans++;
            st++;
        }
        cout<<ans<<endl;
    }
}
