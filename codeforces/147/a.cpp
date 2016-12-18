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
const int MAXX = 24*60;
int main()
{
    int n;
    in_I(n);
    int arr[n],a,b;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        arr[i] = a*60+b;
    }
    sort(arr,arr+n);
    int ans = 0;
    int i=0;
    while(i<n)
    {
        int cur = arr[i];
        int foo = 0;
        while(arr[i]==cur && i<n)
        {
            i++;
            foo++;
        }
        ans = max(ans,foo);
    }
    cout<<ans<<endl;
}
