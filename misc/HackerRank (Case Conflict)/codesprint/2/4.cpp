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
#include<cstring>
#include<cstdlib>
#include<cassert>
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
#define ARR_SIZE 100001
struct node{
    //Node variables
    long long carry;
    int maxidx;
    long long maxval;
};
node TREE[ARR_SIZE<<2];
int n,dist[ARR_SIZE], fuel[ARR_SIZE];
long long arr[ARR_SIZE];
using namespace std;
void build_segment_tree(int NODE,int a,int b)
{
    if(a==b){
        // Single node condition
        TREE[NODE].carry = 0;
        TREE[NODE].maxidx = a;
        TREE[NODE].maxval = arr[a];
        return;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    build_segment_tree(left,a,mid);
    build_segment_tree(right,mid+1,b);

    // Merge Logic for left and right
    TREE[NODE].carry = 0;
    TREE[NODE].maxidx = (arr[TREE[left].maxidx] >= arr[TREE[right].maxidx]?
            TREE[left].maxidx:TREE[right].maxidx);
    TREE[NODE].maxval = arr[TREE[NODE].maxidx];
}
node query_segment_tree(int NODE,int a,int b,int x,int y)
{
    if(x<=a && y>=b){
        return TREE[NODE];
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(y<=mid){
        node ret = query_segment_tree(left,a,mid,x,y);
        ret.maxval += ret.carry;
        ret.carry = TREE[NODE].carry;
        return ret;
    }
    if(x>mid){
        node ret = query_segment_tree(right,mid+1,b,x,y);
        ret.maxval += ret.carry;
        ret.carry = TREE[NODE].carry;
        return ret;
    }

    node left_query=query_segment_tree(left,a,mid,x,y);
    node right_query=query_segment_tree(right,mid+1,b,x,y);

    left_query.maxval += left_query.carry;
    right_query.maxval += left_query.carry;
    left_query.carry = right_query.carry = TREE[NODE].carry;

    // Merge left_query and right_query into ans
    return (left_query.maxval >= right_query.maxval?
            left_query:right_query);
}
void update_segment_tree(int NODE,int a,int b,int x, int y, int z)
{
    if(a>=x && b<=y){
        TREE[NODE].carry += z;
        return;
    }
//    if(a==b){
//        //Single node logic
//        TREE[NODE].maxidx = arr[a];
//        return;
//    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(x<=mid)
    update_segment_tree(left,a,mid,x, y, z);
    if(y>mid)
    update_segment_tree(right,mid+1,b,x, y, z);

    //Merge left and right nodes
    if(TREE[left].maxval + TREE[left].carry >= TREE[right].maxval + TREE[right].carry){
        TREE[NODE].maxidx = TREE[left].maxidx;
        TREE[NODE].maxval = TREE[left].maxval+TREE[left].carry;
    }else{
        TREE[NODE].maxidx = TREE[right].maxidx;
        TREE[NODE].maxval = TREE[right].maxval+TREE[right].carry;
    }
}
int getans(int l, int r, long long q){
    int ret = -1;
    node res = query_segment_tree(1, 1, n+1, l, r);
    long long val = res.maxval+res.carry;
    if(val <= q){
        return -1;
    }
    if(l == r)
        return l;
    int mid = (l+r)/2;
    int L = getans(l, mid, q);
    if(L == -1)
        return getans(mid+1, r, q);
    return L;
}
int main()
{
    in_I(n);
    for(int i = 1;i<=n;i++)
        in_I(dist[i]);
    int x;
    for(int i = 1;i<=n;i++)
    {
        in_I(fuel[i]);
        arr[i] = fuel[i]-dist[i];
    }
    for(int i = n;i>=1;i--)
        arr[i] += arr[i+1];
    build_segment_tree(1, 1, n+1);

    int q;
    in_I(q);
    while(q--){
        int t, q1,q2;
        in_I(t);
        in_I(q1);
        if(t == 1){
            in_I(q2);
            int tmp = fuel[q1];
            fuel[q1] = q2;
            update_segment_tree(1, 1, n+1, 1, q1, q2-tmp);
        }else{
            node qval = query_segment_tree(1, 1, n+1, q1, q1);
            long long res = getans(q1+1, n+1, qval.maxval+qval.carry);
            if(res == -1)
                res = n+1;
            else res--;
            printf("%d\n", res);
        }
    }
}
