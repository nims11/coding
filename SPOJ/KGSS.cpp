
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
struct foo
{
	int max1,max2;
}tmp;
foo TREE[1000000];
int arr[1000000];
void build_segment_tree(int NODE, int a, int b)
{
	if(a==b)
	{
		TREE[NODE].max1=arr[a];TREE[NODE].max2=0;

		return;
	}
	int mid=(a+b)/2;
	int LEFT=2*NODE;
	int RIGHT=LEFT+1;
	build_segment_tree(LEFT,a,mid);
	build_segment_tree(RIGHT,mid+1,b);
	if(TREE[LEFT].max1>TREE[RIGHT].max1)
	{
		TREE[NODE].max1=TREE[LEFT].max1;
		if(TREE[LEFT].max2>TREE[RIGHT].max1)
			TREE[NODE].max2=TREE[LEFT].max2;
		else
			TREE[NODE].max2=TREE[RIGHT].max1;
	}else
	{
		TREE[NODE].max1=TREE[RIGHT].max1;
		if(TREE[RIGHT].max2>TREE[LEFT].max1)
			TREE[NODE].max2=TREE[RIGHT].max2;
		else
			TREE[NODE].max2=TREE[LEFT].max1;
	}
}
void update(int NODE,int a,int b,int x)
{
	if(a==b)
	{
		TREE[NODE].max1=arr[x];
		TREE[NODE].max2=0;
		return;
	}
	int mid=(a+b)/2;
	int LEFT=2*NODE,RIGHT=2*NODE+1;
	if(x<=mid)
		update(LEFT,a,mid,x);
	else
		update(RIGHT,mid+1,b,x);
	if(TREE[LEFT].max1>TREE[RIGHT].max1)
	{
		TREE[NODE].max1=TREE[LEFT].max1;
		if(TREE[LEFT].max2>TREE[RIGHT].max1)
			TREE[NODE].max2=TREE[LEFT].max2;
		else
			TREE[NODE].max2=TREE[RIGHT].max1;
	}else
	{
		TREE[NODE].max1=TREE[RIGHT].max1;
		if(TREE[RIGHT].max2>TREE[LEFT].max1)
			TREE[NODE].max2=TREE[RIGHT].max2;
		else
			TREE[NODE].max2=TREE[LEFT].max1;
	}
}
foo query(int NODE,int a,int b,int x,int y)
{
	if(x<=a && y>=b)return TREE[NODE];
	int mid=(a+b)/2;
	if(y<=mid)return query(2*NODE,a,mid,x,y);
	if(x>mid)return query(2*NODE+1,mid+1,b,x,y);
	foo left=query(2*NODE,a,mid,x,y);
	foo right=query(2*NODE+1,mid+1,b,x,y);
	foo ans;
	if(left.max1>right.max1)
	{
		ans.max1=left.max1;
		if(left.max2>right.max1)
			ans.max2=left.max2;
		else
			ans.max2=right.max1;
	}else
	{
		ans.max1=right.max1;
		if(right.max2>left.max1)
			ans.max2=right.max2;
		else
			ans.max2=left.max1;
	}
	return ans;
}
int main()
{
	int N;
	in_I(N);
	for(int i=0;i<N;i++)
		in_I(arr[i]);
	build_segment_tree(1,0,N-1);
	int q;
	in_I(q);
	char ch;int x,y;
	while(q--)
	{
		cin>>ch>>x>>y;
		if(ch=='Q')
		{
			tmp=query(1,0,N-1,x-1,y-1);
			printf("%d\n",tmp.max1+tmp.max2);
		}else
		{
			arr[x-1]=y;
			update(1,0,N-1,x-1);
		}
	}
}
