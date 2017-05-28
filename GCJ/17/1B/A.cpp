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

int main(){
    int z = 0;
    in_T{
        int D,N;
        in_I(D);in_I(N);
        vector<pair<int, int>> horses;
        for(int i = 0;i<N;i++){
            int k, s;
            in_I(k);
            in_I(s);
            horses.push_back({k, s});
        }
        sort(horses.begin(), horses.end());
        map<double, double> intercepts;
        reverse(horses.begin(), horses.end());
        for(auto horse: horses){
            auto it2 = intercepts.begin();
            bool intersects = false;
            for(auto it = intercepts.begin(); it != intercepts.end(); it++){
                if(it->second < get_position(horse, it->first)){
                    intersects = true;
                    double m = (it->second - it2->second) / double(it->first - it2->first);
                    double x = double((it2->second) - m*(it2->first) - horse.first)/(horse.second - m);
                    double y = get_position(horse, x);
                    for(auto it3 = intercepts.begin(); it3 != intercepts.end();){
                        if(it3->first <= x){
                            it3 = intercepts.erase(it3);
                        }else break;
                    }
                    intercepts[0] = horse.first;
                    intercepts[x] = y;
                }
                it2 = it;
            }
            if(!intersects){
                intercepts[0] = horse.first;
                intercepts[double(D-horse.first)/horse.second] = D;
            }
        }
        double total_time = 0;
        auto it2 = intercepts.end();
        it2--;
        printf("Case #%d: %.7lf\n", ++z, D/(it2->first));
    }
}
