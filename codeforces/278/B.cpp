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

#define ARR_SIZE 200000
struct node{
    //Node variables
};
int TREE[ARR_SIZE<<2];
using namespace std;
void build_segment_tree(int NODE,int a,int b)
{
    if(a==b){
        TREE[NODE] = 1e9;
        return;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    build_segment_tree(left,a,mid);
    build_segment_tree(right,mid+1,b);

    // Merge Logic for left and right
    TREE[NODE] = min(TREE[left], TREE[right]);
}
int query_segment_tree(int NODE,int a,int b,int x,int y)
{
    if(x<=a && y>=b)return TREE[NODE];
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(y<=mid)return query_segment_tree(left,a,mid,x,y);
    if(x>mid)return query_segment_tree(right,mid+1,b,x,y);

    int left_query=query_segment_tree(left,a,mid,x,y);
    int right_query=query_segment_tree(right,mid+1,b,x,y);

    int ans = min(left_query, right_query);
    // Merge left_query and right_query into ans
    return ans;
}
void update_segment_tree(int NODE,int a,int b,int x, int y)
{
    if(a==b){
        //Single node logic
        TREE[NODE] = y;
        return;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(x<=mid)
    update_segment_tree(left,a,mid,x, y);
    else
    update_segment_tree(right,mid+1,b,x, y);

    //Merge left and right nodes
    TREE[NODE] = min(TREE[left], TREE[right]);
}
int arr[100001];
int n;
int aux[100002][22];
int aux2[100002][22];
int LOG2[100002];
int RMQ_min(int x, int y){
    int k = LOG2[y-x+1];
    return min(aux[x][k], aux[y-(1<<k)+1][k]);
}
int RMQ_max(int x, int y){
    int k = LOG2[y-x+1];
    return max(aux2[x][k], aux2[y-(1<<k)+1][k]);
}

void init(){
    int curr = 2;
    LOG2[1] = 0;
    for(int i = 2; i<=100001;i++){
        if(i == curr){
            curr <<= 1;
            LOG2[i] = LOG2[i-1] + 1;
        }else
            LOG2[i] = LOG2[i-1];
    }

    for(int i=1;i<=n;i++)
        aux[i][0] = aux2[i][0] = arr[i];
    for(int j=1; (1<<j)<=n+1; j++)
        for(int i=1;i+(1<<j)<=n+1;i++)
            aux[i][j] = min(aux[i][j-1], aux[i+(1<<(j-1))][j-1]),
            aux2[i][j] = max(aux2[i][j-1], aux2[i+(1<<(j-1))][j-1]);
}
int main()
{
    int s, l;
    in_I(n);in_I(s);in_I(l);
    build_segment_tree(1, 1, n+1);
    update_segment_tree(1, 1, n+1, 1, 0);
    for(int i = 1;i<=n;i++)
        in_I(arr[i]);
    init();
    for(int i = 1;i<=n;i++){
        int st = 1, end = i;
        while(st < end){
            int mid = (st + end)/2;
            int mini = RMQ_min(mid, i), maxi = RMQ_max(mid, i);
            if(maxi-mini > s)
                st = mid+1;
            else
                end = mid;
        }
        if(i-st+1 >= l){
            int left = st, right = i-l+1;
            int res = query_segment_tree(1, 1, n+1, left, right);
            if(res != 1e9)
                update_segment_tree(1, 1, n+1, i+1, ++res);
        }
    }
    int ans = query_segment_tree(1, 1, n+1, n+1, n+1);
    if(ans == 1e9)
        printf("-1\n");
    else
        printf("%d\n", ans);
}
