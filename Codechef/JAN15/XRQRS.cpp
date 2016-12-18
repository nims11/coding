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
int trie[50000000][2];
int subSize[50000000][2];
struct nn{
    int kids[2];
};
//int nextFree[40000000];
struct node{
    //Node variables
    int trieRoot;
};
node TREE[ARR_SIZE<<2];
int n,arr[ARR_SIZE];
using namespace std;
int cnt;
void build_segment_tree(int NODE,int a,int b)
{
    if(b-a+1<=16)return;
    TREE[NODE].trieRoot = cnt++;
    if(a==b){
        // Single node condition
        return;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    build_segment_tree(left,a,mid);
    build_segment_tree(right,mid+1,b);

    // Merge Logic for left and right
}
void add(int x, int cur){
    for(int i = 18;i>=0;i--){
        int b = (x>>i)&1;
        if(trie[cur][b] == 0){
            trie[cur][b] = ++cnt;
        }
        assert(cnt<40000000);
        subSize[cur][b]++;
            cur = trie[cur][b];
    }
}
void remove(int x, int cur){
    for(int i = 18;i>=0;i--){
        int b = (x>>i)&1;
        subSize[cur][b]--;
        if(subSize[cur][b] == 0){
            trie[cur][b] = 0;
            return;
        }
        cur = trie[cur][b];
    }
    return;
}
int maxXor(int x, int cur){
    int ret = 0;
    for(int i = 18;i>=0;i--){
        int b = (x>>i)&1;
        if(trie[cur][!b])
            cur = trie[cur][!b], ret = (ret<<1)|(!b);
        else
            cur = trie[cur][b], ret = (ret<<1)|b;
    }
    return ret;
}
int lessThan(int x, int cur){
    int ret = 0;
    for(int i = 18;i>=0;i--){
        int b = (x>>i)&1;
        if(b == 1)
            ret += subSize[cur][0];
        if(trie[cur][b]){
            cur = trie[cur][b];
        }else
            return ret;
    }
    return ret;
}
int getMaxXor(int NODE,int a,int b,int x,int y, int v)
{
    if(x<=a && y>=b){
        if(!TREE[NODE].trieRoot){
            int ret = v^arr[a++];
            while(a<=b){
                ret = max(ret, v^arr[a++]);
            }
            return ret;
        }
        return maxXor(v, TREE[NODE].trieRoot)^v;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(y<=mid)return getMaxXor(left,a,mid,x,y,v);
    if(x>mid)return getMaxXor(right,mid+1,b,x,y,v);

    return max(getMaxXor(left,a,mid,x,y,v), getMaxXor(right,mid+1,b,x,y,v));
}
int getLessThan(int NODE,int a,int b,int x,int y, int v)
{
    if(x<=a && y>=b){
        if(!TREE[NODE].trieRoot){
            int ret = 0;
            while(a<=b)
                ret += (v>arr[a++]);
            return ret;
        }
        return lessThan(v, TREE[NODE].trieRoot);
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(y<=mid)return getLessThan(left,a,mid,x,y,v);
    if(x>mid)return getLessThan(right,mid+1,b,x,y,v);

    return getLessThan(left,a,mid,x,y,v)+getLessThan(right,mid+1,b,x,y,v);
}

void update_segment_tree(int NODE,int a,int b,int x)
{
    if(!TREE[NODE].trieRoot)
        TREE[NODE].trieRoot = cnt++;
    add(arr[x], TREE[NODE].trieRoot);
    if(a==b){
        //Single node logic
        return;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
    if(x<=mid)
    update_segment_tree(left,a,mid,x);
    else
    update_segment_tree(right,mid+1,b,x);

    //Merge left and right nodes
}
void remove_segment_tree(int NODE,int a,int b,int x)
{
    if(TREE[NODE].trieRoot)return;
    remove(arr[x], TREE[NODE].trieRoot);
    if(a==b){
        //Single node logic
        return;
    }
    int mid=(a+b)/2;
    int left=2*NODE,right=2*NODE+1;
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
    in_I(M);
    while(M--){
        in_I(ch);
        if(ch == 0){
            in_I(x);
            if(arr[++n])
                remove_segment_tree(1, 1, N, n);
            arr[n] = x;
            update_segment_tree(1, 1, N, n);
        }else if(ch == 1){
            in_I(L);in_I(R);in_I(x);
            printf("%d\n", getMaxXor(1, 1, N, L, R, x)^x);
        }else if(ch == 2){
            in_I(x);
            n -= x;
        }else if(ch == 3){
            in_I(L);in_I(R);in_I(x);
            printf("%d\n", getLessThan(1, 1, N, L, R, x+1));
        }else if(ch == 4){
            in_I(L);in_I(R);in_I(x);
            st = 1, end = 500001;
            while(st < end){
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
