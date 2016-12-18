/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}

using namespace std;
int fib[100];
int cnt=2;
int search_b(int n)
{
    int start=0,end=cnt-1;
    int mid;
    while(start<end)
    {
        mid=(start+end)/2;
        if(fib[mid]<n)
        {
            start=mid+1;
            continue;
        }
        if(fib[mid]>=n)
        {
            end=mid;
            continue;
        }
    }
    return end;
}
int main()
{
    int a=0,b=1;
    fib[0]=a;fib[1]=b;
    while(b<=20000000)
    {
        b+=a;
        a=b-a;
        fib[cnt++]=b;
    }
    int n,foo;
    int ans[100002];
    while(1)
    {
        in_I(n);
        if(n==0)return 0;
        for(int i=0;i<n;i++)
        {
            in_I(foo);
            int tmp=search_b(foo);
            if(fib[tmp]-foo<=foo-fib[tmp-1])
            ans[i]=fib[tmp];
            else
            ans[i]=fib[tmp-1];
        }
        sort(ans,ans+n);
        for(int i=0;i<n;i++)
        printf("%d ",ans[i]);
        printf("\n");

    }
}

