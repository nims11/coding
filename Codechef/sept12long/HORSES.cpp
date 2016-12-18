/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int main()
{
    int a[5002];
    in_T
    {
        int n;
        in_I(n);
        for(int i =0;i<n;i++)
            in_I(a[i]);
        sort(a, a+n);
        int ans = 1<<30;
        for(int i=0;i<n-1;i++)
            ans = min(ans, a[i+1]-a[i]);

        cout<<ans<<endl;
    }
}
