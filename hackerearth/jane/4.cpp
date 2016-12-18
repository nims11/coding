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
pair<long long, long long> dp[2][61];
long long GCD(long long a,long long b)
{
    while(b^=a^=b^=a%=b);
    return a;
}
#define LL long long

pair<LL, LL> mul(pair<LL, LL> a, pair<LL, LL> b){
    pair<LL, LL> res;
    res.first = a.first*b.first;
    res.second = a.second*b.second;
    return res;
}
pair<LL, LL> add(pair<LL, LL> a, pair<LL, LL> b){
    pair<LL, LL> res;
    if(a.second == 0)
        return b;
    if(b.second == 0)
        return a;
    res.second = max(a.second, b.second);
    res.first = a.first*(res.second/a.second) + b.first*(res.second/b.second);
    return res;
}
int main()
{
    int N, K;
    in_I(N);in_I(K);
    dp[0][1] = dp[1][1] = make_pair(1, 2);
    if(K == 1)
        dp[1][1] = make_pair(0, 0);
    dp[0][0] = dp[1][0] = make_pair(1, 1);
    for(int i = 2;i<=N;i++){
        dp[0][i] = dp[1][i] = make_pair(0, 0);
        dp[0][i] = add(dp[0][i-1], dp[1][i-1]);
        dp[0][i].second *= 2;
        for(int j = 1;j<K;j++){
            if(i-j < 0)break;
            dp[1][i] = add(dp[1][i],mul(dp[0][i-j], (make_pair(1LL, 1LL<<j))));
        }
    }
    pair<LL, LL> res = add(dp[1][N], dp[0][N]);
    res.first = res.second-res.first;
    LL xx = GCD(res.first, res.second);
    cout<<(res.first/xx)<<"/"<<(res.second/xx)<<endl;
}
