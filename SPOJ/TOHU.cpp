
/*
    Nimesh Ghelani (nims11)
    find the nth term by f(n)-f(n-1)
    then, use the Vn method to find the series sum.
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
int main()
{
	in_T
	{
		double k;
		in_F(k);
		printf("%.11lf\n",0.75 - 0.5*(1/(k+1) - 1/(k+2)));
	}
}
