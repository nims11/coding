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
int main()
{
    int n;
    in_I(n);
    vector<int> arr;
    for(int i = 0;i<n;i++){
        int x;
        in_I(x);
        arr.push_back(x);
    }
    sort(BE(arr));
    long long res = 0;
    for(int i = arr.size()-1, j = (int)arr.size()-4;i>=0 && j>=0;){
        if(abs(arr[i-1]-arr[i]) <= 1 && abs(arr[i-2]-arr[i-3]) <= 1){
            res += arr[i-1]*1LL*arr[j];
            i -= 4, j -= 4;
        }else{
            i--, j--;
        }
    }
    cout<<res<<endl;
}
