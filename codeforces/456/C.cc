#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

const int INF = INT_MAX;
using namespace std;
long long max_h[100010], cur_h[100010], regen[100010];
set<int> sets[2];
int bounty, inc, dmg;
int n, m;
long long cur_t;
map<int, long long> last_removal;

long long get_bounty(){
    return (long long)sets[0].size() * (bounty + inc * 1LL *cur_t);
}
inline long long divide(long long a, long long b){
    return (a/b) + (a%b!=0);
}

struct event {
    int type; //-1 -> check, 0 -> remove, 1 -> update
    long long time;
    int hero;
    long long health;

    friend bool operator<(const event &a, const event &b){
        if(a.time != b.time)
            return a.time > b.time;
        return a.type < b.type;
    }
};

int main(){
    in_I(n); in_I(m); in_I(bounty); in_I(inc);in_I(dmg);

    for(int i = 0;i < n; i++){
        in_L(max_h[i]); in_L(cur_h[i]); in_L(regen[i]);
    }

    priority_queue<event> events;
    for(int i = 0; i < m; i++){
        int t, e, h;
        in_I(t); in_I(e); in_I(h);
        events.push({1, (long long)t, e-1 ,h});
        events.push({-1, (long long)t-1, e-1 ,h});
        events.push({-1, (long long)t, e-1 ,h});
    }
    for(int i = 0; i < n; i++){
        if(cur_h[i] <= dmg){
            sets[0].insert(i);
            if(regen[i] != 0 && dmg < max_h[i]){
                long long removal_time = divide(dmg + 1 - cur_h[i], regen[i]);
                events.push({0, removal_time, i, dmg+1});
                events.push({-1, removal_time-1, i, dmg+1});
                events.push({-1, removal_time, i, dmg+1});
                last_removal[i] = removal_time;
            }
        }else
            sets[1].insert(i);
    }
    long long ans = get_bounty();
    while(!events.empty()){
        auto evt = events.top();
        events.pop();
        if(evt.type == 0){
            if(last_removal[evt.hero] != evt.time)
                continue;
        }

        if(evt.type == -1){
            cur_t = evt.time;
            ans = max(ans, get_bounty());
            continue;
        }

        cur_h[evt.hero] = evt.health;
        int e = evt.hero;
        long long health = evt.health;
        if(health <= dmg){
            sets[0].insert(e);
            sets[1].erase(e);
            if(regen[e] != 0 && dmg < max_h[e]){
                long long removal_time = evt.time + divide(dmg + 1 - cur_h[e], regen[e]);
                events.push({0, removal_time, e, dmg+1});
                last_removal[e] = removal_time;
                events.push({-1, removal_time-1, 2, dmg+1});
                events.push({-1, removal_time, 2, dmg+1});
            }
        }else{
            sets[1].insert(e);
            sets[0].erase(e);
            last_removal[e] = -1;
        }
    }

    if(inc > 0)
    for(int e: sets[0]){
        if(regen[e] == 0 || dmg >= max_h[e]){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
}
