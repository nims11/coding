#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)

#define ARR_SIZE 100010
int TREE[ARR_SIZE<<2];
int n,arr[ARR_SIZE];
using namespace std;
void build_segment_tree(int NODE,int a,int b){
    if(a==b){
        TREE[NODE] = arr[a];
        return;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    build_segment_tree(left,a,mid);
    build_segment_tree(right,mid+1,b);

    // Merge Logic for left and right
    TREE[NODE] = min(TREE[left], TREE[right]);
}
int query_segment_tree(int NODE,int a,int b,int x,int y){
    if(x<=a && y>=b)return TREE[NODE];
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(y<=mid)return query_segment_tree(left,a,mid,x,y);
    if(x>mid)return query_segment_tree(right,mid+1,b,x,y);

    int left_query=query_segment_tree(left,a,mid,x,y);
    int right_query=query_segment_tree(right,mid+1,b,x,y);

    return min(left_query, right_query);
}
void update_segment_tree(int NODE,int a,int b,int x){
    if(a==b){
        TREE[NODE] = arr[a];
        return;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(x<=mid) update_segment_tree(left,a,mid,x);
    else update_segment_tree(right,mid+1,b,x);

    //Merge left and right nodes
    TREE[NODE] = min(TREE[left], TREE[right]);
}
set<int> store[32];
int main(){
    int N, Q;
    in_I(N);
    in_I(Q);
    for(int i = 1;i<=N;i++){
        in_I(arr[i]);
        for(int j = 0;j<32;j++){
            if(arr[i]&(1<<j))
                store[j].insert(i);
        }
    }
    build_segment_tree(1, 1, N);
    while(Q--){
        int t, l, r;
        in_I(t);
        in_I(l);
        in_I(r);
        if(t == 0){
            printf("%d\n", query_segment_tree(1, 1, N, l, r));
        }else{
            int x;
            in_I(x);
            for(int i = 0;i<32;i++){
                if(!(x&(1<<i))){
                    auto it = store[i].lower_bound(l);
                    while(it != store[i].end() && *it <= r){
                        arr[*it] &= ~(1<<i);
                        update_segment_tree(1, 1, N, *it);
                        store[i].erase(it++);
                    }
                }
            }
        }
    }
}
