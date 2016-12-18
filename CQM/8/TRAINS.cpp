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
struct evt{
    int T, type;    // 0 - ready, 1 - arrive, 2 - depart
    int place;
    evt(int a, int b, int c):T(a), type(b), place(c){}
    friend bool operator<(const evt &a, const evt &b){
        if(a.T != b.T){
            return a.T > b.T;
        }
        return a.type > b.type;
    }
};
int main()
{
    in_T{
        int A,B,C, x, y;
        in_I(C);
        in_I(A);in_I(B);
        priority_queue<evt> evts;
        for(int i = 0;i<A;i++){
            scanf("%d:%d", &x, &y);
            evts.push(evt(x*60+y, 2, 0));
            scanf("%d:%d", &x, &y);
            evts.push(evt(x*60+y, 1, 1));
        }
        for(int i = 0;i<B;i++){
            scanf("%d:%d", &x, &y);
            evts.push(evt(x*60+y, 2, 1));
            scanf("%d:%d", &x, &y);
            evts.push(evt(x*60+y, 1, 0));
        }
        int cnt[2] = {0};
        int res[2] = {0};
        while(!evts.empty()){
            evt cur = evts.top();
//            cout<<cur.T<<" "<<cur.type<<" "<<cur.place<<endl;
            evts.pop();
            if(cur.type == 0){
                cnt[cur.place]++;
            }else if(cur.type == 1){
                evts.push(evt(cur.T+C, 0, cur.place));
            }else if(cur.type == 2){
                if(cnt[cur.place] == 0)
                    res[cur.place]++;
                else
                    cnt[cur.place]--;
            }
        }
        printf("%d %d\n", res[0], res[1]);
    }
}
