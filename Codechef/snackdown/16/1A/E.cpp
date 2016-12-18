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
pair<int, int> segments[100010];
int endArray[1000010];
int nxt[1000100][20];
int main(){
    int N, Q;
    in_I(N);in_I(Q);
    int max_end = 0;
    for(int i = 0;i<N;i++){
        in_I(segments[i].first);
        in_I(segments[i].second);
        max_end = max(max_end, segments[i].second);
    }
    sort(segments, segments+N);
    for(int i = 0;i<N;i++)
        endArray[segments[i].second]++;
    int curIdx = 0;
    int nextEnd = 0;
    for(int i = 0;i<=1000000;){
        while(curIdx < N && segments[curIdx].first <= i){
            endArray[segments[curIdx].second]--;
            curIdx++;
        }
        if(curIdx == N)
            break;
        if(nextEnd < i)
            nextEnd = i;
        while(endArray[nextEnd] == 0)
            nextEnd++;
        nxt[i++][0] = nextEnd;
    }
    for(int i = 1;i<20;i++){
        for(int j = 0;j<=max_end;j++){
            if(nxt[j][i-1] != 0)
                nxt[j][i] = nxt[nxt[j][i-1]][i-1];
        }
    }
    // for(int i = 0;i<=6;i++){
    //     for(int j = 0;j<=3;j++)
    //         cout<<nxt[i][j]<<" ";
    //     cout<<endl;
    // }
    // cout<<endl;

    while(Q--){
        int l, r;
        in_I(l);in_I(r);
        int ans = 0;
        l--;
        for(int i = 19;i>=0;i--){
            if(nxt[l][i] != 0 && nxt[l][i] <= r){
                ans += (1<<i);
                l = nxt[l][i];
            }
        }
        printf("%d\n", ans);
    }
}
