/*
    Nimesh Ghelani (nims11)
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
    int a[3];
};
node TREE[500000];
int n,arr[100003];
using namespace std;
void build_segment_tree(int NODE,int a,int b)
{

    if(a==b)
    {
        for(int i=0;i<3;i++)
        TREE[NODE].a[i]=0;
        TREE[NODE].a[arr[a]]=1;
        return;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    build_segment_tree(left,a,mid);
    build_segment_tree(right,mid+1,b);

    for(int i=0;i<3;i++)
    TREE[NODE].a[i]=TREE[left].a[i]+TREE[right].a[i];
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
    for(int i=0;i<3;i++)
    ans.a[i]=left_query.a[i]+right_query.a[i];
    return ans;
}
void update_segment_tree(int NODE,int a,int b,int x)
{
    if(a==b)
    {
        for(int i=0;i<3;i++)
        TREE[NODE].a[i]=0;
        TREE[NODE].a[arr[a]]=1;
        return;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(x<=mid)
    update_segment_tree(left,a,mid,x);
    else
    update_segment_tree(right,mid+1,b,x);

    for(int i=0;i<3;i++)
    TREE[NODE].a[i]=TREE[left].a[i]+TREE[right].a[i];
}
char ch;
        int A,B;node foo;
        int q;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        in_I(arr[i]);
    }
    build_segment_tree(1,0,n-1);
    in_I(q);
    while(q--)
    {
//        cout<<"******************************\n";
//        traverse(1,0,n-1);
        cin>>ch;in_I(A);in_I(B);
        if(ch == 'Q')
        {
        foo = query_segment_tree(1,0,n-1,A,B);
        printf("%d %d %d\n",foo.a[0],foo.a[1],foo.a[2]);
        }else
        {
            arr[A]=B;
            update_segment_tree(1,0,n-1,A);
        }
    }
}
