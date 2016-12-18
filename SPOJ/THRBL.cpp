
/*
    Nimesh Ghelani (nims11)
    Segment Tree to find the maximum for an interval.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
int TREE[1000000];
int n,arr[51000];
using namespace std;
void build_segment_tree(int NODE,int a,int b)
{

    if(a==b)
    {
        TREE[NODE]=arr[a];
        return;
    }
    int mid=(a+b)/2;
    build_segment_tree(2*NODE,a,mid);
    build_segment_tree(2*NODE+1,mid+1,b);

    int left=2*NODE,right=2*NODE+1;
    TREE[NODE]=max(TREE[left],TREE[right]);
}
int query_segment_tree(int NODE,int a,int b,int x,int y)
{
    if(x<=a && y>=b)return TREE[NODE];
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(y<=mid)return query_segment_tree(left,a,mid,x,y);
    if(x>mid)return query_segment_tree(right,mid+1,b,x,y);

    int left_query=query_segment_tree(left,a,mid,x,y);
    int right_query=query_segment_tree(right,mid+1,b,x,y);

    return max(left_query,right_query);
}
int main()
{
	int q;
	while(cin>>n>>q)
	{
    for(int i=0;i<n;i++)
    {
        in_I(arr[i]);
    }
    build_segment_tree(1,0,n-1);
    int ans=0;
    while(q--)
    {
        int a,b;
        in_I(a);in_I(b);
	if(b==a+1)
		ans++;
	else if(query_segment_tree(1,0,n-1,a,b-2)<=arr[a-1])
		ans++;
    }
    cout<<ans<<endl;
	}
}
