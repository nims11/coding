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

int main(){
    int z, t;
    cin>>t;
    for(z=1;z<=t;z++){
        int J,P,S,K;
        cin>>J>>P>>S>>K;
        vector<pair<int, pair<int, int>>> soln;
        for(int i = 0;i<J;i++){
            for(int j = 0;j<P;j++){
                for(int k = 0;k<S;k++)
                    soln.push_back({i, {j, k}});
            }
        }
        int best_res = 0;
        int best_res_x = 0;
        for(int i = 0;i<(1<<soln.size());i++){
            int jp[3][3] = {0}, ps[3][3] = {0}, js[3][3] = {0};
            int cur_res_x = 0;
            if(__builtin_popcount(i) <= best_res_x)
                continue;
            for(int j = 0;j<soln.size();j++){
                if(i&(1<<j)){
                    cur_res_x++;
                    pair<int, pair<int, int>> &x = soln[j];
                    int jj = x.first, pp = x.second.first, ss = x.second.second;
                    jp[jj][pp]++;
                    ps[pp][ss]++;
                    js[jj][ss]++;
                    if(jp[jj][pp] > K || ps[pp][ss] > K || js[jj][ss] > K){
                        cur_res_x = -1;
                        break;
                    }
                }
            }
            if(cur_res_x > best_res_x)
                best_res = i, best_res_x = cur_res_x;
        }
        cout<<"Case #"<<z<<": "<<best_res_x<<endl;
        for(int j = 0;j<soln.size();j++){
            if(best_res&(1<<j)){
                pair<int, pair<int, int>> &x = soln[j];
                int jj = x.first, pp = x.second.first, ss = x.second.second;
                cout<<jj+1<<" "<<pp+1<<" "<<ss+1<<endl;
            }
        }
    }
}
