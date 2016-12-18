
/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<cmath>
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
long long combi(long long n)
{
	return (n*(n-1))/2;
}

int main()
{
	long long G,T,A,D;
	while(scanf("%lld %lld %lld %lld",&G,&T,&A,&D)!=-1)
	{
		if(G==-1)return 0;
		long long foo =  (long long)ceil(log2(G*A + D));
		long long Y = (long long)pow(2,foo) - D - (G*A);
		long long X = (long long)pow(2,foo) - 1;
		X += G * combi(T);
		printf("%lld*%lld/%lld+%lld=%lld+%lld\n",G,A,T,D,X,Y);
	}
}
