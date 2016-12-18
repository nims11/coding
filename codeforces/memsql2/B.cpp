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
double prev = 0;
vector<pair<int, int> > res;
inline double dist(pair<int, int> x, pair<int, int> y){
    return sqrt((x.first-y.first)*(x.first-y.first) + (x.second-y.second)*(x.second-y.second));
}
int n, m;
vector<pair<int, int> > all;
void getans(vector<pair<int, int> > pts){
    if(pts.size() == 4){
        double cur = 0;
        for(int i = 1;i<4;i++)
            cur += dist(pts[i], pts[i-1]);
        if(cur > prev)
            prev = cur, res = pts;
        return;
    }
    for(int i = 0;i<all.size();i++)
            if(find(pts.begin(), pts.end(), all[i]) == pts.end()){
                    pts.push_back(all[i]);
                    getans(pts);
                    pts.pop_back();
            }
}
int main()
{
 cin>>n>>m;
 for(int i = 0;i<=n;i++)
     for(int j = 0;j<=m;j++){
         if( (i == 0 || i == n) && (j == 0 || j == m) ){
             all.push_back(make_pair(i, j));
         }else if( (i == 1 || i == n-1) && (j == 0 || j == m) ){
             all.push_back(make_pair(i, j));
         }else if( (i == 0 || i == n) && (j == 1 || j == m-1) ){
             all.push_back(make_pair(i, j));
         }
     }
 for(int i = 0;i<all.size();i++){
     vector<pair<int, int> > x;
     x.push_back(all[i]);
     getans(x);
 }
    for(int i = 0;i<res.size();i++)
    cout<<res[i].first<<" "<<res[i].second<<endl;
}
