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
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++)
       cin>>arr[i];
    for(int i=n-2;i>=0;i--)
        arr[i]+=arr[i+1];
    for(int i=0;i<n/2;i++)
    {
        int tmp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = tmp;
    }
    int ans = 0;
    int pre = 0;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
        int x = upper_bound(arr+i, arr+n, pre+m) - (arr+i);
        ans = max(ans, x);
        pre = arr[i];
    }
    cout<<ans<<endl;
}
