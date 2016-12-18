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

#define ARR_SIZE 1000010
struct node{
    //Node variables
    long long val;
    int noodd, noeven;
    int carry;
    int lastop;
    int firstop;
    int pcarry;
};
void lazy_prop(int, int, int);
node TREE[ARR_SIZE<<2];
int n,arr[ARR_SIZE];
using namespace std;
void build_segment_tree(int NODE,int a,int b)
{
    if(a==b){
        // Single node condition
        TREE[NODE].val = arr[a];
        TREE[NODE].noodd = (arr[a]%2);
        TREE[NODE].noeven = !TREE[NODE].noodd;
        TREE[NODE].carry = TREE[NODE].pcarry =0;
        TREE[NODE].lastop = TREE[NODE].firstop = -1;
        return;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    build_segment_tree(left,a,mid);
    build_segment_tree(right,mid+1,b);

    // Merge Logic for left and right
    TREE[NODE].carry = TREE[NODE].pcarry =0;
    TREE[NODE].lastop = TREE[NODE].firstop = -1;
    TREE[NODE].val = TREE[left].val + TREE[right].val;
    TREE[NODE].noodd = TREE[left].noodd + TREE[right].noodd;
    TREE[NODE].noeven = TREE[left].noeven + TREE[right].noeven;
}

long long query_segment_tree(int NODE,int a,int b,int x,int y)
{
    if(x<=a && y>=b)return TREE[NODE].val;
    lazy_prop(NODE, a, b);
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(y<=mid)return query_segment_tree(left,a,mid,x,y);
    if(x>mid)return query_segment_tree(right,mid+1,b,x,y);

    long long left_query=query_segment_tree(left,a,mid,x,y);
    long long right_query=query_segment_tree(right,mid+1,b,x,y);

    // Merge left_query and right_query into ans
    
    return left_query+right_query;
}
void update_segment_tree(int NODE,int a,int b,int l, int r, int x, int y, int z)
{
    if(l<=a && r>=b){
        if(TREE[NODE].firstop == -1){
            TREE[NODE].pcarry += y;
            TREE[NODE].val += y*1LL*(TREE[NODE].noeven+TREE[NODE].noodd);
            
        }
        if(y%2)
                swap(TREE[NODE].noodd, TREE[NODE].noeven);


        if(x == 2 && TREE[NODE].firstop == -1){
            TREE[NODE].pcarry++;
            TREE[NODE].val += TREE[NODE].noodd+TREE[NODE].noeven;
            swap(TREE[NODE].noodd, TREE[NODE].noeven);
            return;
        }
        int incr = 0;
        if(x == 0){
            if(TREE[NODE].firstop != -1 && TREE[NODE].noodd == 0)
                incr++;
            TREE[NODE].val += TREE[NODE].noeven;
            TREE[NODE].noodd += TREE[NODE].noeven;
            TREE[NODE].noeven = 0;
        }else if(x == 1){
            if(TREE[NODE].firstop != -1 && TREE[NODE].noeven == 0)
                incr++;
            TREE[NODE].val += TREE[NODE].noodd;
            TREE[NODE].noeven += TREE[NODE].noodd;
            TREE[NODE].noodd = 0;
        }else if(x == 2){
            incr++;
            TREE[NODE].val += TREE[NODE].noeven + TREE[NODE].noodd;
            swap(TREE[NODE].noeven, TREE[NODE].noodd);
        }
        TREE[NODE].carry += incr+z;
        if(z%2)
            swap(TREE[NODE].noodd, TREE[NODE].noeven);
        if(TREE[NODE].firstop != -1){
            TREE[NODE].carry += y;
            z += y;
            y = 0;
        }

        TREE[NODE].val += z*1LL*(TREE[NODE].noeven+TREE[NODE].noodd);
        if(TREE[NODE].firstop == -1){
            TREE[NODE].firstop = x;
        }
        return;
    }
    lazy_prop(NODE, a, b);
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(l<=mid)
    update_segment_tree(left,a,mid,l,r,x,y,z);
    if(r>mid)
    update_segment_tree(right,mid+1,b,l,r,x,y,z);

    //Merge left and right nodes
    TREE[NODE].val = TREE[left].val + TREE[right].val;
    TREE[NODE].noodd = TREE[left].noodd + TREE[right].noodd;
    TREE[NODE].noeven = TREE[left].noeven + TREE[right].noeven;

}
void lazy_prop(int NODE, int a, int b){
    int left = NODE<<1;
    int right = left+1;
    int mid = (a+b)/2;
    if(a < b)
    update_segment_tree(left, a, mid, a, mid, TREE[NODE].firstop, TREE[NODE].pcarry, TREE[NODE].carry);
    if(a < b)
    update_segment_tree(right, mid+1, b, mid+1, b, TREE[NODE].firstop, TREE[NODE].pcarry, TREE[NODE].carry);
    TREE[NODE].firstop = -1;
    TREE[NODE].carry = TREE[NODE].pcarry = 0;
}
void trav(int NODE, int a, int b){
    cout<<a<<" "<<b<<endl;
    cout<<TREE[NODE].val<<" "<<TREE[NODE].pcarry<<" "<<TREE[NODE].carry<<" ";
    cout<<TREE[NODE].firstop<<endl;
    cout<<" -> "<<TREE[NODE].noodd<<" "<<TREE[NODE].noeven<<endl;
    int mid = (a+b)/2;
    if(a == b)
        return;
    trav(2*NODE, a, mid);
    trav(2*NODE+1, mid+1, b);
}
int main()
{
    in_I(n);
    for(int i = 1;i<=n;i++){
        in_I(arr[i]);
    }
    build_segment_tree(1, 1, n);
    int q,l,r; 
    char str[3];
    in_I(q);
    while(q--){
        scanf("%s %d %d", str, &l, &r);
        if(str[0] == 'O'){
            update_segment_tree(1, 1, n, l, r, 0, 0, 0);
        }else if(str[0] == 'E'){
            update_segment_tree(1, 1, n, l, r, 1, 0, 0);
        }else if(str[0] == 'I'){
            update_segment_tree(1, 1, n, l, r, 2, 0, 0);
        }else if(str[0] == 'M'){
            printf("%lld\n", query_segment_tree(1, 1, n, l, r));
        }
//        trav(1, 1, n);
    }
}
