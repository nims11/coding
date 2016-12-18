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
struct order{
    int S, X, D, P;
};
order orders[300];
struct evt{
    int time;
    int type; // 0 - end, 1 - start
    int id;
    friend bool operator<(const evt &a, const evt &b){
        if(a.time == b.time)
            return a.type<b.type;
        return a.time < b.time;
    }
    evt(int a, int b, int c): time(a), type(b), id(c){}
};
struct job{
    int id;
    friend bool operator<(const job &a, const job &b){
        return orders[a.id].P < orders[b.id].P;
    }
    job(int x):id(x){}
};
int main()
{
    in_T{
        int n;
        in_I(n);
        vector<evt> evts;
        for(int i = 0;i<n;i++){
            in_I(orders[i].S);in_I(orders[i].X);in_I(orders[i].D);in_I(orders[i].P);
            evts.push_back(evt(orders[i].S, 1, i));
            evts.push_back(evt(orders[i].D, 0, i));
        }
        sort(evts.begin(), evts.end());
        int cur = evts[0].time;
        priority_queue<job> jobs;
        jobs.push(job(evts[0].id));
        for(int i = 1;i<evts.size();i++){
            int nxt = evts[i].time;
            if(evts[i].type == 1)
                jobs.push(job(evts[i].id));
            int jb = -1;
            while(!jobs.empty()){
                int id = jobs.top().id;
                jobs.pop();
                if(cur >= orders[id].D || orders[id].X == 0)
                    continue;
                else{
                    jb = id;break;
                }
            }
            if(jb != -1){
                int x = min(orders[jb].X, nxt-cur);
                orders[jb].X -= x;
                if(orders[jb].X)
                    jobs.push(job(jb));
            }
            cur = nxt;
        }
        long long ans = 0;
        for(int i = 0;i<n;i++){
            ans += 1LL*orders[i].X*orders[i].P;
        }
        cout<<ans<<endl;
    }
}
