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
int n,v,p,q;
struct node
{
    int a[2],add;
    friend node operator+(const node &a,int b)
    {
        node c;
        c.a[0]=a.a[0]+b;
        c.a[1]=a.a[1]+b;
    }
}TREE[2000000];
using namespace std;
void build_segment_tree(int NODE,int a,int b)
{
    TREE[NODE].add=0;

    if(a==b)
    {
        TREE[NODE].a[0]=TREE[NODE].a[1]=a;
        return;
    }
    int mid=(a+b)/2,left = 2*NODE;int right = right = left+1;
    build_segment_tree(left,a,mid);
    build_segment_tree(right,mid+1,b);
    TREE[NODE].a[0] = b;
    TREE[NODE].a[1] = a;
}

void update_segment_tree(int NODE,int a,int b)
{
//    cout<<a<<" "<<b<<" "<<p<<" "<<q<<endl;
    if(p<=a && q>=b)
    {
        TREE[NODE].a[0]+=v;
        TREE[NODE].a[1]+=v;
        TREE[NODE].add+=v;
        return;
    }
    int mid=(a+b)/2,left = 2*NODE;int right = left+1;
    if(p<=mid)
    update_segment_tree(left,a,mid);

    if(q>mid)
    update_segment_tree(right,mid+1,b);

    if(TREE[left].a[0]>TREE[right].a[0])
    TREE[NODE].a[0] = TREE[left].a[0] + TREE[NODE].add;
    else TREE[NODE].a[0] = TREE[right].a[0] +TREE[NODE].add;

    if(TREE[left].a[1]<TREE[right].a[1])
    TREE[NODE].a[1] = TREE[left].a[1]+TREE[NODE].add;
    else TREE[NODE].a[1] = TREE[right].a[1]+TREE[NODE].add;
}
void traverse(int NODE,int a,int b, int carry=0)
{
    cout<<a<<" "<<b<<" "<<carry<<"="<<carry+TREE[NODE].a[0]<<" "<<carry+TREE[NODE].a[1]<<" "<<TREE[NODE].add<<endl;
    if(a==b)return;
    traverse(2*NODE,a,(a+b)/2, carry+TREE[NODE].add);
    traverse(2*NODE+1,(a+b)/2+1,b, carry+TREE[NODE].add);
}
int main()
{
    in_T{
    in_I(n);
    build_segment_tree(1,1,n);
//    traverse(1,1,n);
//    cout<<endl;
    int P;
    in_I(P);
    while(P--)
    {
        int w,x,y,z;
        scanf("%d %d %d %d",&w,&p,&q,&v);

        if(w==2)v=-v;
        update_segment_tree(1,1,n);
//        traverse(1,1,n);
//        cout<<endl;
    }
    printf("%d\n",TREE[1].a[0]-TREE[1].a[1]);
    }
}
