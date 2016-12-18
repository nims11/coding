
/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<cstring>
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
		char str[150];
		scanf("%s",str);
		int a,b,c;
		a=b=c=0;
		int len=strlen(str);
		str[len-2]=0;
		int i=0;
		len-=2;
		if(str[0]=='x') a=1;
		else
		{
			while(str[i]!='*')
			{
				a=a*10 + (str[i]-'0');
				i++;
			}
		}
		while(i<len && str[i]!='+' && str[i]!='-')
			i++;
		bool sign=false;
		if(i<len)
			if(str[i]=='-')
				sign=true;
		int tmp=0;
		i++;
		if(str[i]=='x')tmp=1;
		else
		while(i<len && str[i]!='*')
		{
			tmp=tmp*10+str[i]-'0';
			i++;
		}
		if(sign)tmp=-tmp;
		if(i==len)
			c=tmp;
		else b=tmp;
		while(i<len && str[i]!='-' && str[i]!='+')
			i++;
		sign=false;
		if(i<len && str[i]=='-')
			sign=true;
		i++;
		while(i<len)
		{
			c=c*10+str[i]-'0';
			i++;
		}
		if(sign)
			c=-c;
		if(b*b-4*a*c==0)
			printf("Equal roots.\n");
		else if(b*b-4*a*c>0)
			printf("Distinct real roots.\n");
		else
			printf("Imaginary roots.\n");
	}
}
