
/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
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
long long mod = 1000000007;
long long pow(long long r2,long long n)
{
    long long ans=1;
    while(n>0)
    {
        if((n&1)>0)
        ans=(ans*r2)%mod;
        n>>=1;
        r2=(r2*r2)%mod;
    }
    return ans%mod;
}
int main()
{
	in_T
	{
		int n;
		in_I(n);
		long long a = pow(2,(n+1)/2);
		if(a==0) a=mod;
		a--;
		a = (a*2)%mod;
		if(n%2 == 0)
			a = (a+pow(2,n/2))%mod;
		cout<<a<<endl;
	}
}
