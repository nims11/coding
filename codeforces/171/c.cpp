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

using namespace std;
struct node
{
    int mx;
    bool inc, dec, ladd;
    // 0 -> inc
    // 1 -> dec
    // 2 -> ladd
    // 3 ->nthin
};
node TREE[500000];
int n,arr[100003];
using namespace std;
void build_segment_tree(int NODE,int a,int b)
{

    if(a==b)
    {
        TREE[NODE].mx = arr[a];
        TREE[NODE].inc = TREE[NODE].dec = TREE[NODE].ladd = true;
        return;
    }
    int mid=(a+b)/2;
    build_segment_tree(2*NODE,a,mid);
    build_segment_tree(2*NODE+1,mid+1,b);

    int left=2*NODE,right=2*NODE+1;
    TREE[NODE].mx = max(TREE[left].mx, TREE[right].mx);
    TREE[NODE].inc = TREE[NODE].dec = TREE[NODE].ladd = false;
    if(TREE[left].inc && TREE[right].inc && arr[mid]<=arr[mid+1])
    {
        TREE[NODE].inc = true;
        TREE[NODE].ladd = true;
    }
    else if(TREE[left].dec && TREE[right].dec && arr[mid]>=arr[mid+1])
    {
        TREE[NODE].dec = true;
        TREE[NODE].ladd = true;
    }
    else if(TREE[left].inc && TREE[right].ladd && arr[mid]<=arr[mid+1])
    {
        TREE[NODE].ladd = true;
    }
    else if(TREE[left].ladd && TREE[right].dec && arr[mid]>=arr[mid+1])
        TREE[NODE].ladd = true;
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
    ans.mx = max(left_query.mx, right_query.mx);
    ans.inc = ans.dec = ans.ladd = false;
    if(left_query.inc && right_query.inc && arr[mid]<=arr[mid+1])
    {
        ans.inc = true;
        ans.ladd = true;
    }
    else if(left_query.dec && right_query.dec && arr[mid]>=arr[mid+1])
    {
        ans.dec = true;
        ans.ladd = true;
    }
    else if(left_query.inc && right_query.ladd && arr[mid]<=arr[mid+1])
    {
        ans.ladd = true;
    }
    else if(left_query.ladd && right_query.dec && arr[mid]>=arr[mid+1])
        ans.ladd = true;
    return ans;
}
int main()
{
    int n,m;
    in_I(n);in_I(m);
    for(int i=0;i<n;i++)
        in_I(arr[i]);
    build_segment_tree(1, 0, n-1);
    int x,y;
    while(m--)
    {
        in_I(x);
        in_I(y);
        if(query_segment_tree(1, 0, n-1, x-1, y-1).ladd)
            printf("Yes\n");
        else
            printf("No\n");
    }
}
