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
    long long n;int k;long long curr;
    in_T
    {
        in_L(n);in_I(k);
        long long arr[102]={0};
        int start=1,end=45000000,mid;
        long long x;
        while(start<end)
        {
            mid=(start+end)/2;
            x=(mid*(long long)(mid+1))/2;
            if(x>n)
            end=mid-1;
            else
            start=mid+1;
        }
        if((start*(long long)(start+1))/2 > n)
        start--;
        long long comp=start/k;
        for(int i=1;i<=k;i++)
        {
            x=i*comp + ((comp * (comp-1))/2)*k;
            arr[i]=x;
            n-=x;
        }
        int comp2=start%k;
        int i;
        for(i=1;i<=comp2;i++)
        {
            x=i + k * (comp);
            arr[i]+=x;
            n-=x;
        }
        arr[i]+=n;

        for(int i=1;i<=k;i++)
        printf("%lld ",arr[i]);
        newline;
    }
}

