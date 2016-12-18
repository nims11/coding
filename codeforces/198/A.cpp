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
long long GCD(long long a,long long b)
{
    while(b^=a^=b^=a%=b);
    return a;
}

int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    arr[0] = 0;
    for(int i = 1; i<=n; i++)
    {
        in_I(arr[i]);
    }
    sort(arr, arr+n+1);
    long long num = n*1LL*arr[1], den;
    for(int i = 2; i<=n; i++)
    {
        num += (arr[i]-arr[i-1])*1LL*((2*i-1)*1LL*(n+1-i));
    }
    long long x = GCD(num, n);
    cout<<num/x<<" "<<n/x<<endl;
}
