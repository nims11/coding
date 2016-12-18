/*
    Nimesh Ghelani (nims11)
    Lazy propagation + Segment Tree
    Instead of updating every child, the topmost exact interval is updated and a carry is increased for that node by the amount of value increased.
    while querying, the carry is added when traversing through that node.
    See the structure of the node for the details stored in the nodes of the tree
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
struct node
{
    int cnt[3];
    int add;
    friend node operator+(const node &a,const node &b)
    {
        node s;
        for(int i=0;i<3;i++)
        s.cnt[i]=a.cnt[i]+b.cnt[i];
        return s;
    }
    node& operator=(const node &a)
    {
        for(int i=0;i<3;i++)
        this->cnt[i]=a.cnt[i];
        return *this;
    }
};
node TREE[1000000];
int n;
using namespace std;
void build_segment_tree(int NODE,int a,int b)
{
    TREE[NODE].add=0;
    if(a==b)
    {
        TREE[NODE].cnt[0]=1;
        TREE[NODE].cnt[1]=TREE[NODE].cnt[2]=0;
        return;
    }
    int mid=(a+b)/2;
    build_segment_tree(2*NODE,a,mid);
    build_segment_tree(2*NODE+1,mid+1,b);
    TREE[NODE].cnt[0]=b-a+1;
    TREE[NODE].cnt[1]=TREE[NODE].cnt[2]=0;
}
node query_segment_tree(int NODE,int a,int b,int x,int y,int carry=0)
{
    if(x<=a && y>=b)
    {
        node ans;
        for(int i=0;i<3;i++)
        {
            ans.cnt[(i+carry)%3]=TREE[NODE].cnt[i];
        }
        return ans;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(y<=mid)return query_segment_tree(left,a,mid,x,y,carry+TREE[NODE].add);
    if(x>mid)return query_segment_tree(right,mid+1,b,x,y,carry+TREE[NODE].add);
    node LEFT=query_segment_tree(left,a,mid,x,y,carry+TREE[NODE].add),RIGHT=query_segment_tree(right,mid+1,b,x,y,carry+TREE[NODE].add);

    node ans;
    ans=LEFT+RIGHT;
    return ans;
}
void update_segment_tree(int NODE,int a,int b,int p,int q)
{
    if(p<=a && q>=b)
    {
        int tmp=TREE[NODE].cnt[1];

        TREE[NODE].cnt[1]=TREE[NODE].cnt[0];
        TREE[NODE].cnt[0]=TREE[NODE].cnt[2];
        TREE[NODE].cnt[2]=tmp;
        TREE[NODE].add++;
        return;

    }
    int mid=(a+b)/2;
    if(p<=mid)
    {
        update_segment_tree(2*NODE,a,mid,p,q);
    }

    if(q>mid)
    {
        update_segment_tree(2*NODE+1,mid+1,b,p,q);
    }
TREE[NODE]=query_segment_tree(2*NODE,a,mid,a,mid,TREE[NODE].add)+query_segment_tree(2*NODE+1,mid+1,b,mid+1,b,TREE[NODE].add);

}
void traverse(int NODE,int a,int b)
{
    cout<<a<<" "<<b<<"="<<TREE[NODE].cnt[0]<<" "<<TREE[NODE].cnt[1]<<" "<<TREE[NODE].cnt[2]<<" "<<TREE[NODE].add<<endl;
    if(a==b)return;
    traverse(2*NODE,a,(a+b)/2);
    traverse(2*NODE+1,(a+b)/2+1,b);
}
int main()
{
    in_I(n);
    build_segment_tree(1,0,n-1);
    int q;
    in_I(q);
    while(q--)
    {
        int a,b,c,d;
        in_I(c);in_I(a);in_I(b);
        if(c==1)
        printf("%d\n",query_segment_tree(1,0,n-1,a,b).cnt[0]);
        else
        {
            update_segment_tree(1,0,n-1,a,b);
//            traverse(1,0,n-1);
//            cout<<endl;
        }
    }
}
