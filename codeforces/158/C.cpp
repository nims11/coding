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
    int n, x;
    cin>>n>>x;
    int arr[n];
    x--;
    int mini = 2000000000, min_idx;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]<mini)
        {
            mini = arr[i];
            min_idx = i;
        }else
        if(arr[i]==mini)
        {
            int foo;
            int bar;
            if(min_idx<=x)
            {
                foo = x-min_idx;
            }else
            {
                foo = x+(n-min_idx);
            }
            if(i<=x)
            {
                bar = x-i;
            }else
            {
                bar = x+(n-i);
            }
            if(foo>bar)
            {
                min_idx = i;
            }
        }
    }
    int cycle =mini;
    int s = min_idx-1;
//    cout<<min_idx<<endl;
int cc = 0;
    do
    {
        cc++;
        s = (s+1)%n;
        arr[s]--;
    }while(s!=x);
    for(int i=0;i<n;i++)
    {
        if(i==min_idx)cout<<cycle*(long long)n+cc-1<<" ";else
        cout<<arr[i]-cycle<<" ";
    }
    newline;
}
