
/*
    Nimesh Ghelani (nims11)
    2d BIT
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
int n,tree[2000][2000];
void updatey(int x,int y,int num)
{
	while(y<=n)
	{
		tree[x][y]+=num;
		y += (y & -y);
	}
}
void updatex(int x,int y,int num)
{
	while(x<=n)
	{
		updatey(x,y,num);
		x+=(x & -x);
	}
}
long long queryy(int x,int y)
{
	long long ans=0;
	while(y>0)
	{
		ans+=tree[x][y];
		y -= (y & -y);
	}
	return ans;
}
long long query(int x,int y)
{
	long long ans=0;
	while(x>0)
	{
		ans+=queryy(x,y);
		x -= (x & -x);
	}
	return ans;
}

int main()
{
	in_T
	{
		in_I(n);
		char tmps[10];
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				tree[i][j]=0;
		int grid[1200][1200]={{0}};
		while(1)
		{
			in_S(tmps);
			if(tmps[0]=='E')break;
			if(tmps[1]=='U')
			{
				int x1,y1,x2,y2;
				in_I(x1);in_I(y1);in_I(x2);in_I(y2);
				printf("%lld\n",query(x2+1,y2+1)-query(x1,y2+1)-query(x2+1,y1)+query(x1,y1));
			}else
			{
				int x,y,num;
				in_I(x);in_I(y);in_I(num);
				int k=grid[x+1][y+1];
				grid[x+1][y+1]=num;
				updatex(x+1,y+1,num-k);
			}
		}
	}
}
