#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;
int N, K, M;
vector<pair<int, int>> sneks[2];
int main(){
    in_T{
        in_I(N);
        in_I(K);
        in_I(M);
        sneks[0].clear();
        sneks[1].clear();
        int boundary[] = {(N-K)/2 + 1, (N-K)/2 + K};
        int hx, hy, tx, ty;
        for(int i = 0;i<M;i++){
            in_I(hx); in_I(hy); in_I(tx); in_I(ty);
            pair<int, int> snek[2] = {{min(hy, ty), max(hy, ty)}, {min(hx, tx), max(hx, tx)}};
            for(int j = 0;j<2;j++){
                if(!(snek[j].second < boundary[0] || snek[j].first > boundary[1])){
                    snek[j].first = max(snek[j].first, boundary[0]);
                    snek[j].second = min(snek[j].second, boundary[1]);
                    sneks[j].push_back(snek[j]);
                }
            }
        }
        int ans = 0;
        sort(sneks[0].begin(), sneks[0].end());
        sort(sneks[1].begin(), sneks[1].end());

        bool impossible = false;
        for(int j = 0;!impossible && j<2;j++){
            multiset<int> buffer;
            int covered = boundary[0]-1;
            int idx = 0;
            while(idx < (int)sneks[j].size()){
                auto &snek = sneks[j][idx];
                while(!buffer.empty() && *buffer.begin() < snek.first){
                    int idx_ = *buffer.begin();
                    if(idx_ > covered){
                        covered = *buffer.rbegin();
                        ans++;
                    }
                    buffer.erase(buffer.begin());
                }
                if(covered < snek.first - 1){
                    if(buffer.size() == 0){
                        impossible = true;
                        break;
                    }else{
                        covered = *buffer.rbegin();
                        ans++;
                    }
                }

                while(idx < (int)sneks[j].size() && sneks[j][idx].first == snek.first){
                    buffer.insert(sneks[j][idx].second);
                    idx++;
                }
                if(snek.first > covered){
                    covered = *buffer.rbegin();
                    ans++;
                }
            }
            if(covered < boundary[1]){
                if(buffer.empty() || *buffer.rbegin() < boundary[1]){
                    impossible = true;
                }else
                    ans++;
            }
        }

        printf("%d\n", impossible?-1:ans);
    }
}
