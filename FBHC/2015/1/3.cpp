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
long long dp1[2001][2001], dp2[2001][2001];
const int mod = 1000000007;
int main()
{
    int z = 0;
    dp1[0][0] = 1;
    for(int i = 1;i<=2000;i++){
        for(int j = 0;j<i;j++){
            dp1[i][j] = (dp1[i-1][j] + dp1[i][j-1])%mod;
        }
    }
    dp2[0][0] = 1;
    for(int i = 0;i<=2000;i++){
        for(int j = 0;j<=2000;j++){
            if(i == 0 && j == 0)continue;
            if(i>0){
                dp2[i][j] += dp2[i-1][j];
            }
            if(i<j && j != 0){
                dp2[i][j] += dp2[i][j-1];
            }
            dp2[i][j] %= mod;
        }
    }
    in_T{
        z++;
        cout<<"Case #"<<z<<": ";
        int A, B;
        scanf("%d-%d", &A, &B);
        cout<<dp1[A][B]<<" "<<dp2[A][B]<<endl;
    }
}
