/*
    Nimesh Ghelani (nims11)
*/
#include<cassert>
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

#define ARR_SIZE 1000010
struct node{
    //Node variables
    int cnt[4];
    int propo;
};
node TREE[ARR_SIZE<<4];
using namespace std;
void update_segment_tree(int NODE,int a,int b,int l, int r, int k);
void build_segment_tree(int NODE,int a,int b)
{
    if(a==b){
        // Single node condition
        for(int i = 0;i<4;i++)
            TREE[NODE].cnt[i] = 0;
        TREE[NODE].cnt[0] = 1;
        return;
    }
    TREE[NODE].propo = 0;
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    build_segment_tree(left,a,mid);
    build_segment_tree(right,mid+1,b);

    // Merge Logic for left and right
    for(int i = 0;i<4;i++)
        TREE[NODE].cnt[i] = TREE[left].cnt[i]+TREE[right].cnt[i];
}
node query_segment_tree(int NODE,int a,int b,int x,int y)
{
//    cout<<a<<" "<<b<<endl;
    if(TREE[NODE].propo){
//        cout<<"Propagating: "<<TREE[NODE].propo<<endl;
        update_segment_tree(NODE, a, b, a, b, 0);
    }
    if(x<=a && y>=b)return TREE[NODE];
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(y<=mid)return query_segment_tree(left,a,mid,x,y);
    if(x>mid)return query_segment_tree(right,mid+1,b,x,y);

    node left_query=query_segment_tree(left,a,mid,x,y);
    node right_query=query_segment_tree(right,mid+1,b,x,y);

    node ans;
    // Merge left_query and right_query into ans
    for(int i = 0;i<4;i++)
        ans.cnt[i] = left_query.cnt[i] + right_query.cnt[i];
    return ans;
}
void update_segment_tree(int NODE,int a,int b,int l, int r, int k)
{
    int left=2*NODE,right=2*NODE+1;
    if(a>=l && b<=r){
        int tmp[4];
        int netK = (TREE[NODE].propo+k+4)%4;
        TREE[NODE].propo = 0;
        for(int i = 0;i<4;i++)
            tmp[i] = TREE[NODE].cnt[i];
        for(int i = 0;i<4;i++)
            TREE[NODE].cnt[(i+4+netK)%4] = tmp[i];
        if(a != b)
            TREE[left].propo = (TREE[left].propo+netK+4)%4,
            TREE[right].propo = (TREE[right].propo+netK+4)%4;
        return;
    }

    TREE[left].propo = (TREE[left].propo+4)%4,
    TREE[right].propo = (TREE[right].propo+4)%4;

    int mid=(a+b)/2;
    if(l<=mid)
        update_segment_tree(left,a,mid, l, r, k);
    if(r>mid)
        update_segment_tree(right,mid+1,b, l, r, k);

    //Merge left and right nodes
    if(TREE[left].propo){
        update_segment_tree(left, a, mid, a, mid, 0);
    }
    if(TREE[right].propo){
        update_segment_tree(right, mid+1, b, mid+1, b, 0);
    }
    for(int i = 0;i<4;i++)
        TREE[NODE].cnt[i] = TREE[left].cnt[i]+TREE[right].cnt[i];
}
int main()
{
    int N, M, L, R, K;
    in_I(N);in_I(M);
    char ch;
    build_segment_tree(1, 1, N);
    while(M--){
        scanf("\n%c %d %d", &ch, &L, &R);
        if(ch == 'Q'){
            node ret = query_segment_tree(1, 1, N, L, R);
            int res = 0;
            for(int i = 0;i<4;i++)
                res = max(res, ret.cnt[i]);
            printf("%d\n", res);
        }else{
            in_I(K);
            if(ch == 'A')
                K = -K;
            K %= 4;
            if(K<0)K+=4;
            update_segment_tree(1, 1, N, L, R, K);
        }
//        for(int i = 0;i<4;i++)
//            cout<<TREE[1].cnt[i]<<" ";
//        cout<<endl;
    }
}
