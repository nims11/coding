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
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;
#define P_I(a) printf("%d",a)

using namespace std;
long long unsigned getsum(int n2)
{
    long long unsigned n=9,k=1;
    for(int i=1;i<n2;i++)
    k*=10;
    n*=k;
    return n/2 * (2*k+n-1);
}
long long unsigned even(int n)
{
    long long unsigned A[12]={0};
    long long unsigned k=4,m=10;
    for(int i=1;i<n;i++)
    k*=5;
    A[0]=k/4 * 20;
    for(int i=1;i<n;i++)
    A[i]=k/5 * 20;
    for(int i=n-1;i>0;i--)
    {A[i-1]=A[i-1]*m+A[i];m*=10;}
    return A[0];
}
long long unsigned odd(int n)
{
    long long unsigned A[12]={0};
    long long unsigned k=1,m=10;
    for(int i=1;i<n;i++)
    k*=5;
    for(int i=0;i<n;i++)
    A[i]=k * 25;
    for(int i=n-1;i>0;i--)
    {
        A[i-1]=A[i-1]*m+A[i];
        m*=10;
    }
    return A[0];
}
int main()
{
    int n;
    int c=1;
    while(cin>>n)
    {
        cout<<"Case #"<<c<<": ";
        cout<<getsum(n)-odd(n)-even(n)<<endl;
        c++;
    }
}
