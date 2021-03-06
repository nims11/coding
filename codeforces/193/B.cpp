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
    int n,k;
    cin>>n>>k;
    long long arr[n+1];
    arr[0] = 0;
    for(int i=1;i<=n;i++)
    {
        in_L(arr[i]);
        arr[i] += arr[i-1];
    }
    long long maxi[n+2];
    int b[n+2];
    for(int i=0;i<=n+1;i++)
        maxi[i] = -1;
    long long ans = 0;
    for(int i=n-k+1;i>k;i--)
    {
        if(maxi[i+1]>arr[i+k-1]-arr[i-1])
            maxi[i] = maxi[i+1], b[i] = b[i+1];
        else
            maxi[i] = arr[i+k-1]-arr[i-1], b[i] = i;
    }
    pair<int, int> res;
    for(int i=1;i<=n-2*k+1;i++)
    {
        if(ans<arr[i+k-1]-arr[i-1]+maxi[i+k])
            res = make_pair(i, b[i+k]);
        ans = max(ans, arr[i+k-1]-arr[i-1]+maxi[i+k]);
    }
    cout<<res.first<<" "<<res.second<<endl;
}
