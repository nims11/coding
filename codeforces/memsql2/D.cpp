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
    int type; // take out 1, 2, 3;
    int time;
    evt(int a, int b):type(a),time(b){}
    friend bool operator<(const evt &a, const evt &b){
        if(a.time == b.time)
            return a.type<b.type;
        return a.time>b.time;
    }
};
int main()
{
    int k, n[3], t[3];
    cin>>k>>n[0]>>n[1]>>n[2]>>t[0]>>t[1]>>t[2];
    int free[3] = {n[0], n[1], n[2]};
    int ready[3] = {0};
    priority_queue<evt> simu;
    while(k && free[0]){
        k--;
        free[0]--;
        simu.push(evt(0, t[0]));
    }
    int ans = 0;
    while(k || !simu.empty()){
        evt cur = simu.top();
        //cout<<cur.type<<" "<<cur.time<<endl;
        simu.pop();
        ans = max(ans, cur.time);
        if(cur.type == 2){
            free[2]++;
        }else {
            if(free[cur.type+1]){
                free[cur.type+1]--;
                free[cur.type]++;
                simu.push(evt(cur.type+1, cur.time + t[cur.type+1]));
            }else{
                ready[cur.type]++;
            }
        }
        for(int i = 1;i>=0;i--){
            while(ready[i] && free[i+1]){
                ready[i]--;
                free[i+1]--;
                free[i]++;
                simu.push(evt(i+1, cur.time+t[i+1]));
            }
        }
        while(k && free[0]){
            k--;
            free[0]--;
            simu.push(evt(0, cur.time+t[0]));
        }
    }
    cout<<ans<<endl;
}
