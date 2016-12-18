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
int N, L;
struct Point{
    int x, y, c;
}points[100010];

#define ARR_SIZE 100010
struct node{
    //Node variables
    long long val;
    long long carry;
};
node TREE[ARR_SIZE<<2];
int n = 100000;
using namespace std;
void build_segment_tree(int NODE,int a,int b){
    if(a==b){
        // Single node condition
        TREE[NODE].val = 0;
        TREE[NODE].carry = 0;
        return;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    build_segment_tree(left,a,mid);
    build_segment_tree(right,mid+1,b);

    // Merge Logic for left and right
    TREE[NODE].val = max(TREE[left].val, TREE[right].val);
    TREE[NODE].carry = 0;
}
void lazy_propogate(int NODE, int a, int b){
    int mid = (a+b)/2;
    long long carry =  TREE[NODE].carry;
    // TREE[NODE].val += carry;
    TREE[NODE].carry = 0;
    if(a != b){
        int left = 2*NODE, right = 2*NODE+1;
        TREE[left].carry += carry;
        TREE[right].carry += carry;
        TREE[left].val += carry;
        TREE[right].val += carry;
    }
}
long long query_segment_tree(int NODE,int a,int b,int x,int y){
    if(TREE[NODE].carry){
        lazy_propogate(NODE, a, b);
    }
    if(x<=a && y>=b)return TREE[NODE].val;
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(y<=mid)return query_segment_tree(left,a,mid,x,y);
    if(x>mid)return query_segment_tree(right,mid+1,b,x,y);

    long long left_query=query_segment_tree(left,a,mid,x,y);
    long long right_query=query_segment_tree(right,mid+1,b,x,y);

    // Merge left_query and right_query into ans
    return max(left_query, right_query);
}
void update_segment_tree(int NODE,int a,int b,int l, int r, long long val){
    if(TREE[NODE].carry){
        lazy_propogate(NODE, a, b);
    }
    if(l <= a && b <= r){
        TREE[NODE].carry += val;
        TREE[NODE].val += val;
        return;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(l <= mid) update_segment_tree(left,a,mid,l, r, val);
    if(r > mid) update_segment_tree(right,mid+1,b,l, r, val);

    //Merge left and right nodes
    TREE[NODE].val = max(TREE[left].val, TREE[right].val);
}

long long getBeauty(int sideLength){
    long long S = 0;
    build_segment_tree(1, 1, n);
    int beginPtr = 1, endPtr = 1;
    while(endPtr <= N){
        int l = points[endPtr].y;
        int r = min(n, points[endPtr].y+sideLength-1);
        update_segment_tree(1, 1, n, l, r, points[endPtr].c);
        S = max(S, query_segment_tree(1, 1, n, 1, n));

        endPtr++;
        if(endPtr > N)break;
        while(points[beginPtr].x + sideLength - 1 < points[endPtr].x){
            // delete point at beginPtr
            int l = points[beginPtr].y;
            int r = min(n, points[beginPtr].y+sideLength-1);
            update_segment_tree(1, 1, n, l, r, -points[beginPtr].c);
            beginPtr++;
        }
    }
    return S;
}
int main(){
    in_I(N);in_I(L);
    for(int i = 1;i<=N;i++){
        in_I(points[i].x);
        in_I(points[i].y);
        in_I(points[i].c);
    }
    sort(points+1, points+N+1, [](const Point &p1, const Point &p2) -> bool {return p1.x < p2.x;});
    long long S = getBeauty(L);
    int st = 1, end = L;
    while(st < end){
        int mid = (st + end)/2;
        if(getBeauty(mid) == S){
            end = mid;
        }else
            st = mid+1;
    }
    printf("%lld %d\n", S, end);
}
