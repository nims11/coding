
/*
    Nimesh Ghelani (nims11)
    Derive the formula by first calculating the total number of marbles for each pentagon and then excluding the common ones.
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
	int n;
	while(1)
	{
		in_I(n);
		if(n==0)return 0;
		printf("%d\n",5*((n*(n+1))/2) - (n*n-1));
	}
}
