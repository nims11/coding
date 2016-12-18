/*
    Nimesh Ghelani (nims11)
    find the smallest number of rectangular tiles needed to form the smallest possible square.

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
long long GCD(long long a,long long b)
{
	while(b>0)
	{
	   long long temp=a;
	   a=b;
	   b=temp%b;
	}
      return a;
}
int main()
{
    long long a,b;
    while(1)
    {
        in_L(a);in_L(b);
        if(a==0)
        return 0;
        long long ans;
        if(a==b)ans=1;
        else if(a%b==0) ans=a/b;
        else if(b%a==0) ans=b/a;
        else
        ans=(a*b)/GCD(a,b);
        printf("%lld\n",ans);
    }
}
