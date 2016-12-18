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
long long n,s,d,a,lt,k,x,j;
long long mul(long long a,long long b)
{
    long long x=0,y=a%n;
    while(b>0)
    {
        if(b%2)x=(x+y)%n;
        y=(y+y)%n;
        b>>=1;
    }
    return x%n;
}
long long pow_1(long long r2,long long n1)
{
    long long ans=1;
    while(n1>0)
    {
        if((n1&1)>0)
        ans=mul(ans,r2);
        n1>>=1;
        r2=mul(r2,r2);
    }
    return ans%n;
}
bool miller_rabin()
{
    if(n==1)return false;
    if(n==2)return true;
    if(n%2==0)return false;
    s=0;d=n-1;
    while(d%2==0)
    {
        s++;d/=2;
    }
    for(int i=0;i<20;i++)
    {
        a=rand()%(n-1)+1;
        x=pow_1(a,d);
        if(x==1 || x==n-1)continue;
        for(j=1;j<=s;j++)
        {
            x=mul(x,x);
            if(x==1)return false;
            if(x==(n-1))break;
        }
        if(j==s+1)return false;
    }
    return true;
}
int main()
{
    in_T
    {
        in_L(n);
        while(!miller_rabin())
        {
            n--;
        }
        printf("%lld\n", n);
    }
}
