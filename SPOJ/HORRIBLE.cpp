/*
    Nimesh Ghelani (nims11)
    Lazy propagation + Segment Tree
    Instead of updating every child, the topmost exact interval is updated and a carry is increased for that node by the amount of value increased.
    while querying, the carry is added when traversing through that node.
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
long long TREE[1000000], add[1000000];
int n;
using namespace std;
void build_segment_tree(int NODE,int a,int b)
{
    add[NODE]=0;

    if(a==b)
    {
        TREE[NODE]=0;
        return;
    }
    int mid=(a+b)/2;
    build_segment_tree(2*NODE,a,mid);
    build_segment_tree(2*NODE+1,mid+1,b);
    TREE[NODE]=0;
}
long long query_segment_tree(int NODE,int a,int b,int x,int y,long long carry=0)
{
//    cout<<a<<" "<<b<<"="<<TREE[NODE]<<" "<<add[NODE]<<endl;
    if(x<=a && y>=b)return TREE[NODE]+carry*(b-a+1);
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(y<=mid)return query_segment_tree(left,a,mid,x,y,carry+add[NODE]);
    if(x>mid)return query_segment_tree(right,mid+1,b,x,y,carry+add[NODE]);

    return query_segment_tree(left,a,mid,x,y,carry+add[NODE])+query_segment_tree(right,mid+1,b,x,y,carry+add[NODE]);
}
long long update_segment_tree(int NODE,int a,int b,int p,int q,int v)
{
//    cout<<a<<" "<<b<<" ** "<<p<<" "<<q<<endl;
    if(p<=a && q>=b)
    {
        TREE[NODE]+=v*(b-a+1);
        add[NODE]+=v;
        return v*(b-a+1);
    }
    int mid=(a+b)/2;
    long long k=0;
    if(p<=mid)
    k+=update_segment_tree(2*NODE,a,mid,p,q,v);

    if(q>mid)
    k+=update_segment_tree(2*NODE+1,mid+1,b,p,q,v);

    TREE[NODE]+=k;
    return k;
}
int main()
{
    in_T{
    in_I(n);
    build_segment_tree(1,0,n-1);
    int q;
    in_I(q);
    while(q--)
    {
        int a,b,c,d;
        in_I(c);in_I(a);in_I(b);
        if(c==1)
        printf("%lld\n",query_segment_tree(1,0,n-1,a-1,b-1));
        else
        {
            in_I(d);
//            cout<<"*"<<b-1<<" "<<c-1<<endl;
            update_segment_tree(1,0,n-1,a-1,b-1,d);
        }
//        cout<<endl;
    }
    }
}
