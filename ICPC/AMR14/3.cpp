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
char str[300000];
long long dp[300000][501];
inline int sub(int a, int b, int mod){
    int ret = (a-b)%mod;
    if(ret<0)
        ret += mod;
    return ret;
}
int main()
{
    in_S(str);
    int q;
    in_I(q);
    int len = strlen(str);
    while(q--){
        int m, l;
        in_I(m);
        in_I(l);
        vector<int> foo[m];

        for(int i = 0;i<m;i++)
            for(int j = 0;j<len;j++)
            dp[j][i] = 0;
        dp[0][(str[0]-'0')%m] = 1;
        long long res = dp[0][l];
        for(int i = 1;i<len;i++){
            for(int j = 0;j<m;j++){
                int tar = (j*10 + (str[i]-'0'))%m;
                dp[i][tar] += dp[i-1][j];
            }
            dp[i][(str[i]-'0')%m]++;
            res += dp[i][l];
        }

        printf("%lld\n", res);
    }
}
