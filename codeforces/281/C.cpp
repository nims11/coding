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
vector<int> dist1, dist2;
pair<long long, long long> ans = make_pair(-1, -1);
void compute(int d){
    d = max(0, d);
    long long sB = 0, sA = 0;
    int  nA = int(dist1.end() - upper_bound(dist1.begin(), dist1.end(), d));
    sA = nA*3 + (dist1.size()-nA)*2;
    int  nB = int(dist2.end() - upper_bound(dist2.begin(), dist2.end(), d));
    sB = nB*3 + (dist2.size()-nB)*2;

    if(ans.first == -1){
        ans = make_pair(sA, sB);
    }else if(ans.first - ans.second < sA - sB || (ans.first - ans.second == sA - sB && ans.first < sA))
        ans = make_pair(sA, sB);
}
int main()
{
    int n1, n2, x;
    in_I(n1);
    for(int i = 0;i<n1;i++){
        in_I(x);
        dist1.push_back(x);
    }
    in_I(n2);
    for(int i = 0;i<n2;i++){
        in_I(x);
        dist2.push_back(x);
    }
    sort(dist1.begin(), dist1.end());
    sort(dist2.begin(), dist2.end());
    for(int i = 0;i<dist1.size();i++){
        compute(dist1[i]);
        compute(dist1[i]-1);
        compute(dist1[i]+1);
    }
    for(int i = 0;i<dist2.size();i++){
        compute(dist2[i]);
        compute(dist2[i]-1);
        compute(dist2[i]+1);
    }
    printf("%lld:%lld\n", ans.first, ans.second);
}
