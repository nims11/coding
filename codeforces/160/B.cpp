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
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;k && i<n && arr[i]<0;i++)
    {
        k--;
        arr[i] = -arr[i];
    }
    int mini = 1000000;int min_i;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<mini)
            mini = arr[i], min_i = i;
    }
    if(k && k%2)
        arr[min_i] = -arr[min_i];
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        ans += arr[i];
    }
    cout<<ans<<endl;
}
