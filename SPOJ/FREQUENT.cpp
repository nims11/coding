
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
	int max[3][2];
};
node TREE[1000000];
int n,arr[110000];
using namespace std;
void build_segment_tree(int NODE,int a,int b)
{
    if(a==b)
    {
        TREE[NODE].max[0][0]=TREE[NODE].max[1][0]=TREE[NODE].max[2][0]=arr[a];
	TREE[NODE].max[0][1]=TREE[NODE].max[1][1]=TREE[NODE].max[2][1]=1;
        return;
    }
    int mid=(a+b)/2;
    build_segment_tree(2*NODE,a,mid);
    build_segment_tree(2*NODE+1,mid+1,b);

    int left=2*NODE,right=2*NODE+1;
    TREE[NODE].max[1][0]=TREE[right].max[1][0];
    TREE[NODE].max[1][1]=TREE[right].max[1][1] + (TREE[left].max[1][0] == TREE[right].max[1][0]? TREE[left].max[1][1]: 0);

    TREE[NODE].max[2][0]=TREE[left].max[2][0];
    TREE[NODE].max[2][1]=TREE[left].max[2][1] + (TREE[right].max[2][0] == TREE[left].max[2][0]? TREE[right].max[2][1]: 0);

    int L = TREE[left].max[0][1] + (TREE[right].max[2][0] == TREE[left].max[0][0]? TREE[right].max[2][1]:0);
    int R = TREE[right].max[0][1] + (TREE[left].max[1][0] == TREE[right].max[0][0]?TREE[left].max[1][1]:0);
    if(L>R)
    {
        TREE[NODE].max[0][0] = TREE[left].max[0][0];
        TREE[NODE].max[0][1] = L;
    }else
    {
        TREE[NODE].max[0][0] = TREE[right].max[0][0];
        TREE[NODE].max[0][1] = R;
    }
    int M = (TREE[left].max[1][0] == TREE[right].max[2][0]?TREE[left].max[1][1]+TREE[right].max[2][1]:0);
    if(M>TREE[NODE].max[0][1])
    {
        TREE[NODE].max[0][0] = TREE[right].max[2][0];
        TREE[NODE].max[0][1] = M;
    }
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
    ans.max[1][0]=right_query.max[1][0];
    ans.max[1][1]=right_query.max[1][1] + (left_query.max[1][0] == right_query.max[1][0]? left_query.max[1][1]: 0);

    ans.max[2][0]=left_query.max[2][0];
    ans.max[2][1]=left_query.max[2][1] + (right_query.max[2][0] == left_query.max[2][0]? right_query.max[2][1]: 0);

    int L = left_query.max[0][1] + (right_query.max[2][0] == left_query.max[0][0]? right_query.max[2][1]:0);
    int R = right_query.max[0][1] + (left_query.max[1][0] == right_query.max[0][0]?left_query.max[1][1]:0);
    if(L>R)
    {
        ans.max[0][0] = left_query.max[0][0];
        ans.max[0][1] = L;
    }else
    {
        ans.max[0][0] = right_query.max[0][0];
        ans.max[0][1] = R;
    }
    int M = (left_query.max[1][0] == right_query.max[2][0]?left_query.max[1][1]+right_query.max[2][1]:0);
    if(M>ans.max[0][1])
    {
        ans.max[0][0] = right_query.max[2][0];
        ans.max[0][1] = M;
    }
    return ans;
}
void traverse(int NODE,int a,int b)
{
    cout<<a<<" "<<b<<"="<<TREE[NODE].max[0][0]<<" "<<TREE[NODE].max[0][1]<<" "<<TREE[NODE].max[1][0]<<" "<<TREE[NODE].max[1][1]<<" "<<TREE[NODE].max[2][0]<<" "<<TREE[NODE].max[2][1]<<endl;
    if(a==b)return;
    traverse(2*NODE,a,(a+b)/2);
    traverse(2*NODE+1,(a+b)/2+1,b);
}
int main()
{
    while(1)
    {
        int n,q;
        in_I(n);if(n==0)return 0;
        in_I(q);
        for(int i=0;i<n;i++)
        in_I(arr[i]);
        build_segment_tree(1,0,n-1);
//        traverse(1,0,n-1);
        while(q--)
        {
            int a,b;
            in_I(a);in_I(b);
            printf("%d\n",query_segment_tree(1,0,n-1,a-1,b-1).max[0][1]);
        }
    }
}
