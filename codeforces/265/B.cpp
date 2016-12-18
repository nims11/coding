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
#define SQR(a) (a)*(a)
using namespace std;
long long pts[8][3];
long long dot(int i, int i1, int i2){
    return (pts[i][0]-pts[i1][0])*(pts[i][0]-pts[i2][0]) + 
        (pts[i][1]-pts[i1][1])*(pts[i][1]-pts[i2][1]) +
        (pts[i][2]-pts[i1][2])*(pts[i][2]-pts[i2][2]);
}
inline long long dist(int i, int j){
    return SQR(pts[i][0]-pts[j][0])+SQR(pts[i][1]-pts[j][1])+SQR(pts[i][2]-pts[j][2]);
}
bool isCube(int foo){
    vector<pair<long long, int> > lens;
    for(int i = 0;i<8;i++){
        if(i != foo)
        lens.push_back(make_pair(dist(i, foo), i));
    }
    sort(lens.begin(), lens.end());
    long long dist = lens[0].first,
         diagFace = lens[3].first,
         diagBody = lens[6].first;
    if(dist == 0)
        return false;
    if(!(lens[0].first == lens[1].first && lens[1].first == lens[2].first)
            || !(lens[3].first == lens[4].first && lens[4].first == lens[5].first))
        return false;
    if(diagFace != 2*dist||diagBody != 3*dist)return false;
    if(dot(foo, lens[0].second, lens[1].second) != 0 || 
            dot(foo, lens[1].second, lens[2].second) != 0 ||
            dot(foo, lens[0].second, lens[2].second ) != 0)
        return false;
    if(dot(lens[6].second, lens[3].second, lens[4].second) != 0 || 
            dot(lens[6].second, lens[4].second, lens[5].second) != 0 ||
            dot(lens[6].second, lens[3].second, lens[5].second ) != 0)
        return false;

    if(dot(lens[6].second, lens[3].second, lens[4].second) != 0 || 
            dot(lens[6].second, lens[4].second, lens[5].second) != 0 ||
            dot(lens[6].second, lens[3].second, lens[5].second ) != 0)
        return false;

}
void getans(int idx){
    if(idx == 8){
        if(isCube(0) && isCube(1) && isCube(2)){
            printf("YES\n");
            for(int i = 0;i<8;i++){
                printf("%lld %lld %lld\n", pts[i][0], pts[i][1], pts[i][2]);
            }
            exit(0);
        }
        return;
    }
    int i = idx;
    getans(idx+1);
    swap(pts[i][0], pts[i][1]);

    getans(idx+1);
    swap(pts[i][1], pts[i][2]);

    getans(idx+1);
    swap(pts[i][0], pts[i][1]);

    getans(idx+1);
    swap(pts[i][1], pts[i][2]);

    getans(idx+1);
    swap(pts[i][0], pts[i][1]);

    getans(idx+1);
}
int main()
{
    for(int i = 0;i<8;i++){
        in_L(pts[i][0]);
        in_L(pts[i][1]);
        in_L(pts[i][2]);
    }
    getans(1);
    printf("NO\n");
}
