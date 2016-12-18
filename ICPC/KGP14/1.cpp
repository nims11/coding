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
vector<pair<double, double> > pts;
bool cmp(pair<double, double> a, pair<double, double> b){
    return a.second<b.second;
}
#define SQR(a) ((a)*(a))
#define DIST(a, b) (sqrt(SQR(a.first-b.first)+SQR(a.second-b.second)))
double INF = 1e18;
double getmin(int st, int end, vector<int> &valid){
    double ret = INF;
    for(int i = st;i<=end;i++){
        for(int j = i+1;j<=end;j++){
            for(int k = j+1;k<=end;k++){
                ret = min(ret, DIST(pts[valid[i]], pts[valid[j]])+
                        DIST(pts[valid[i]], pts[valid[k]])+
                        DIST(pts[valid[j]], pts[valid[k]]));
            }
        }
    }
    return ret;
}
double getans(int st, int end){
    int mid = (st+end)/2;
    if(end-st+1 == 3){
        return DIST(pts[st], pts[end])+
            DIST(pts[st], pts[st+1])+
            DIST(pts[st+1], pts[end]);
    }else if(end-st+1<3)
        return INF;
    double res = min(getans(st, mid), getans(mid+1, end));
    sort(pts.begin()+st, pts.begin()+mid+1, cmp);
    sort(pts.begin()+mid+1, pts.begin()+end, cmp);
    pair<double, double> midpt;
    midpt.first = (pts[mid].first+pts[mid+1].first)/2;
    midpt.second = (pts[mid].second+pts[mid+1].second)/2;

    vector<int> valid;
    for(int i = st;i<=end;i++){
        if(abs(midpt.first-pts[i].first) <= res/2)
            valid.push_back(i);
    }
    int x = 0, y = 0;
double ret = res;
    for(int i = 1;i<valid.size();i++){
        y = i;
        while(x<=y && pts[valid[x]].second < pts[valid[y]].second-res){
            x++;
        }
        ret = min(ret, getmin(x, y, valid));
    }
    return ret;

}
int main()
{
    int z = 0;
    in_T{
        z++;
        printf("Case #%d: ", z);
        int n;
        in_I(n);
        pts.clear();
        double x, y;
        for(int i = 0;i<n;i++){
            scanf("%lf%lf", &x, &y);
            pts.push_back(make_pair(x, y));
        }
        INF = DIST(pts[0], pts[1])+
            DIST(pts[0], pts[2])+
            DIST(pts[1], pts[2]);

        sort(pts.begin(), pts.end());
        printf("%.7lf\n", getans(0, pts.size()-1));
    }
}
