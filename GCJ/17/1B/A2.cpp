#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;

double get_position(pair<int, int> horse, double time){
    return horse.first + horse.second*time;
}

double eps = 1e-9;
int D,N;
bool slower(pair<long long, long long> horse, pair<long long, long long> horse2){
    return ((D-horse.first) * horse2.second > (D-horse2.first) * horse.second);
}
int main(){
    int z = 0;
    in_T{
        in_I(D);in_I(N);
        vector<pair<long long, long long>> horses;
        /* if(z == 26)cout<<D<<" "<<N<<endl; */
        for(int i = 0;i<N;i++){
            int k, s;
            in_I(k);
            in_I(s);
        /* if(z == 26)cout<<k<<" "<<s<<endl; */
            horses.push_back({k, s});
        }
        sort(horses.begin(), horses.end());
        reverse(horses.begin(), horses.end());
        pair<long long, long long> slowest = {-1, -1};
        for(auto horse: horses){
            if(slowest.first == -1){
                slowest = horse;
            }else{
                if(slower(horse, slowest)){
                    slowest = horse;
                }
            }
        }
        printf("Case #%d: %.7lf\n", ++z, D/(double(D-slowest.first)/slowest.second));
    }
}
