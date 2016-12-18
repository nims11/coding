//GQ
/*
    Nimesh Ghelani (nims11)
    offline
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
struct foo
{
    int a,b,i;
    friend bool operator<(const foo &a,const foo &b)
    {
        if(a.b==b.b)
        return a.a<b.a;
        return a.b<b.b;
    }
}bar[240000];
int BIT[31000]={0};
int arr[31000];
int n,done[1000003]={0};

void update(int idx,int v)
{
	while(idx<=n)
	{
		BIT[idx]+=v;
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
int ans[200002];
int main()
{
    in_I(n);
    for(int i=1;i<=n;i++)
    {
        in_I(arr[i]);
        bar[i].a=-1;
        bar[i].b=i;
    }
    int q;
    in_I(q);
    for(int i=n+1;i<=n+q;i++)
    {
        in_I(bar[i].a);
        in_I(bar[i].b);
        bar[i].i=i-n;
    }
    sort(bar,bar+n+q+1);
    for(int i=0;i<n+q+1;i++)
    {
        if(bar[i].a==-1)
        {
            if(done[arr[bar[i].b]])
            {
                update(done[arr[bar[i].b]],-1);
            }
            update(bar[i].b,1);
            done[arr[bar[i].b]]=bar[i].b;
        }else
        {
            ans[bar[i].i]=query(bar[i].b)-query(bar[i].a-1);
        }
    }
    for(int i=1;i<=q;i++)
    printf("%d\n",ans[i]);
}
