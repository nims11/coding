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
    int n, k;
    in_I(n);
    in_I(k);
    vector<int> arr;
    bool flag = false;
    for(int i = 0;i<n;i++){
        int x;
        in_I(x);
        if(x < 0)
            flag = true;
        if(flag)
            arr.push_back(x>=0?1:-1);
        if(x<0)
            k--;
    }
    if(k < 0){
        printf("-1\n");
        return 0;
    }
    int ans = 0;
    vector<int> mid;
    int tmp = 0;
    for(int i = 0;i<arr.size();){
        if(i == 0 || arr[i-1] == 1)
            ans++;
        int j = i+1;
        for(;j<arr.size() && arr[j] >= 0;j++);
        if(j == arr.size()){
            tmp = j-i-1;
            ans+=(tmp>0);
            break;
        }
        if(j-i-1 > 0){
            ans++;
            mid.push_back(j-i-1);
        }
        i = j;
    }
    sort(mid.begin(), mid.end());
    for(int x: mid){
        if(k - x < 0)break;
        k -= x;
        ans -= 2;
    }
    if(tmp != 0 && k >= tmp)
        ans--;
    printf("%d\n", ans);
}
