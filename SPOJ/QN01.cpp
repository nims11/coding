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

using namespace std;
int trie[1002*32][2];
int cnt = 0;
map<int, int> foo;
void add(int x){
    int cur = 1;
    for(int i = 30;i>=0;i--){
        int b = (x>>i)&1;
        if(trie[cur][b] == 0){
            trie[cur][b] = ++cnt;
        }
            cur = trie[cur][b];
    }
    assert(cnt < 1002*32);
}
int getans(int x){
    int cur = 1;
    int ret = 0;
    for(int i = 30;i>=0;i--){
        int b = (x>>i)&1;
        if(trie[cur][!b])
            cur = trie[cur][!b], ret = (ret<<1)|(!b);
        else
            cur = trie[cur][b], ret = (ret<<1)|b;
    }
    return ret;
}
int main()
{
    cnt = 1;
    int n, x;
    in_I(n);
    pair<int, int> res = make_pair(-1, 0);
    int ress = -1;
    int tmpp = 0;
    foo[0] = 0;

    int X[n+1];
    X[0] = 0;
    for(int i = 0;i<n;i++){
        in_I(x);
        X[i+1] = X[i]^x;
        add(tmpp);
        tmpp ^= x;
        int tmp = getans(tmpp);
        if(foo.find(tmpp) == foo.end())
            foo[tmpp] = i+1;
        assert(foo.find(tmp) != foo.end());
        if((tmp^tmpp) > ress || ((tmp^tmpp) == ress && foo[tmp]+1 < res.first))
            res = make_pair(foo[tmp]+1, i+1), ress = tmp^tmpp;
    }
    printf("%d\n%d %d\n", ress, res.first, res.second);
}
