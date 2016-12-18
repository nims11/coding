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

int N;
vector<int> reachDp[16][5];
int markDp[16][5];
vector<int> zo[2][16];
int max_rnd = 4;
set<int> x[16];
void reach(int x, int rnd){
    if(markDp[x][rnd] != -1)
        return;
    markDp[x][rnd] = 1;
    reach(x, rnd-1);
    for(int y: zo[1][x]){
        reach(y, rnd-1);
        for(int i: reachDp[y][rnd-1]){
            for(int j: reachDp[x][rnd-1]){
                if((i&j) == 0){
                    if(rnd == max_rnd-1){
                        if(::x[x].count((i|j)))
                            continue;
                        ::x[x].insert((i|j));
                    }
                    reachDp[x][rnd].push_back((i|j));
                    if(rnd == max_rnd)
                        return;
                }
            }
        }
    }
}
int main(){
    int z = 0;
    for(int i = 0;i<16;i++){
        reachDp[i][0].push_back(1<<i);
        markDp[i][0] = 1;
    }
    in_T{
        in_I(N);
        int ans[N][2];
        for(int i = 0;i<16;i++)
            x[i].clear();
        for(int i = 0;i<N;i++)
            ans[i][0] = 100, ans[i][1] = -1;
        for(int i = 0;i<16;i++)
            for(int j = 1;j<5;j++)
                reachDp[i][j].clear(), markDp[i][j] = -1;
        for(int i = 0;i<2;i++)
            for(int j = 0;j<16;j++)
                zo[i][j].clear();
        for(int i = 0;i<N;i++)
            for(int j = 0;j<N;j++){
                int x;
                in_I(x);
                if(i != j){
                    zo[x][i].push_back(j);
                }
            }
        int lt = 0;
        // if(N == 16)
        //     lt++;
        for(int rnd=1,rem=N/2;rem>lt;rnd++,rem/=2){
            // cout<<rnd<<","<<rem<<": ";
            for(int i = 0;i<N;i++){
                if(markDp[i][rnd] == -1){
                    reach(i, rnd);
                }
                // cout<<reachDp[i][rnd].size()<<" ";
            }
            // cout<<endl;
        }
        // if(N == 16){
        //     for(int i = 0;i<16;i++){
        //         if(zo[1][i].size() == 15){
        //             reachDp[i][max_rnd].push_back(1);
        //             goto nx;
        //         }
        //     }
        //     for(int i = 0;i<16;i++){
        //         if(zo[1][i].size() > 7)
        //             reachDp[i][max_rnd].push_back(1);
        //     }
        // }
nx:
        for(int rnd=0,rem=N;rem>0;rnd++,rem/=2){
            for(int i = 0;i<N;i++){
                int flag = false;
                for(int maskX: reachDp[i][rnd]){
                    if(rem == 1){
                        ans[i][0] = min(ans[i][0], 1);
                        ans[i][1] = max(ans[i][1], 1);
                        break;
                    }
                    for(int y: zo[0][i]){
                        for(int maskY: reachDp[y][rnd]){
                            if((maskY&maskX) == 0){
                                flag = true;
                                ans[i][0] = min(ans[i][0], rem/2+1);
                                ans[i][1] = max(ans[i][1], rem/2+1);
                            }
                            if(flag)
                                break;
                        }
                        if(flag)
                            break;
                    }
                    if(flag)
                        break;
                }
            }
        }
        cout<<"Case #"<<(++z)<<":"<<endl;
        for(int i = 0;i<N;i++){
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
        }
    }
}
