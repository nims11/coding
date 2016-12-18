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
#include<climits>
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
        {
            in_I(arr[i]);
        }
        long long max_suff[n];
        max_suff[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            max_suff[i] = max((long long)arr[i], arr[i]+max_suff[i+1]);
        }
        long long ans = arr[0];
        long long curr = 2;
        for(int i=1;i<n;i++)
        {
            if(arr[i]>=0)
            {
                ans += curr*arr[i];
                curr++;
            }else
            {
                if(max_suff[i]<0)
                    curr = 2;
                ans += curr*arr[i];
                curr++;
//                foo -= arr[i];
            }
        }
        cout<<ans<<endl;
    }
}
