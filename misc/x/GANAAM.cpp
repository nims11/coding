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
    int time;
    int type; // 0-in, 1 - out
    int id;
    friend bool operator<(const evt &a, const evt &b){
        if(a.time == b.time)
            return a.type<b.type;
        return a.time<b.time;
    }
    evt(int a, int b,  int c): time(a), type(b), id(c){}
};
int main()
{
    in_T{
        int N,X;
        in_I(N);in_I(X);
        vector<evt> evts;
        vector<int> grps[N];
        vector<vector<int> > ppl;
        for(int i = 0;i<N;i++){
            int S, E;
            in_I(S);in_I(E);
            evts.push_back(evt(S, 0, i));
            evts.push_back(evt(E, 1, i));
        }
        sort(evts.begin(), evts.end());
        set<int> cur;
        set<int>::iterator it;
        int cnt = 0;
        for(int i = 0;i<evts.size();i++){
            int x = evts[i].time;
            while(i<evts.size() && evts[i].time == x && evts[i].type == 0){
                cur.insert(evts[i].id);
                i++;
            }
            if(cur.size() >= X){
                ppl.push_back(vector<int> ());
                for(it = cur.begin(); it != cur.end(); it++)
                    grps[*it].push_back(cnt), ppl[cnt].push_back(*it);
                cnt++;
            }
            while(i<evts.size() && evts[i].time == x && evts[i].type == 1){
                cur.erase(evts[i].id);
                i++;
            }
        }
        int quota[cnt];
        for(int i = 0;i<cnt;i++){
            quota[i] = ppl[i].size()-X+1;
        }
        for(int i = 0;i<)
    }
}
