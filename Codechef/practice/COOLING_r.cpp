
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main()
{
	int c=0,i,pos=0,t,n,a[101],b[101],p,r,j,g;
	scanf("%d",&t);
	for(g=1;g<=t;g++)
	{
		c=0;
		scanf("%d",&n);
		for(p=0;p<n;p++)
		{
			scanf("%d",&a[p]);
		}
		for(r=0;r<n;r++)
		{
			scanf("%d",&b[r]);
		}
		sort(a,a+n);
		sort(b,b+n);
		for(i=0;i<n;i++)
		{
			for(j=pos;j<n;j++)
			{
				if(a[i]<=b[j])
				{
					c++;
					pos=j;
					break;
				}
			}}
		printf("%d\n",c);
	}
	 
	return 0;
}

