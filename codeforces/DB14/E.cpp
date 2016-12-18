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
int n;
struct line{
    int x, l;
    int block;
}lines[200010];
struct query {
    int id;
    int L, R;
}queries[200010];
int ans[200010];
int tmp[200010];
bool cmp1(const query &a, const query &b){
    if(lines[a.L].block == lines[b.L].block)
        return a.R<b.R;
    return lines[a.L].block < lines[b.L].block;
}
int main()
{
    in_I(n);
    int blockSize = sqrt(n);
    for(int i = 1;i<=n;i++){
        in_I(lines[i].x);
        in_I(lines[i].l);
        lines[i].block = (i-1)/blockSize;
    }
    int q;
    in_I(q);
    for(int i = 0;i<q;i++){
        in_I(queries[i].L);
        in_I(queries[i].R);
        queries[i].id = i;
    }
    sort(queries, queries+q, cmp1);
    int curL = 1, curR = 1;
    int curRes = 0;
    int last = -1;
    for(int i = 0;i<q;i++){
        while(curR < queries[i].R){
            int diff = lines[curR+1].x - (lines[curR].x+lines[curR].l);
            if(diff && last != -1 && lines[last]
            curRes += max(0, diff);
            curR++;
        }
        while(curR > queries[i].R){
            int diff = lines[curR].x - (lines[curR-1].x+lines[curR-1].l);
            curRes -= max(0, diff);
            curR--;
        }
        while(curL < queries[i].L){
            int diff = lines[curL+1].x - (lines[curL].x+lines[curL].l);
            curRes -= max(0, diff);
            curL++;
        }
        while(curL > queries[i].L){
            int diff = lines[curL].x - (lines[curL-1].x+lines[curL-1].l);
            curRes += max(0, diff);
            curL--;
        }
        ans[queries[i].id] = curRes;
    }
    for(int i = 0;i<q;i++)
        printf("%d\n", ans[i]);
}
