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
int n,k;
int arr[1001];
char str1[1001], str2[1001];
int main()
{
    in_T
    {
        in_I(n);
        in_I(k);
        in_S(str1);in_S(str2);
        long long ans = 0;
        for(int i=0;i<n-k;i++)
        {
            for(int j=i;j<=n;j++)
                arr[j] = 0;
            for(int j=i;j<n;j++)
            {
                arr[j+1] = arr[j] + (str1[j-i]!=str2[j]);
            }
            for(int j=i;j<=n;j++)
            {
                ans += int(arr+1+n-upper_bound(arr+i, arr+n+1, k+arr[j]));
//                cout<<int(arr+1+n-upper_bound(arr+i, arr+n+1, k+arr[j]))<<endl;
            }
//            cout<<endl;
        }
//        cout<<ans<<endl;
        for(int i=1;i<n-k;i++)
        {
            for(int j=i;j<=n;j++)
                arr[j] = 0;
            for(int j=i;j<n;j++)
            {
                arr[j+1] = arr[j] + (str2[j-i]!=str1[j]);
            }
            for(int j=i;j<=n;j++)
            {
                ans += int(arr+1+n-upper_bound(arr+i, arr+n+1, k+arr[j]));
            }
        }
        long long A = (n*(long long)(n+1)*(long long)(2*n+1))/6;
        ans = A-ans;
        cout<<ans<<endl;
    }
}
