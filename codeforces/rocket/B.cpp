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
    long long m;
    cin>>n>>m;
    int arr[n];
    int st = 0, end = n-1;
    long long cur = 1LL<<(n-1);
    int id = 1;
    while(st <= end){
        if(m <= cur/2){
            arr[st++] = id++;
        }else{
            arr[end--] = id++;
            m -= cur/2;
        }
        cur /= 2;
    }
    for(int i = 0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    // int ans = 0;
    // for(int i = 0;i<n;i++){
    //     int curmin = 1e9;
    //     for(int j = i;j<n;j++){
    //         curmin = min(curmin, arr[j]);
    //         ans += curmin;
    //     }
    // }
    // cout<<ans<<endl;
}
