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
const int MAXN = 100010;
int n,q;
struct line{
    int x1, x2, y1, y2, idx;
    double inline getY(int x) const{
        return (y2==y1?0:((x-x1)*1LL*(y2-y1)/double(x2-x1))) + y1;
    }
    friend bool operator<(const line &a, const line &b);
}lines[MAXN*2];
struct evt{
    int key, type, idx;
}evts[3*MAXN];
int curX;
bool operator<(const line &a, const line &b){
    return a.getY(curX) > b.getY(curX);
}
int evtCnt = 0;
set<line> store;
int ansTree[2*MAXN];
int ans[2*MAXN];
int getans(int idx){
    if(ansTree[idx] == -1)
        return ans[idx];
    ans[idx] = getans(ansTree[idx]);
    ansTree[idx] = -1;
    return ans[idx];
}
int main(){
    in_I(n);
    in_I(q);
    for(int i = 0;i<n;i++){
        in_I(lines[i].x1);
        in_I(lines[i].y1);
        in_I(lines[i].x2);
        in_I(lines[i].y2);
        lines[i].idx = i;
        if(lines[i].x1 > lines[i].x2){
            swap(lines[i].x1, lines[i].x2);
            swap(lines[i].y1, lines[i].y2);
        }
        evts[evtCnt].key = lines[i].x1;
        evts[evtCnt].type = 1;
        evts[evtCnt++].idx = i;
        evts[evtCnt].key = lines[i].x2;
        evts[evtCnt].type = 3;
        evts[evtCnt++].idx = i;
    }
    for(int i = 0;i<q;i++){
        in_I(lines[i+n].x1);
        in_I(lines[i+n].y1);
        lines[i+n].x2 = lines[i+n].x1;
        lines[i+n].y2 = lines[i+n].y1;
        lines[i+n].idx = i+n;
        evts[evtCnt].key = lines[i+n].x1;
        evts[evtCnt].type = 2;
        evts[evtCnt++].idx = i+n;
    }
    sort(evts, evts+evtCnt, [](const evt &a, const evt &b) -> bool
        {
            if(a.key != b.key)
                return a.key < b.key;
            return a.type < b.type;
        }
    );
    for(int i = 0;i<evtCnt;i++){
        evt &e = evts[i];
        curX = e.key;
        if(e.type == 1){
            auto it = store.insert(lines[e.idx]).first;
            if(lines[e.idx].y1 < lines[e.idx].y2){
                it = std::next(it);
                if(it == store.end()){
                    ansTree[e.idx] = -1;
                    ans[e.idx] = lines[e.idx].x1;
                }
                else
                    ansTree[e.idx] = it->idx;
            }
        } else if(e.type == 3){
            auto it = store.find(lines[e.idx]);
            if(lines[e.idx].y1 > lines[e.idx].y2){
                it = std::next(it);
                if(it == store.end()){
                    ansTree[e.idx] = -1;
                    ans[e.idx] = lines[e.idx].x2;
                }
                else
                    ansTree[e.idx] = it->idx;
            }
            store.erase(lines[e.idx]);
        } else{
            auto it = store.lower_bound(lines[e.idx]);
            if(it == store.end())
                ansTree[e.idx] = -1, ans[e.idx] = lines[e.idx].x1;
            else
                ansTree[e.idx] = it->idx;
        }
    }
    for(int i = n;i<n+q;i++){
        printf("%d\n", getans(i));
    }
}
