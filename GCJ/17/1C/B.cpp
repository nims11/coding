#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;
const int mod = 24* 60;

struct Act{
    int type;
    int st, end;
};
bool cmp(const Act &a, const Act &b){
    return a.st < b.st;
}
int main(){
    int z = 0;
    in_T{
        int Ac, Aj;
        in_I(Ac);in_I(Aj);
        vector<Act> activities;
        int flags[24*60];
        memset(flags, -1, sizeof(flags));

        for(int i = 0;i<Ac;i++){
            int st, end;
            in_I(st);in_I(end);
            activities.push_back({0, st % mod, end % mod});
        }

        for(int i = 0;i<Aj;i++){
            int st, end;
            in_I(st);in_I(end);
            activities.push_back({1, st % mod, end % mod});
        }

        sort(BE(activities), cmp);

        for(Act &a: activities){
            for(int i = a.st; ; i++){
                i %= mod;
                if(i == a.end){
                    break;
                }
                flags[i] = a.type;
            }
        }

        vector<int> empty_segments[3];
        int rem[2] = {mod/2, mod/2};
        for(int i = 0;i<mod;i++){
            if(flags[i] != -1)
                rem[flags[i]]--;
        }

        int ans = 0;
        for(int i = 0;i<activities.size();i++){
            int st = activities[i].end;
            int end = activities[(i+1)%activities.size()].st;
            int len = (end - st);
            if(end < st){
                len = mod - st + end;
            }
            if(activities[i].type != activities[(i+1)%activities.size()].type){
                ans++;
                empty_segments[2].push_back(len);
            }else{
                empty_segments[activities[i].type].push_back(len);
            }
        }
        for(int i = 0;i<3;i++){
            sort(BE(empty_segments[i]));
        }
        for(int x=0;x<2;x++)
            {
                for(int i = 0;i<empty_segments[x].size();i++){
                    int removable = min(rem[x], empty_segments[x][i]);
                    empty_segments[x][i] -= removable;
                    rem[x] -= removable;
                }

                for(int i = 0;i<empty_segments[2].size();i++){
                    int removable = min(rem[x], empty_segments[2][i]);
                    empty_segments[2][i] -= removable;
                    rem[x] -= removable;
                }
            }

        for(int x = 0;x<2;x++){
            if(rem[x]){
                for(int i = 0;i<empty_segments[!x].size();i++){
                    int removable = min(rem[x], empty_segments[!x][i]);
                    empty_segments[!x][i] -= removable;
                    rem[x] -= removable;
                    if(removable)
                        ans += 2;
                }
            }
        }
        cout<<"Case #"<<(++z)<<": "<<ans<<endl;
    }
}
