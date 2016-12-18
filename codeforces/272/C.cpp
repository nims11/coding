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
string S, P;
int subs[2001][501];
int cur[501];
int dp[2001][2001];
int main()
{
    cin>>S>>P;

    for(int i = 1;i<=S.length();i++){
        for(int j = 1;j<=P.length();j++){
            if(S[i-1] == P[j-1]){
                if(j == 1)
                    subs[i][j] = i;
                else
                subs[i][j] = subs[i-1][j-1];
            }else
                subs[i][j] = subs[i-1][j];
        }
    }
    for(int i = 1;i<=S.length(); i++){
            int last = subs[i][P.length()];
            for(int j = 0;j<=S.length();j++)
                dp[i][j] = dp[i-1][j];
            if(last != 0){
                for(int j = i-last+1-int(P.length()), j2 = 0;j2<=last-1;j2++, j++){
                    dp[i][j] = max(dp[i][j], 1+dp[last-1][j2]);
                }
            }
    }
    for(int i = 0;i<=S.length();i++){
        printf("%d ", dp[S.length()][i]);
    }
    newline;
}
