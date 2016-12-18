#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)
int arr1[101];
int arr2[101];
int tmp[100001];
int dp1[100001];
int dp2[100001];
int cnttmp = 0;
int diff[100001][2];
int main(){
    int n1;
    in_I(n1);
    for(int i = 0;i<n1;i++)
        in_I(arr1[i]);

    int n2;
    in_I(n2);
    for(int i = 0;i<n2;i++)
        in_I(arr2[i]);

    tmp[cnttmp++] = 0;
    int v;
    int z_1 = 0, z_2 = 0;
    for(int i = 0;i<n1;i++){
        int diff_cnt = 0;
        for(int j = cnttmp-1;j>=0;j--){
            v = tmp[j] + arr1[i];
            if(!dp1[v]){
                dp1[v] = dp1[tmp[j]]+1;
                diff[diff_cnt][0] = v;
                diff[diff_cnt++][1] = dp1[tmp[j]]+1;
                tmp[cnttmp++] = v;
            }else if(dp1[v] > dp1[tmp[j]]+1){
                diff[diff_cnt][0] = v;
                diff[diff_cnt++][1] = dp1[tmp[j]]+1;
            }
        }
        for(int i = 0;i<diff_cnt;i++)
            dp1[diff[i][0]] = diff[i][1];
    }

    cnttmp = 0;
    tmp[cnttmp++] = 0;
    for(int i = 0;i<n2;i++){
        int diff_cnt = 0;
        for(int j = cnttmp-1;j>=0;j--){
            v = tmp[j] + arr2[i];
            if(!dp2[v]){
                dp2[v] = dp2[tmp[j]]+1;
                diff[diff_cnt][0] = v;
                diff[diff_cnt++][1] = dp2[tmp[j]]+1;
                tmp[cnttmp++] = v;
            }else if(dp2[v] > dp2[tmp[j]]+1){
                diff[diff_cnt][0] = v;
                diff[diff_cnt++][1] = dp2[tmp[j]]+1;
            }
        }
        for(int i = 0;i<diff_cnt;i++)
            dp2[diff[i][0]] = diff[i][1];
    }

    int inf = 1e9;
    int ans = inf;

    for(int i = 1;i<=100000;i++){
        if(dp1[i] && dp2[i]){
            ans = min(ans, dp1[i]+dp2[i]);
        }
    }

    if(ans == inf){
        printf("impossible\n");
    }else
        printf("%d\n",ans);
}
