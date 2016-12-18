/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<stack>
#include<set>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int main()
{
    int n;
    in_I(n);
    int arr[n];
    for(int i = 0;i<n;i++)
        in_I(arr[i]);
    if(n == 1){
        cout<<1<<endl;
        return 0;
    }
    bool poss[n];
    for(int i = 0 ;i<n;i++)
        poss[i] = 0;
    poss[0] = true;
    poss[n-1] = true;
    for(int i = 1;i<n-1;i++){
        if(arr[i+1]> arr[i-1] && arr[i+1]-arr[i-1] > 1)
            poss[i] = true;
    }
    int longest[n], revLongest[n];
    longest[0] = 1;
    revLongest[n-1] = 1;
    for(int i = 1;i<n;i++){
        if(arr[i]>arr[i-1])
            longest[i] = longest[i-1]+1;
        else
            longest[i] = 1;
    }
    for(int i = n-2;i>=0;i--){
        if(arr[i]<arr[i+1])
            revLongest[i] = revLongest[i+1]+1;
        else
            revLongest[i] = 1;
    }
    int ans = max(revLongest[1]+1, longest[n-2]+1);
    for(int i = 1;i<n-1;i++){
        if(poss[i]){
            ans = max(ans, 1+longest[i-1]+revLongest[i+1]);
        }else{
            ans = max(ans, max(1+longest[i-1], 1+revLongest[i+1]));
        }
    }
    for(int i = 0;i<n;i++)
        ans = max(ans, longest[i]);
    cout<<ans<<endl;
}
