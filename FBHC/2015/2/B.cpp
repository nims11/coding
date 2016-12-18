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
double p;
double powerP[21][2];
const int maxX = 100000;
double dp[maxX][21];
int tot = 20;
double C[21][21];
double getans(int t, int left){
    if(t == 0 && left)
        return 0;
    if(t == 0)
        return 1;
    if(dp[t][left] >= -0.1)
        return dp[t][left];
    double &ans = dp[t][left];
    ans = 0;
    for(int i = (left == tot);i<=left;i++){
        ans = ans + C[left][i]*(powerP[i][0] * powerP[tot-left][1] * getans(t-1, left-i));
//        cout<<t<<" "<<left<<" "<<i<<" "<<(powerP[i][0] * powerP[tot-left][1] * getans(t-1, left-i))<<endl;
    }
    return ans;
}
int main()
{
    for(int i = 0;i<=20;i++)
        C[i][0] = C[i][i] = 1;
    for(int i = 1;i<=20;i++){
        for(int j = 1;j<i;j++)
            C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
    int z = 0;
    in_T{
        z++;
        printf("Case #%d: ", z);
        cin>>p;
        powerP[0][0] = powerP[0][1] = 1;
        for(int i = 1;i<=20;i++)
            powerP[i][0] = powerP[i-1][0] * p,
                powerP[i][1] = powerP[i-1][1] * (1-p);

        for(int i = 0;i<maxX;i++)
            for(int j = 0;j<=20;j++)
                dp[i][j] = -1;
        double ans = 0;
//        printf("%.30lf\n", getans(2, 2));
//        return 0;
        for(int i = 1;i<maxX;i++)
            ans += getans(i, tot)*i;
        printf("%.5lf\n", ans);
    }
}
