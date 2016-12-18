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
    int idx, val;
    node& operator=(const node &a)
    {
        this->idx = a.idx;
        this->val = a.val;
        return *this;
    }
};
node min(node &a, node &b)
{
    return a.val<b.val?a:b;
}
node TREE[1000000];
int n,arr[51000];
using namespace std;
void build_segment_tree(int NODE,int a,int b)
{

    if(a==b)
    {
        TREE[NODE].val = arr[a];
        TREE[NODE].idx = a;
        return;
    }
    int mid=(a+b)/2;
    build_segment_tree(2*NODE,a,mid);
    build_segment_tree(2*NODE+1,mid+1,b);

    int left=2*NODE,right=2*NODE+1;
    TREE[NODE]=min(TREE[left], TREE[right]);

}
node query_segment_tree(int NODE,int a,int b,int x,int y)
{
//    cout<<x<<" "<<y<<" "<<a<<" "<<b<<endl;
//    cin>>n;
    if(x<=a && y>=b)return TREE[NODE];
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(y<=mid)return query_segment_tree(left,a,mid,x,y);
    if(x>mid)return query_segment_tree(right,mid+1,b,x,y);

    node left_query=query_segment_tree(left,a,mid,x,y);
    node right_query=query_segment_tree(right,mid+1,b,x,y);

    return min(left_query, right_query);
}
const int M = 1000000007;
int foo(int idx, int a, int b, int curr)
{
//    cout<<a<<" "<<b<<" "<<curr<<endl;
//    cin>>n;
    if(a==b || curr<a ||  curr>b)return 1;
    long long ret = 1;
    if(idx==curr)return ret = (foo(idx, a,b, idx+1)*(long long)foo(idx, a, b, idx-1))%M;
    int l = min(idx, curr);
    int r = max(idx, curr);
    while(l>=a && arr[l]<=arr[curr])l--;
    l++;
    while(r<=b && arr[r]<=arr[curr])r++;
    r--;
    ret = (ret*(foo(idx, a, b, l-1)*foo(idx, a,b, r+1))%M)%M;
    return (((((ret*(arr[curr]-arr[idx]))%M)*(r-max(idx, curr)+1))%M)*(min(idx, curr)-l+1))%M;
}
int getans(int idx, int a, int b)
{
//    cout<<a<<" "<<b<<endl;
    long long ret = 1;
    int left = -1, right = -1;
    if(idx>a){
        left = query_segment_tree(1,0,n-1,a,idx-1).idx;
        ret = getans(left,a, idx-1);
    }
    if(idx<b){
        right = query_segment_tree(1,0,n-1,idx+1,b).idx;
        ret = (ret*getans(right, idx+1, b))%M;
    }
    return (foo(idx, a, b, idx)*ret)%M;
}
int main()
{
    in_I(n);
    for(int i=0;i<n;i++)
        in_I(arr[i]);
    build_segment_tree(1,0,n-1);
    cout<<getans(query_segment_tree(1,0,n-1,0,n-1).idx, 0, n-1)<<endl;
}
