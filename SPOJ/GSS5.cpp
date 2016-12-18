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
#include<cstring>
#include<cstdlib>
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

#include<cassert>

using namespace std;
int n, A[10002];
int aux[10002][16];
int aux2[10002][16];
int LOG2[10002];
int RMQ(int x, int y)
{
    int k = LOG2[y-x+1];
    return min(aux[x][k], aux[y-(1<<k)+1][k]);
}
int RMQ2(int x, int y)
{
    int k = LOG2[y-x+1];
    return max(aux2[x][k], aux2[y-(1<<k)+1][k]);
}
struct node
{
    int sum,max_l,max_r,max;
};
node TREE[50000];
void build_segment_tree(int NODE,int a,int b)
{

    if(a==b)
    {
        TREE[NODE].sum=TREE[NODE].max_l=TREE[NODE].max_r=TREE[NODE].max=A[a];
        return;
    }
    int mid=(a+b)/2;
    build_segment_tree(2*NODE,a,mid);
    build_segment_tree(2*NODE+1,mid+1,b);

    int left=2*NODE,right=2*NODE+1;
    TREE[NODE].sum=TREE[left].sum+TREE[right].sum;
    TREE[NODE].max_l=max(TREE[left].max_l,TREE[left].sum+TREE[right].max_l);
    TREE[NODE].max_r=max(TREE[right].max_r,TREE[right].sum+TREE[left].max_r);
    TREE[NODE].max=max(max(TREE[left].max,TREE[right].max),TREE[left].max_r+TREE[right].max_l);
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
    ans.sum=left_query.sum+right_query.sum;
    ans.max_l=max(left_query.max_l,left_query.sum+right_query.max_l);
    ans.max_r=max(right_query.max_r,right_query.sum+left_query.max_r);
    ans.max=max(max(left_query.max,right_query.max),left_query.max_r+right_query.max_l);
    return ans;
}
int main()
{
    int x = 0;
    int x1, x2, y1, y2;
    for(int i=0;i<10002;i++)
    {
        if(1<<x <= i)
            x++;
        LOG2[i] = x-1;
    }
    in_T
    {
        in_I(n);
        for(int i=1;i<=n;i++)
            in_I(A[i]);
        A[0] = 0;
        build_segment_tree(1, 0, n);
        for(int i=1;i<=n;i++)
            A[i] += A[i-1];
        for(int i=0;i<=n;i++)
            aux[i][0] = aux2[i][0] = A[i];
        for(int j=1;(1<<j)<=n+1;j++)
        {
            for(int i=0;i+(1<<j)<=n+1;i++)
                aux[i][j] = min(aux[i][j-1], aux[i+(1<<(j-1))][j-1]),
                aux2[i][j] = max(aux2[i][j-1], aux2[i+(1<<(j-1))][j-1]);
        }
        int m;
        in_I(m);
        while(m--)
        {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if(y1<x2)
            {
                x1--, y1--;
                printf("%d\n", RMQ2(x2, y2) - RMQ(x1, y1));
            }else
            {
                int res = max(RMQ2(x2, y2) - RMQ(x1-1, x2-1), RMQ2(y1, y2) - RMQ(x1-1, y1-1));
                res = max(res, query_segment_tree(1, 0, n, x2, y1).max);
                printf("%d\n", res);
            }
//            cout<<mini<<" "<<maxi<<endl;
        }
    }
}
