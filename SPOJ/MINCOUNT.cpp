#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
long long unsigned foo(long long unsigned n)
{
	return (n*(n+1))/2;
}
void mins(long long unsigned a,long long unsigned b)
{
    if(a<b)printf("%llu\n",a);
    else  printf("%llu\n",b);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long unsigned n;
		scanf("%llu",&n);
		if(n==0 || n==1)printf("0\n");
		else
		{
		    long long unsigned a1=floor((n-1)/double(3));
		    long long unsigned a2=ceil((n-1)/double(3));
		    if(n==3)a1=1;
		mins(2*foo(a1)+foo(n-2*a1-1),2*foo(a2)+foo(n-2*a2-1));
		}
	}
}
