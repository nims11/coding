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
#define BE(a) a.begin(), a.end()

using namespace std;
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)
int n, k, a;
int sz[200010];
int main()
{
    in_I(n);in_I(a);in_I(k);
    int m;
    in_I(m);
    int curTot = (n+1)/(k+1);
    set<int> state;
    state.insert(n);
    sz[n] = n;
    int res = -1;
    for(int i = 0;i<m;i++){
        int x;
        in_I(x);
        set<int>::iterator it = state.lower_bound(x);
        int curSz = sz[*it];
        curTot -= (curSz+1)/(k+1);
        int stIdx = (*it) - curSz + 1;
        int sz1 = x - stIdx, sz2 = (*it) - x;
        // cout<<curSz<<" "<<sz1<<" "<<sz2<<endl;
        curTot += (sz1+1)/(k+1) + (sz2+1)/(k+1);
        // cout<<curTot<<endl;
        int endIdx = *it;

        state.erase(it);
        if(sz1 > 0){
            sz[x-1] = sz1;
            state.insert(x-1);
        }
        if(sz2 > 0){
            sz[endIdx] = sz2;
            state.insert(endIdx);
        }
        if(curTot < a && res == -1)
            res = i+1;
    }
    cout<<res<<endl;
}
