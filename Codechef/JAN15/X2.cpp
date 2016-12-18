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
#include<cassert>
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
#define BE(a) a.begin(), a.end()

using namespace std;

#define ARR_SIZE 500010
struct nn{
    nn* kids[2];
    int sz[2];
};
inline nn* newNode(){
    nn* ret = (nn*)(malloc(sizeof(nn)));
    ret->kids[0] = ret->kids[1] = 0;
    ret->sz[0] = ret->sz[1] = 0;
    return ret;
}
inline void freeAll(nn* x){
    if(x == 0)return;
    freeAll(x->kids[0]);
    freeAll(x->kids[1]);
    free(x);
}
//int nextFree[40000000];
nn *TREE[ARR_SIZE<<2];
int n,arr[ARR_SIZE];
using namespace std;
int cnt;
int inI(int &a)
{
    int x=0;
    register int c=getchar_unlocked();
    for(; c>47 && c<58 ; c = getchar_unlocked())
    {
        x = (x<<1) + (x<<3) + c - 48;

    }
    a=x;

}

void build_segment_tree(int NODE,int a,int b)
{
    if(b-a+1<=64)return;
    TREE[NODE] = newNode();
    if(a==b){
        // Single node condition
        return;
    }
    int mid=(a+b)/2;
    int left=NODE<<1,right=(NODE<<1)+1;
    build_segment_tree(left,a,mid);
    build_segment_tree(right,mid+1,b);

    // Merge Logic for left and right
}
void add(int x, nn *cur){
    for(int i = 18;i>=0;i--){
        int b = (x>>i)&1;
        if(cur->kids[b] == 0){
            cur->kids[b] = newNode();
        }
        cur->sz[b]++;
        cur = cur->kids[b];
    }
}
void remove(int x, nn *cur){
    for(int i = 18;i>=0;i--){
        int b = (x>>i)&1;
        cur->sz[b]--;
        if(cur->sz[b] == 0){
            freeAll(cur->kids[b]);
            cur->kids[b] = 0;
            return;
        }
        cur = cur->kids[b];
    }
    return;
}
int maxXor(int x, nn* cur){
    int ret = 0;
    for(int i = 18;i>=0;i--){
        int b = (x>>i)&1;
        if(cur->kids[!b])
            cur = cur->kids[!b], ret = (ret<<1)|(!b);
        else
            cur = cur->kids[b], ret = (ret<<1)|b;
    }
    return ret;
}
int lessThan(int x, nn* cur){
    int ret = 0;
    for(int i = 18;i>=0;i--){
        int b = (x>>i)&1;
        if(b == 1)
            ret += cur->sz[0];
        if(cur->kids[b]){
            cur = cur->kids[b];
        }else
            return ret;
    }
    return ret;
}
int getMaxXor(int NODE,int a,int b,int x,int y, int v)
{
    if(x<=a && y>=b){
        if(!TREE[NODE]){
            int ret = arr[a++]^v;
            while(a<=b){
                ret = max(ret, arr[a]^v);
                a++;
            }
            return ret;
        }
        return maxXor(v, TREE[NODE])^v;
    }
    int mid=(a+b)/2;
    int left=(NODE<<1),right=(NODE<<1)+1;
    if(y<=mid)return getMaxXor(left,a,mid,x,y,v);
    if(x>mid)return getMaxXor(right,mid+1,b,x,y,v);

    return max(getMaxXor(left,a,mid,x,y,v), getMaxXor(right,mid+1,b,x,y,v));
}
int getLessThan(int NODE,int a,int b,int x,int y, int v)
{
    if(x<=a && y>=b){
        if(!TREE[NODE]){
            int ret = 0;
            while(a<=b){
                ret += (arr[a]<v);
                a++;
            }
            return ret;
        }
        return lessThan(v, TREE[NODE]);
    }
    int mid=(a+b)/2;
    int left=(NODE<<1),right=(NODE<<1)+1;
    if(y<=mid)return getLessThan(left,a,mid,x,y,v);
    if(x>mid)return getLessThan(right,mid+1,b,x,y,v);

    return getLessThan(left,a,mid,x,y,v)+getLessThan(right,mid+1,b,x,y,v);
}

void update_segment_tree(int NODE,int a,int b,int x)
{
    if(!TREE[NODE])return;
    add(arr[x], TREE[NODE]);
    if(a==b){
        //Single node logic
        return;
    }
    int mid=(a+b)/2;
    int left=(NODE<<1),right=(NODE<<1)+1;
    if(x<=mid)
        update_segment_tree(left,a,mid,x);
    else
        update_segment_tree(right,mid+1,b,x);

    //Merge left and right nodes
}
void remove_segment_tree(int NODE,int a,int b,int x)
{
    if(!TREE[NODE])return;
    remove(arr[x], TREE[NODE]);
    if(a==b){
        //Single node logic
        return;
    }
    int mid=(a+b)/2;
    int left=(NODE<<1),right=(NODE<<1)+1;
    if(x<=mid)
        remove_segment_tree(left,a,mid,x);
    else
        remove_segment_tree(right,mid+1,b,x);

    //Merge left and right nodes
}

int main()
{
    int M, N=500000, ch, x, L, R, st, end, mid;
    n = 0;
    cnt = 1;
    build_segment_tree(1, 1, N);
    inI(M);
    while(M--){
        inI(ch);
        if(ch == 0){
            inI(x);
            if(arr[++n])
                remove_segment_tree(1, 1, N, n);
            arr[n] = x;
            update_segment_tree(1, 1, N, n);
        }else if(ch == 1){
            inI(L);inI(R);inI(x);
            printf("%d\n", getMaxXor(1, 1, N, L, R, x)^x);
        }else if(ch == 2){
            inI(x);
            n -= x;
        }else if(ch == 3){
            inI(L);inI(R);inI(x);
            printf("%d\n", getLessThan(1, 1, N, L, R, x+1));
        }else if(ch == 4){
            inI(L);inI(R);inI(x);
            st = 1, end = 500001;
            int cnt = 0;
            while(st < end){
                cnt++;
                if(cnt == 100)return 100;
                mid = (st+end+1)/2;
                ch = getLessThan(1, 1, N, L, R, mid);
                if(ch >= x){
                    end = mid-1;
                }else {
                    st = mid;
                }
            }
            printf("%d\n", st);
        }
    }
}
