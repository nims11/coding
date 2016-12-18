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
const int mod = 1000000007;
int dp[2][5010];
int main()
{
    int n, a, b, k;
    in_I(n);in_I(a);in_I(b);in_I(k);
    for(int i = 1;i<=n;i++){
        if(abs(i-a) < abs(a-b) && i != b && i != a)
            dp[0][i] = 1;

        dp[0][i] += dp[0][i-1];
    }
    int res = dp[0][n];
    for(int i = 1;i<k;i++){

            int f = i&1;
        for(int j = 1;j<=n;j++){
            if(j != b){
//                cout<<j<<endl;
                int st1, st2, end1, end2;
                if(j<b){
                    st1 = 1, end1 = j-1;
                    st2 = j+1, end2 = (b+j-1)/2;
                }else{
                    st1 = j+1, end1 = n;
                    st2 = (b+j)/2+1, end2 = j-1;
                }
//                cout<<st1<<" "<<end1<<" "<<st2<<" "<<end2<<endl;
                dp[f][j] = 0;
                if(st1<=end1){
                    int add = dp[!f][end1]-dp[!f][st1-1];
                    add%=mod;
                    if(add < 0)
                        add += mod;
                    dp[f][j] = (dp[f][j] + add)%mod;
                }
                if(st2<=end2){
                    int add = dp[!f][end2] - dp[!f][st2-1];
                    add %= mod;
                    if(add < 0)
                        add += mod;
                    dp[f][j] = (dp[f][j] + add)%mod;
                }
//                cout<<dp[f][j]<<endl;
            }else
                dp[f][j] = 0;
            dp[f][j] = (dp[f][j] + dp[f][j-1])%mod;
        }
        if(i == k-1)
            res = dp[f][n];
    }
    printf("%d\n", res);
}
