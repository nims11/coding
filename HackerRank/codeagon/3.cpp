/*
    Nimesh Ghelani (nims11)
*/
#include <bits/stdc++.h>
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
#define BE(a) a.begin(), a.end()

using namespace std;
int main()
{
    string A, B, C;
    cin>>A>>B>>C;
    int dp[101][101][101] ={0};
    assert(A.length()<=100);
    assert(B.length()<=100);
    assert(C.length()<=100);
    for(int i = 1;i<=A.length();i++){
        for(int j = 1;j<=B.length();j++){
            for(int k = 0;k<C.length();k++){
                dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k]);
            }
            if(A[i-1] == B[j-1]){
                for(int k = 0;k<C.length();k++){
                    int foo = (C[k] == A[i-1]?k+1:0);
                    if(foo == C.length() || dp[i-1][j-1][k] < k)continue;
                    dp[i][j][foo] = max(dp[i][j][foo], 1+dp[i-1][j-1][k]);
                }
            }
        }
    }
    int ans = dp[A.length()][B.length()][0];
    for(int i = 1;i<C.length();i++)
        ans = max(ans, dp[A.length()][B.length()][i]);
    cout<<ans<<endl;
}
