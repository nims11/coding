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
#define buffer 60
int n, T;
int arr[101];
int lis[111*buffer][301];
int lis2[111*buffer][301];
int arr2[101];
int cnt[301];
int main(){
    in_I(n);
    in_I(T);
    for(int i = 0;i<n;i++)
        in_I(arr[i+1]);
    for(int i = 0;i<n;i++){
        arr2[i] = arr[i+1];
        cnt[arr[i+1]]++;
    }
    sort(arr2, arr2+n);
    int limit = min(T, buffer);
    int idx;
    for(int t = 0;t<limit;t++){
        for(int i = 1;i<=n;i++){
            idx = n*t+i;
            for(int j = 0;j<n && arr2[j] <= arr[i];j++)
                lis[idx][arr[i]] = max(lis[idx][arr[i]], 1+lis[idx-1][arr2[j]]);
            // cout<<idx<<" "<<lis[idx][arr[i]]<<endl;
            for(int j = 0;j<n;j++){
                if(arr[i] != arr2[j])
                    lis[idx][arr2[j]] = lis[idx-1][arr2[j]];
            }
        }
    }

    int rem = T-limit;
    int limit2 = min(rem, buffer);
    int idx2=0;
    for(int t = limit2-1;t>=0;t--){
        for(int i = n;i>=1;i--){
            int idx = n*t+i;
            for(int j = n-1;j>=0 && arr2[j] >= arr[i];j--)
                lis2[idx][arr[i]] = max(lis2[idx][arr[i]], 1+lis2[idx+1][arr2[j]]);
            for(int j = 0;j<n;j++){
                if(arr[i] != arr2[j])
                    lis2[idx][arr2[j]] = lis2[idx+1][arr2[j]];
            }
            idx2 = idx;
        }
    }
    rem = T-limit-limit2;
    int ans = 0;
    for(int i = 0;i<=300;i++){
        // if(cnt[i] != 0){
        //     cout<<i<<endl;
        //     cout<<lis[idx][i]<<" "<<lis2[idx2][i]<<endl;
        // }
        ans = max(ans, lis[idx][i] + lis2[idx2][i] + cnt[i]*rem);
    }
    printf("%d\n", ans);
}
