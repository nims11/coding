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
        sort(arr, arr+n);
        long long foo = 0;
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                foo+= int(lower_bound(arr+j+1, arr+n, arr[i]+arr[j])-(arr+j+1));
//                cout<<foo<<endl;
            }
        }
        printf("%.4lf\n", 6*double(foo)/((long long)n*(n-1)*(long long)(n-2)));
    }
}
