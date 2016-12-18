/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cassert>
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
struct node{
    unsigned int max;
};
node TREE[ARR_SIZE<<2];
using namespace std;
void build_segment_tree(int NODE,int a,int b)
{
    if(a==b){
        TREE[NODE].max = 0;
        return;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    build_segment_tree(left,a,mid);
    build_segment_tree(right,mid+1,b);


    // Merge Logic for left and right
    TREE[NODE].max = max(TREE[left].max, TREE[right].max);
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
    // Merge left_query and right_query into ans
    ans.max = max(left_query.max, right_query.max);
    return ans;
}
void update_segment_tree(int NODE,int a,int b,int x, unsigned int val)
{
    if(a==b){
        //Single node logic
        TREE[NODE].max = val;
        return;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(x<=mid)
    update_segment_tree(left,a,mid,x, val);
    else
    update_segment_tree(right,mid+1,b,x, val);

    //Merge left and right nodes
    TREE[NODE].max = max(TREE[left].max, TREE[right].max);
}
int main()
{
    in_T{
        int N, Q, x, y;
        unsigned int z;
        in_I(N); in_I(Q);
        while(Q--){
            in_I(x);in_I(y);
            if(x == 0)
            {
                scanf("%u", &z);
                update_segment_tree(1, 1, N, y, z);
            }else{
                printf("%u\n", query_segment_tree(1, 1, N, 1, y).max);
            }
        }
    }
}
