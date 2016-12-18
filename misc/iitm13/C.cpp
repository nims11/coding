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
    in_T
    {
        int n;
        in_I(n);
        int arr[n];
        for(int i=0;i<n;i++)
            in_I(arr[i]);
        int ans = 0;
        if(n==1)
            ans=0;
        else
        {
            ans+= arr[1]<arr[0];
            ans += arr[n-1]<arr[n-2];
            for(int i=1;i<n-1;i++)
                ans+= (arr[i+1]<arr[i] || arr[i]<arr[i-1]);
        }
        cout<<ans<<endl;
    }
}
