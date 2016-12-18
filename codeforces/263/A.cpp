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
    long long arr[n+1];
    arr[0] = 0;
    for(int i = 1;i<=n;i++)
        in_L(arr[i]);
    sort(arr, arr+n+1);
    for(int i = 1;i<=n;i++)
        arr[i] += arr[i-1];
    long long res = arr[n]-arr[n-1];
    for(int i = 1;i<n;i++){
        res += (arr[n]-arr[i-1]) + (arr[i]-arr[i-1]);
    }
    cout<<res<<endl;
}
