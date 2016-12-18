
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
	int n;
	int a[3]={1,1,1},b[3];
	int *prev = a;
	int *curr = b;
	int *tmp;
	int curr_n = 2;
	in_I(n);
	while(curr_n <= n)
	{
		curr[0] = prev[0] + prev[1];
		curr[1] = prev[0] + prev[1] + prev[2];
		curr[2] = prev[1] + prev[2];
		tmp = curr;
		curr = prev;
		prev = tmp;
		curr_n++;
	}
	printf("%d\n",prev[0]+prev[1]+prev[2]);
}
