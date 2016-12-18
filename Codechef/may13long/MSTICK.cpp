/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

#define ARR_SIZE 100005
struct node
{
    int max_v, min_v;
};
node TREE[ARR_SIZE<<2];
int n,arr[ARR_SIZE];
using namespace std;
void build_segment_tree(int NODE,int a,int b)
{

    if(a==b)
    {
        TREE[NODE].max_v = TREE[NODE].min_v = arr[a];
        return;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    build_segment_tree(left,a,mid);
    build_segment_tree(right,mid+1,b);

    TREE[NODE].max_v = max(TREE[left].max_v, TREE[right].max_v);
    TREE[NODE].min_v = min(TREE[left].min_v, TREE[right].min_v);
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
    ans.max_v = max(left_query.max_v, right_query.max_v);
    ans.min_v = min(left_query.min_v, right_query.min_v);
    return ans;
}
int main()
{
    int n;
    in_I(n);
    for(int i=0;i<n;i++)
    {
        in_I(arr[i]);
    }
    build_segment_tree(1, 0, n-1);
    int q;
    in_I(q);
    int l,r;
    while(q--)
    {
        in_I(l);in_I(r);
        double max1 = 0, max2 = 0, max3 = 0;
        if(l!=0)
        {
            max1 = query_segment_tree(1, 0, n-1, 0, l-1).max_v;
        }
        if(r!=n-1)
        {
            max2 = query_segment_tree(1, 0, n-1, r+1, n-1).max_v;
        }
        max3 = query_segment_tree(1, 0, n-1, l,r).max_v;
        double min3 = query_segment_tree(1, 0, n-1, l,r).min_v;
        max3 = (max3-min3)/2;
        printf("%.1lf\n", min3+max(max1, max(max3, max2)));
    }
}
