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
double dp[101][201][1001];
double nxtFlt()
{
    int a,b;
    scanf("%d.%d", &a, &b);
    return (a*1000+b)/1000.0;
}
int main()
{
    int z = 0;
    in_T
    {
        z++;
        int K;
        in_I(K);
        double Ps, Pr, Pi, Pu, Pw, Pd, Pl;
        Ps = nxtFlt();
        Pr = nxtFlt();
        Pi = nxtFlt();
        Pu = nxtFlt();
        Pw = nxtFlt();
        Pd = nxtFlt();
        Pl = nxtFlt();
        int T = 2*K-1;
        for(int i = 0;i<=K;i++)
            for(int j = 0; j<=T; j++)
                for(int k = 0;k<=1000;k++)
                    dp[i][j][k] = 0;

        dp[0][0][int(Pi*1000)] = 1;
        for(int j = 0; j<T;j++)
            for(int i = 0;i<K;i++)
                for(int k = 0; k<=1000; k++)
            {
                double Pi = k/1000.0;
                double Pwin = (Ps*Pi + Pr*(1-Pi));

                // win +
                dp[i+1][j+1][min(1000, k+int(Pu*1000))] += dp[i][j][k]*Pwin*Pw;

                // win same
                dp[i+1][j+1][k] += dp[i][j][k]*Pwin*(1-Pw);

                // lose -
                dp[i][j+1][max(0, k-int(Pd*1000))] += dp[i][j][k]*(1-Pwin)*Pl;

                // lose same
                dp[i][j+1][k] += dp[i][j][k]*(1-Pwin)*(1-Pl);
            }

        double res = 0;
        for(int i = 0;i<=T;i++)
        for(int j = 0; j<=1000;j++)
            res += dp[K][i][j];
        printf("Case #%d: %.6lf\n", z, res);
    }
}
