/*
    Nimesh Ghelani (nims11)
    Maximum Subarray + Segmented tree
    A normal Maximum Subarray + DP solution will give TLE.
    build a segmented tree and store in each node, its max_left_sum, max_right_sum, max_sum, and sum
    suitably merge the children nodes to get parent node.
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
struct node
{
    long long sum,max_l,max_r,max;
};
node TREE[1000000];
int n,arr[51000];
using namespace std;
void build_segment_tree(int NODE,int a,int b)
{

    if(a==b)
    {
        TREE[NODE].sum=TREE[NODE].max_l=TREE[NODE].max_r=TREE[NODE].max=arr[a];
        return;
    }
    int mid=(a+b)/2;
    build_segment_tree(2*NODE,a,mid);
    build_segment_tree(2*NODE+1,mid+1,b);

    int left=2*NODE,right=2*NODE+1;
    TREE[NODE].sum=TREE[left].sum+TREE[right].sum;
    TREE[NODE].max_l=max(TREE[left].max_l,TREE[left].sum+TREE[right].max_l);
    TREE[NODE].max_r=max(TREE[right].max_r,TREE[right].sum+TREE[left].max_r);
    TREE[NODE].max=max(max(TREE[left].max,TREE[right].max),TREE[left].max_r+TREE[right].max_l);
}
node query_segment_tree(int NODE,int a,int b,int x,int y)
{
    if(x<=a && y>=b)return TREE[NODE];
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(y<=mid)return query_segment_tree(left,a,mid,x,y);
    if(x>mid)return query_segment_tree(right,mid+1,b,x,y);

    node left_query=query_segment_tree(left,a,mid,x,y);
    node right_query=query_segment_tree(right,mid+1,b,x,y);

    node ans;
    ans.sum=left_query.sum+right_query.sum;
    ans.max_l=max(left_query.max_l,left_query.sum+right_query.max_l);
    ans.max_r=max(right_query.max_r,right_query.sum+left_query.max_r);
    ans.max=max(max(left_query.max,right_query.max),left_query.max_r+right_query.max_l);
    return ans;
}
int main()
{
    in_I(n);
    for(int i=0;i<n;i++)
    {
        in_I(arr[i]);
    }
    build_segment_tree(1,0,n-1);
    int q;
    in_I(q);
    while(q--)
    {
        int a,b;
        in_I(a);in_I(b);
        printf("%lld\n",query_segment_tree(1,0,n-1,a-1,b-1).max);
    }
}
