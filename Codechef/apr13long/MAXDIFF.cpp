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
int arr[1000];
int main()
{
    int n,k;
    in_T
    {
        cin>>n>>k;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum += arr[i];
        }
        int sum2 = 0, sum3 = 0;
        sort(arr, arr+n);

        for(int i=0;i<k;i++)
            sum2 += arr[i], sum3 += arr[n-i-1];
        int ans = max(max(sum2, sum-sum2) - min(sum2, sum-sum2), max(sum3, sum-sum3) - min(sum3, sum-sum3));
        printf("%d\n", ans);
    }
}
