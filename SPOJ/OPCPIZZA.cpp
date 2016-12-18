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
int n,m,arr[100000];
int main()
{
    in_T
    {
        in_I(n);
        in_I(m);
        pair<int*, int*> foo;
        for(int i=0;i<n;i++)
        {
            in_I(arr[i]);
        }
        sort(arr, arr+n);
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            foo = equal_range(arr+i+1, arr+n, m-arr[i]);
            ans+=foo.second-foo.first;
//            cout<<ans<<endl;
        }
        printf("%lld\n", ans);
    }
}
