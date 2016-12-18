//GQ
/*
    Nimesh Ghelani (nims11)
    Flipping + Lazy Propagation
    When Flipping, reverse the flip bit highest subset range
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

#define ARR_SIZE 100002
struct node
{
    //Node variables
    int sum, lmax, lmin, rmax, rmin, _max, _min;
};
node TREE[ARR_SIZE<<2];
int n,arr[ARR_SIZE];
bool flipFlag[ARR_SIZE<<2];
using namespace std;
void build_segment_tree(int NODE,int a,int b)
{
    flipFlag[NODE] = false;
    if(a==b)
    {
        // Single node condition
        TREE[NODE].sum = TREE[NODE].lmax = TREE[NODE].lmin = TREE[NODE].rmax = TREE[NODE].rmin = TREE[NODE]._min = TREE[NODE]._max = arr[a];
        return;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    build_segment_tree(left,a,mid);
    build_segment_tree(right,mid+1,b);

    // Merge Logic for left and right
    TREE[NODE].sum = TREE[left].sum + TREE[right].sum;

    TREE[NODE].lmax = max(TREE[left].lmax, TREE[left].sum + TREE[right].lmax);
    TREE[NODE].rmax = max(TREE[right].rmax, TREE[right].sum + TREE[left].rmax);
    TREE[NODE]._max = max(max(TREE[left]._max, TREE[right]._max), TREE[left].rmax + TREE[right].lmax);

    TREE[NODE].lmin = min(TREE[left].lmin, TREE[left].sum + TREE[right].lmin);
    TREE[NODE].rmin = min(TREE[right].rmin, TREE[right].sum + TREE[left].rmin);
    TREE[NODE]._min = min(min(TREE[left]._min, TREE[right]._min), TREE[left].rmin + TREE[right].lmin);
}
node query_segment_tree(int NODE,int a,int b,int x,int y)
{
    if(x<=a && y>=b)return TREE[NODE];
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(y<=mid)
    {
        node ans = query_segment_tree(left,a,mid,x,y);
        if(flipFlag[NODE])
        {
            swap(ans.lmax, ans.lmin);
            swap(ans.rmax, ans.rmin);
            swap(ans._max, ans._min);

            ans.lmax = -ans.lmax;
            ans.lmin = -ans.lmin;
            ans.rmax = -ans.rmax;
            ans.rmin = -ans.rmin;
            ans._min = -ans._min;
            ans._max = -ans._max;
            ans.sum = -ans.sum;
        }
        return ans;
    }
    if(x>mid)
    {
        node ans = query_segment_tree(right,mid+1,b,x,y);
        if(flipFlag[NODE])
        {
            swap(ans.lmax, ans.lmin);
            swap(ans.rmax, ans.rmin);
            swap(ans._max, ans._min);

            ans.lmax = -ans.lmax;
            ans.lmin = -ans.lmin;
            ans.rmax = -ans.rmax;
            ans.rmin = -ans.rmin;
            ans._min = -ans._min;
            ans._max = -ans._max;
            ans.sum = -ans.sum;
        }
        return ans;
    }

    node left_query=query_segment_tree(left,a,mid,x,y);
    node right_query=query_segment_tree(right,mid+1,b,x,y);

    node ans;
    // Merge left_query and right_query into ans
    ans.sum = left_query.sum + right_query.sum;

    ans.lmax = max(left_query.lmax, left_query.sum + right_query.lmax);
    ans.rmax = max(right_query.rmax, right_query.sum + left_query.rmax);
    ans._max = max(max(left_query._max, right_query._max), left_query.rmax + right_query.lmax);

    ans.lmin = min(left_query.lmin, left_query.sum + right_query.lmin);
    ans.rmin = min(right_query.rmin, right_query.sum + left_query.rmin);
    ans._min = min(min(left_query._min, right_query._min), left_query.rmin + right_query.lmin);

    if(flipFlag[NODE])
    {
        swap(ans.lmax, ans.lmin);
        swap(ans.rmax, ans.rmin);
        swap(ans._max, ans._min);

        ans.lmax = -ans.lmax;
        ans.lmin = -ans.lmin;
        ans.rmax = -ans.rmax;
        ans.rmin = -ans.rmin;
        ans._min = -ans._min;
        ans._max = -ans._max;
        ans.sum = -ans.sum;
    }
    return ans;
}

void flip(int NODE,int a,int b, int x, int y)
{
    if(x<=a && b<=y)
    {
        flipFlag[NODE] = !flipFlag[NODE];
        swap(TREE[NODE].lmax, TREE[NODE].lmin);
        swap(TREE[NODE].rmax, TREE[NODE].rmin);
        swap(TREE[NODE]._max, TREE[NODE]._min);

        TREE[NODE].lmax = -TREE[NODE].lmax;
        TREE[NODE].lmin = -TREE[NODE].lmin;
        TREE[NODE].rmax = -TREE[NODE].rmax;
        TREE[NODE].rmin = -TREE[NODE].rmin;
        TREE[NODE]._min = -TREE[NODE]._min;
        TREE[NODE]._max = -TREE[NODE]._max;
        TREE[NODE].sum = -TREE[NODE].sum;
    }else if(!(a>y || b<x))
    {
        int left = 2*NODE, right = 2*NODE + 1;
        int mid = (a+b)/2;
        flip(left, a, mid, x, y);
        flip(right, mid+1, b, x, y);

        TREE[NODE].sum = TREE[left].sum + TREE[right].sum;

        TREE[NODE].lmax = max(TREE[left].lmax, TREE[left].sum + TREE[right].lmax);
        TREE[NODE].rmax = max(TREE[right].rmax, TREE[right].sum + TREE[left].rmax);
        TREE[NODE]._max = max(max(TREE[left]._max, TREE[right]._max), TREE[left].rmax + TREE[right].lmax);

        TREE[NODE].lmin = min(TREE[left].lmin, TREE[left].sum + TREE[right].lmin);
        TREE[NODE].rmin = min(TREE[right].rmin, TREE[right].sum + TREE[left].rmin);
        TREE[NODE]._min = min(min(TREE[left]._min, TREE[right]._min), TREE[left].rmin + TREE[right].lmin);

        if(flipFlag[NODE])
        {
            swap(TREE[NODE].lmax, TREE[NODE].lmin);
            swap(TREE[NODE].rmax, TREE[NODE].rmin);
            swap(TREE[NODE]._max, TREE[NODE]._min);

            TREE[NODE].lmax = -TREE[NODE].lmax;
            TREE[NODE].lmin = -TREE[NODE].lmin;
            TREE[NODE].rmax = -TREE[NODE].rmax;
            TREE[NODE].rmin = -TREE[NODE].rmin;
            TREE[NODE]._min = -TREE[NODE]._min;
            TREE[NODE]._max = -TREE[NODE]._max;
            TREE[NODE].sum = -TREE[NODE].sum;
        }
    }
}
int a,b,c;
int main()
{
    in_T
    {
        in_I(n);
        for(int i=0;i<n;i++)
            in_I(arr[i]);
        int Q;
        build_segment_tree(1, 0, n-1);
        in_I(Q);
        while(Q--)
        {
            scanf("%d%d%d", &c, &a, &b);
            if(!c)
                flip(1, 0, n-1, a, b);
            else
                printf("%d\n", query_segment_tree(1, 0, n-1, a, b)._max);
        }
    }
}
