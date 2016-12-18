
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
int main()
{
	in_T
	{
		int n;
		in_I(n);
		int arr1[100],arr2[100];
		for(int i=0;i<n;i++)
			in_I(arr1[i]);
		for(int i=0;i<n;i++)
			in_I(arr2[i]);
		sort(arr1,arr1+n);
		sort(arr2,arr2+n);
		int i=0,j=0,count=0;
		while(i<n && j<n)
		{
			if(arr1[i]<=arr2[j])
			{
				count++;
				i++;j++;
			}else j++;
		}
		cout<<count<<endl;
	}

}
