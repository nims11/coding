/*
    Nimesh Ghelani (nims11)
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
    long long sum,max_l,max_r,max,min_l, min_r, min;
};
node TREE[40002];
int n,arr[10002];
using namespace std;
void build_segment_tree(int NODE,int a,int b)
{

    if(a==b)
    {
        TREE[NODE].sum=TREE[NODE].max_l=TREE[NODE].max_r=TREE[NODE].max=TREE[NODE].min=TREE[NODE].min_r=TREE[NODE].min_l=arr[a];
        return;
    }
    int mid=(a+b)/2;
    build_segment_tree(2*NODE,a,mid);
    build_segment_tree(2*NODE+1,mid+1,b);

    int left=2*NODE,right=2*NODE+1;
    TREE[NODE].sum=TREE[left].sum+TREE[right].sum;
    TREE[NODE].max_l=max(TREE[left].max_l,TREE[left].sum+TREE[right].max_l);
    TREE[NODE].max_r=max(TREE[right].max_r,TREE[right].sum+TREE[left].max_r);
    TREE[NODE].min_l = min(TREE[left].min_l, TREE[left].sum+TREE[right].min_l);
    TREE[NODE].min_r = min(TREE[right].min_r, TREE[right].sum+TREE[left].min_r);
    TREE[NODE].max=max(max(TREE[left].max,TREE[right].max),TREE[left].max_r+TREE[right].max_l);
    TREE[NODE].min=min(min(TREE[left].min, TREE[right].min), TREE[left].min_r+TREE[right].min_l);
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
    ans.min_l = min(left_query.min_l, left_query.sum+right_query.min_l);
    ans.min_r = min(right_query.min_r, right_query.sum+left_query.min_r);
    ans.max=max(max(left_query.max,right_query.max),left_query.max_r+right_query.max_l);
    ans.min=min(min(left_query.min, right_query.min), left_query.min_r+right_query.min_l);
    return ans;
}
node l, r;
int main()
{
    in_T
    {
        in_I(n);
        for(int i=0;i<n;i++)
            in_I(arr[i]);
        long long ans = arr[0]-arr[1];
        build_segment_tree(1, 0, n-1);
        for(int i=1;i<n;i++)
        {
            l = query_segment_tree(1, 0, n-1, 0, i-1);
            r = query_segment_tree(1, 0, n-1, i, n-1);
            ans = max(ans, max(r.max-l.min, l.max-r.min));
        }
        printf("%lld\n", ans);
    }
}
