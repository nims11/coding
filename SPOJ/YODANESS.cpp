
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
		int n;
int BIT[31000];
void update(int idx)
{
	while(idx<=n)
	{
		BIT[idx]++;
		idx+=(idx & -idx);
	}
}
int query(int idx)
{
	int ans=0;
	while(idx>0)
	{
		ans+=BIT[idx];
		idx -= (idx & -idx);
	}
	return ans;
}
int main()
{
	in_T
	{
		map<string,int> foo;
		in_I(n);
		char tmp[23];
		for(int i=0;i<n;i++)
		{
			in_S(tmp);
			foo[tmp]=i+1;
		}
		for(int i=0;i<=n;i++)
			BIT[i]=0;
		long long ans=0;
		for(int i=0;i<n;i++)
		{
			in_S(tmp);
			int k=foo[tmp];
			update(k);
			ans+=query(n)-query(k);
		}
		printf("%lld\n",ans);
	}
}
