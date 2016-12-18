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
struct node{
    long long left[3], right[3], total[3];
    long long totMod;
};
node TREE[ARR_SIZE<<2];
int n,arr[ARR_SIZE];
using namespace std;
void build_segment_tree(int NODE,int a,int b)
{
    if(a==b){
        TREE[NODE].left[arr[a]%3]++;
        TREE[NODE].right[arr[a]%3]++;
        TREE[NODE].total[arr[a]%3]++;
        TREE[NODE].totMod = arr[a]%3;
        return;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    build_segment_tree(left,a,mid);
    build_segment_tree(right,mid+1,b);

    // Merge Logic for left and right
    TREE[NODE].totMod = (TREE[left].totMod + TREE[right].totMod)%3;
    for(int i = 0;i<3;i++){
        TREE[NODE].left[i] = TREE[left].left[i];
        TREE[NODE].right[i] = TREE[right].right[i];
        TREE[NODE].total[i] = TREE[left].total[i] + TREE[right].total[i];
    }
    for(int i = 0;i<3;i++){
        TREE[NODE].left[(TREE[left].totMod+i)%3] += TREE[right].left[i];
        TREE[NODE].right[(TREE[right].totMod+i)%3] += TREE[left].right[i];
    }
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            TREE[NODE].total[(i+j)%3] += TREE[left].right[i]*TREE[right].left[j];
        }
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
    // Merge left_query and right_query into ans
    ans.totMod = (left_query.totMod + right_query.totMod)%3;
    for(int i = 0;i<3;i++){
        ans.left[i] = left_query.left[i];
        ans.right[i] = right_query.right[i];
        ans.total[i] = left_query.total[i] + right_query.total[i];
    }
    for(int i = 0;i<3;i++){
        ans.left[(left_query.totMod+i)%3] += right_query.left[i];
        ans.right[(right_query.totMod+i)%3] += left_query.right[i];
    }
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            ans.total[(i+j)%3] += left_query.right[i]*right_query.left[j];
        }
    }

    return ans;
}
void update_segment_tree(int NODE,int a,int b,int x)
{
    if(a==b){
        //Single node logic
        for(int i = 0;i<3;i++)
                TREE[NODE].left[i] = TREE[NODE].right[i] = TREE[NODE].total[i] = 0;
        TREE[NODE].left[arr[a]%3]++;
        TREE[NODE].right[arr[a]%3]++;
        TREE[NODE].total[arr[a]%3]++;
        TREE[NODE].totMod = arr[a]%3;
        return;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(x<=mid)
    update_segment_tree(left,a,mid,x);
    else
    update_segment_tree(right,mid+1,b,x);

    //Merge left and right nodes
    TREE[NODE].totMod = (TREE[left].totMod + TREE[right].totMod)%3;
    for(int i = 0;i<3;i++){
        TREE[NODE].left[i] = TREE[left].left[i];
        TREE[NODE].right[i] = TREE[right].right[i];
        TREE[NODE].total[i] = TREE[left].total[i] + TREE[right].total[i];
    }
    for(int i = 0;i<3;i++){
        TREE[NODE].left[(TREE[left].totMod+i)%3] += TREE[right].left[i];
        TREE[NODE].right[(TREE[right].totMod+i)%3] += TREE[left].right[i];
    }
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            TREE[NODE].total[(i+j)%3] += TREE[left].right[i]*TREE[right].left[j];
        }
    }

}
char str[100010];
int main()
{
    int n, m, q, l, r;
    in_I(n);
    in_I(m);
    in_S(str);
    for(int i = 0;str[i];i++)
        arr[i+1] = str[i]-'0';
    build_segment_tree(1, 1, n);
    while(m--){
        in_I(q);in_I(l);in_I(r);
        if(q == 1){
            arr[l] = r;
            update_segment_tree(1, 1, n, l);
        }else{
            printf("%lld\n", query_segment_tree(1, 1, n, l, r).total[0]);
        }
    }
}
