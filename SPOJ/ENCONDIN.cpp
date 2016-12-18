
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
	string str;
	while(getline(cin,str))
	{
		int spree_start=-1,spree_type=0;
		for(int i=0;i<str.length();i++)
		{
			if(spree_type==0)
			{
				spree_type=1;
				spree_start=i;
				continue;
			}
			if(spree_type==1)
			{
				if(str[i]!=str[i-1])continue;
				if(spree_start<i-1)
				{
					printf("1");
					for(int j=spree_start;j<i-1;j++)
						if(str[j]=='1')printf("11");else printf("%c",str[j]);
					printf("1");
				}
				spree_type=2;
				spree_start=i-1;
				continue;
			}
			if(str[i]==str[i-1] && i-spree_start<9)continue;
			printf("%d%c",i-spree_start,str[i-1]);
			spree_type=1;
			spree_start=i;
		}
		if(spree_type==1)
		{
			printf("1");
			for(int i=spree_start;i<str.length();i++)
				if(str[i]=='1')printf("11");
				else printf("%c",str[i]);
			printf("1");
		}else if(spree_type==2)
			printf("%d%c",str.length()-spree_start,str[spree_start]);
		newline;
	}
}
