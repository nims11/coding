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
#define BE(a) a.begin(), a.end()

using namespace std;
int L[25][50], P[25][50];
int dpL[25][125002], dpP[25][125002];
int main()
{
    for(int i = 0;i<25;i++)
        for(int j = 0;j<125002;j++)
            dpL[i][j] = dpP[i][j] = 1e9;
    int n, l, p;
    scanf("%d%d%d", &n, &l, &p);
    for(int i = 0;i<l;i++){
        for(int j = 0;j<n;j++)
            scanf("%d", &L[i][j]);
    }
    for(int i = 0;i<p;i++){
        for(int j = 0;j<n;j++)
            scanf("%d", &P[i][j]);
    }
    int lsum = 0, psum = 0;
    int o = 62500;

    for(int i = 0;i<n;i++){
        if(i == 0)
            dpL[0][0+o] = dpP[0][0+o] = n;
        lsum += L[0][i];
        psum += P[0][i];
        dpL[0][lsum+o] = min(dpL[0][lsum+o], n-i-1);
        dpP[0][psum+o] = min(dpP[0][psum+o], n-i-1);
    }
    for(int i = 1;i<l;i++){
        lsum = 0;
        int mini = i*(-50)*n;
        int maxi = i*50*n;
        for(int j = -1;j<n;j++){
            if(j != -1){
                lsum += L[i][j];
            }
            for(int k = mini;k<=maxi;k++){
                int kk = k+o;
                dpL[i][kk+lsum] = min(dpL[i][kk+lsum], dpL[i-1][kk]+n-j-1);
            }
        }
    }

    for(int i = 1;i<p;i++){
        psum = 0;
        int mini = i*(-50)*n;
        int maxi = i*50*n;
        for(int j = -1;j<n;j++){
            if(j != -1){
                psum += P[i][j];
            }
            for(int k = mini;k<=maxi;k++){
                int kk = k+o;
                dpP[i][kk+psum] = min(dpP[i][kk+psum], dpP[i-1][kk]+n-j-1);
            }
        }
    }
    int ans = n*(l+p);
    int mini = min(l, p)*(-50)*n;
    int maxi = min(l, p)*50*n;
    for(int i = mini;i<=maxi;i++)
        ans = min(ans, dpL[l-1][i+o]+dpP[p-1][i+o]);
    printf("%d\n", ans);
}
