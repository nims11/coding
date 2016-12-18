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

#define ARR_SIZE 100010
using namespace std;
    int mod = 1000000007;
struct node{
    //Node variables
    long long val;
    vector<int> carry;
};
void lazy_prop(int, int, int);
long a1=0,a2=0;
#define ADD(a,b) ((a+b)%mod)
#define MUL(a,b) ((a*1LL*b)%mod)

void matpow(long long n,long long M[2][2],long long m)
{
    if (n > 1)
    {
        matpow(n/2,M,m);
        long long a=M[0][0],b=M[0][1],c=M[1][0],d=M[1][1];
        M[0][0]=((a*a)%m+(b*c)%m)%m;
        M[0][1]=((a*b)%m+(b*d)%m)%m;
        M[1][0]=((c*a)%m+(d*c)%m)%m;
        M[1][1]=((c*b)%m+(d*d)%m)%m;

    }
    if (n %2 ==1)
    {
        long long a=M[0][0],b=M[0][1],c=M[1][0],d=M[1][1];
        M[0][0]=(a+b)%m;
        M[0][1]=a%m;
        M[1][0]=(c+d)%m;
        M[1][1]=c%m;
    }
}
void fib(long long n,long long m)
{
    long long M[2][2] = {{1%m,0%m},{0%m,1%m}};
    matpow(n-1,M,m);
    a1=M[1][0];
    a2=M[0][0];
}

node TREE[ARR_SIZE<<2];
int n,arr[ARR_SIZE];
void build_segment_tree(int NODE,int a,int b){
    if(a==b){
        TREE[NODE].val = 0;
        return;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    build_segment_tree(left,a,mid);
    build_segment_tree(right,mid+1,b);

    // Merge Logic for left and right
    TREE[NODE].val = 0;
}
long long query_segment_tree(int NODE,int a,int b,int x,int y){
    if(x<=a && y>=b)return TREE[NODE].val;
    lazy_prop(NODE, a, b);
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(y<=mid)return query_segment_tree(left,a,mid,x,y);
    if(x>mid)return query_segment_tree(right,mid+1,b,x,y);

    long long left_query=query_segment_tree(left,a,mid,x,y);
    long long right_query=query_segment_tree(right,mid+1,b,x,y);

    node ans;
    // Merge left_query and right_query into ans
    return left_query+ right_query;
}
void update_segment_tree(int NODE,int a,int b, int l, int r,int x){
    // cout<<a<<" "<<b<<" "<<l<<" "<<r<<" "<<x<<endl;
    if(l<=a && r>=b){
        fib(x, mod);
        TREE[NODE].val = ADD(TREE[NODE].val, a2);
        TREE[NODE].carry.push_back(x);
        return;
    }
    lazy_prop(NODE, a, b);
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(l<=mid) update_segment_tree(left,a,mid,l,r,x+1);
    if(r>mid)update_segment_tree(right,mid+1,b,l,r,x+1);

    //Merge left and right nodes
    TREE[NODE].val = TREE[left].val + TREE[right].val;
}
void lazy_prop(int NODE, int a, int b){
    int left = NODE<<1;
    int right = left+1;
    int mid = (a+b)/2;
    if(a < b){
        for(int v: TREE[NODE].carry){
            update_segment_tree(left, a, mid, a, mid, v+1);
            update_segment_tree(right, mid+1, b, mid+1, b, v+1);
        }
    }
    TREE[NODE].carry.clear();
}
void trav(int NODE, int a, int b){
    cout<<a<<"--"<<b<<endl;
    cout<<TREE[NODE].val<<" "<<TREE[NODE].carry.size()<<endl;
    for(int v: TREE[NODE].carry)
        cout<<v<<" ";
    cout<<endl;
    // cout<<TREE[NODE].val<<" "<<TREE[NODE].pcarry<<" "<<TREE[NODE].carry<<" ";
    // cout<<TREE[NODE].firstop<<endl;
    // cout<<" -> "<<TREE[NODE].noodd<<" "<<TREE[NODE].noeven<<endl;
    int mid = (a+b)/2;
    if(a == b)
        return;
    trav(2*NODE, a, mid);
    trav(2*NODE+1, mid+1, b);
}
vector<int> neigh[100010];
int in_id[100010], out_id[100010];
int cnt_id;
int dfs(int idx, int par=-1){
    in_id[idx] = out_id[idx] = ++cnt_id;
    // cout<<idx<<" "<<in_id[idx]<<endl;
    for(int u: neigh[idx]){
        if(u != par){
            out_id[idx] = max(out_id[idx], dfs(u, idx));
        }
    }
    // cout<<idx<<" "<<out_id[idx]<<endl;
    return out_id[idx];
}
int main()
{
    int N, M;
    in_I(N);
    in_I(M);
    for(int i = 0;i<N-1;i++){
        int u, v;
        u = i+2;
        scanf("%d", &v);
        neigh[u].push_back(v);
        neigh[v].push_back(u);
    }
    dfs(1);
    build_segment_tree(1, 1, N);
    while(M--){
        char c;
        int u,v;
        scanf("\n%c %d", &c, &u);
        cout<<c<<" "<<u<<endl;
        if(c == 'U'){
            in_I(v);
            update_segment_tree(1, 1, N, in_id[u], out_id[u], v);
            // trav(1, 1, N);
            // return 0;
        }else{
            printf("%lld\n", query_segment_tree(1, 1, N, in_id[u], in_id[u]));
        }
    }
}
