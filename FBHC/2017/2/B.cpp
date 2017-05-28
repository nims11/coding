#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;

const long long INF = 1e14;
template <class T>
class POINT{
    public:
    long long P[2];
    POINT(){}
    POINT(long long x, long long y){P[0] = x, P[1] = y;}
    //dot
    long long operator*(const POINT &a){
        return a.P[0]*this->P[0] + a.P[1]*this->P[1];
    }
    POINT operator-(const POINT &b){
        return POINT(this->P[0] - b.P[0], this->P[1] - b.P[1]);
    }
    //cross
    long long operator^(const POINT &b){
        return this->P[0]*b.P[1] - this->P[1]*b.P[0];
    }
};
int ccw(POINT<int> a, POINT<int> b, POINT<int> c)
{
    long long foo = ((b-a)^(c-a));
    return foo > 0?1:(foo<0?-1:0);
}
double getarea(POINT<int> p1, POINT<int> p2){
    if(p1.P[0] + p1.P[1] <= p2.P[0] && p2.P[0] - p2.P[1] >= p1.P[0]){
        double ret = 0.5 * p1.P[1] * p1.P[1] + \
            0.5 * p2.P[1] * p2.P[1];
        long long hyp = p1.P[0] + p1.P[1] - (p2.P[0] - p2.P[1]);
        if(hyp > 0){
            ret -= hyp * hyp / 4.0;
        }
        return ret;
    }else{
        double inter_x = (p1.P[1] + p1.P[0] - p2.P[1] + p2.P[0]) / 2.0;
        double inter_y = (p1.P[1] + p1.P[0] + p2.P[1] - p2.P[0]) / 2.0;
        double ret = 0.5 * (p1.P[1] + inter_y) * (inter_x - p1.P[0]) + \
                     0.5 * (inter_y + p2.P[1]) * (p2.P[0] - inter_x);

        return ret;
    }
}
int main(){
   int z = 0;
   int t;
   cin>>t;
   while(t--){
       z++;
       long long N, X1, AX, BX, CX, H1, AH, BH, CH;
       cin>>N>>X1>>AX>>BX>>CX>>H1>>AH>>BH>>CH;
       set<pair<long long, long long>> peaks;
       peaks.insert({-INF, 0});
       peaks.insert({INF, 0});
       double cur_area = 0;
       double res = 0;
       while(N--){
           auto it = peaks.lower_bound({X1, 0});
           POINT<int> nextpt(it->first, it->second);
           POINT<int> prevpt(prev(it)->first, prev(it)->second);
           POINT<int> curpt(X1, H1);
               /* cout<<curpt.P[0]<<" "<<curpt.P[1]<<","<<prevpt.P[0]<<" "<<prevpt.P[1]<<","<<nextpt.P[0]<<" "<<nextpt.P[1]<<endl; */
           if(curpt.P[1] > min(prevpt.P[1], nextpt.P[1]) || (abs(prevpt.P[1] - curpt.P[1]) < abs(prevpt.P[0] - curpt.P[0]) && abs(nextpt.P[1] - curpt.P[1]) < abs(nextpt.P[0] - curpt.P[0]))){
               cur_area -= getarea(prevpt, nextpt);
               vector<pair<long long, long long>> to_rem;
               for(auto it2 = it; it2 != peaks.end();it2++){
                   if(abs(H1 - it2->second) >= abs(X1 - it2->first) && H1 > it2->second){
                       to_rem.push_back(*it2);
                       cur_area -= getarea(POINT<int>(it2->first, it2->second), POINT<int>(next(it2)->first, next(it2)->second));
                   }else
                       break;
               }
               for(auto it2 = prev(it); it2 != peaks.begin();it2--){
                   if(abs(H1 - it2->second) >= abs(X1 - it2->first) && H1 > it2->second){
                       to_rem.push_back(*it2);
                       cur_area -= getarea(POINT<int>(prev(it2)->first, prev(it2)->second), POINT<int>(it2->first, it2->second));
                   }else
                       break;
               }
               for(auto xx: to_rem)
                   peaks.erase(xx);
               it = peaks.insert({X1, H1}).first;
               curpt = POINT<int> (it->first, it->second);
               prevpt = POINT<int> (prev(it)->first, prev(it)->second);
               nextpt = POINT<int> (next(it)->first, next(it)->second);
               cur_area += getarea(prevpt, curpt);
               cur_area += getarea(curpt, nextpt);
           }
           res += cur_area;
           X1 = ((AX * X1 + BX) % CX) + 1;
           H1 = ((AH * H1 + BH) % CH) + 1;
       }
       printf("Case #%d: %.8lf\n", z, res);
    }
}
