/*
    Nimesh Ghelani (nims11)
*/
#include <bits/stdc++.h>
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
pair<int, int> rects[100010];
struct compL{
    bool operator() (const int &a, const int &b){
        if(rects[a].first != rects[b].first)
            return rects[a].first<rects[b].first;
        return a<b;
    }
};
struct compR{
    bool operator() (const int &a, const int &b){
        if(rects[a].second != rects[b].second)
            return rects[a].second<rects[b].second;
        return a<b;
    }
};

int main()
{
    in_T{
        int N, M;
        in_I(N);in_I(M);
        for(int i = 0;i<N;i++){
            in_I(rects[i].first);
            in_I(rects[i].second);
        }
        set<int, compL> curH;
        set<int, compR> curV;
        for(int i = 0;i<N;i++)
            curH.insert(i), curV.insert(i);
        set<int> curRem;
        if(M == N)
            M--;
        set<int, compL>::iterator curHPtr;
        set<int, compR>::iterator curVPtr;
        curHPtr = curH.begin();
        curVPtr = curV.begin();
        set<int> VSkipped;
        for(int i = 0;i<M;i++){
            curV.erase(*(curHPtr));
            ++curHPtr;
        }
        long long res = rects[*curV.begin()].second*1LL*rects[*curHPtr].first;
        for(int i = 1;i<=M;i++){
            --curHPtr;
            curV.insert(*curHPtr);
            int toRem = *curV.begin();
            if(toRem == *curHPtr){
                if(curHPtr == curH.begin()){
                    curH.erase(toRem);
                    curHPtr = curH.begin();
                }else{
                    --curHPtr;
                    curH.erase(toRem);
                }
            }
            curV.erase(curV.begin());
            res = max(res, rects[*curV.begin()].second*1LL*rects[*curHPtr].first);
        }
        printf("%lld\n", res);
    }
}
