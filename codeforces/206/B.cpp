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
int n, k;
int arr[300000];
int sie[1000001];
int solve(int x)
{
    int cur = 0;
    while(cur < n)
    {
        if(arr[cur]%x <= k)
        {
            cur = upper_bound(arr+cur+1, arr+n, (arr[cur]/x)*x+k)-arr;
        }else
            return false;
    }
    return true;
}
int main()
{
    in_I(n);in_I(k);
    for(int i = 0; i<n; i++)
        in_I(arr[i]);
    sort(arr, arr+n);
    int ans = 1;
    for(int i = 2; i<=arr[0]; i++)
    {
        if(sie[i] == 0)
        {
            if(solve(i))
            {
                ans = i;
            }else
            {
                for(int j = i; j<=arr[0]; j+=i)
                {
                    sie[j] = 1;
                }
            }
        }
    }
    cout<<ans<<endl;
}
