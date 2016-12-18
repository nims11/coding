/*
    Nimesh Ghelani (nims11)
    GREEDY
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
int arr[10000];
int main()
{
    in_T
    {
        int a,b,c,n;
        in_I(n);
        in_I(a);in_I(b);in_I(c);
        for(int i=0;i<n;i++)
        {
            arr[i] = (a*(i+1)+b)%c;
        }
        sort(arr, arr+n);
        int res = arr[0];
        for(int i=n-1;i>0;i--)
        {
            if((n-1-i)%2 == 0)
            {
                res += arr[i];
            }else
                res -= arr[i];
        }
        printf("%d\n", res<0?-res:res);
    }
}
