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
    long long N;int C;
    cin>>N>>C;
    long long dp[20][3][300] = {0};
    vector<int> digits;
    while(N){
        digits.push_back(N%10);
        N/=10;
    }
    reverse(BE(digits));
    dp[0][0][0] = 1;
    for(int i = 1;i<=digits.size();i++){
        for(int j = 0;j<3;j++){
            for(int k = (i==1?1:0);k<=9;k++){
                int cost = abs(k-digits[i-1]);
                int cur = (j+k)%3;
                for(int l = cost;l<=C;l++)
                    dp[i][cur][l] += dp[i-1][j][l-cost];
            }
        }
    }
    long long ans = 0;
    for(int i = 0;i<=C;i++)
        ans += dp[digits.size()][0][i];
    cout<<ans<<endl;
}
