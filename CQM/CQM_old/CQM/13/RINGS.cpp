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
    in_T
    {
        int n;
        in_I(n);
        long long arr[n];
        for(int i=0;i<n;i++)
            in_I(arr[i]);
        sort(arr, arr+n);
        int ans = 0;
        for(int i=1;i<n;i++)
        {
            if(arr[i] == arr[i-1])
            {
                if(ans == 0)
                    ans = 1;
                arr[i] += ans;
            }else if(arr[i]<arr[i-1])
            {
                if(arr[i-1]-arr[i]+1 >ans)
                {
                    ans = arr[i-1]-arr[i]+1;
                }
                arr[i] += ans;
            }
        }
        cout<<ans<<endl;
    }
}
