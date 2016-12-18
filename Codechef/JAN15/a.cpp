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
int trie[500002*20][2], subSize[500002*20][2];
int cnt = 0;
void add(int x){
    int cur = 1;
    for(int i = 18;i>=0;i--){
        int b = (x>>i)&1;
        if(trie[cur][b] == 0){
            trie[cur][b] = ++cnt;
        }
        subSize[cur][b]++;
            cur = trie[cur][b];
    }
}
int getans(int x, int k){
    int cur = 1;
    int ret = 0;
    for(int i = 20;i>=0;i--){
        int b = (x>>i)&1;
        int kb = (k>>i)&1;
        int bb = (b<<1)|kb;
        switch(bb){
            case 0:
            case 2:
                if(trie[cur][b])
                    cur = trie[cur][b];
                else return ret;
                break;
            case 1:
            case 3:
                ret += subSize[cur][b];
                if(trie[cur][!b])
                    cur = trie[cur][!b];
                else return ret;
                break;
        }
    }
    return ret;
}
int main()
{
    in_T{
        cnt = 1;
        for(int i = 1;i<=500000;i++)
            add(i);
        cout<<cnt<<endl;
        int n, x,k;
        in_I(n);
        in_I(k);
        long long res = 0;
        int tmpp = 0;
        memset(subSize, 0, sizeof(subSize));
        memset(trie, 0, sizeof(trie));
        for(int i = 0;i<n;i++){
            in_I(x);
            add(tmpp);
            tmpp ^= x;
            res += getans(tmpp, k);
        }
        printf("%lld\n", res);
    }
}
