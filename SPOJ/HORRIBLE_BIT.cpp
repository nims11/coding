
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
int N,C,l,p,q,v;
long long BIT[500000];
long long query(int idx)
{
	long long ans=0;
	while(idx>0)
	{
		ans+=BIT[idx];
		idx-=(idx & -idx);
	}
	return ans;
}
void update(int p,int q,int v)
{
	int idx=p;
	long long x,lower;
	int k;
	while(idx<=N)
	{
		x=0;
		k = (idx & -idx);
		lower=idx-(idx & -idx)+1;
		if(p<lower)
		{
			if(q>=lower){
			if(q>idx)
				x = v*(idx-lower+1);
			else
				x = v*(q-lower+1);
			}else
				x = v*(q-p+1);
		}else
		{
			if(p<=idx){
			if(q>idx)
				x = v*(idx-p+1);
			else
				x = v*(q-p+1);
			}
		}
		BIT[idx] += x;
		cout<<idx<<" "<<lower<<" "<<BIT[idx]<<endl;
		idx+= k;
	}
}
int main()
{
	in_T
	{
		in_I(N);
		for(int i=0;i<=N;i++)
			BIT[i]=0;
		in_I(C);
		while(C--)
		{
			in_I(l);in_I(p);in_I(q);
			if(l==0)
			{
				in_I(v);
				update(p,q,v);
			}else
			{
				printf("%lld\n",query(q)-query(p-1));
			}
		}
	}
}
