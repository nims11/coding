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
int n;
int arr[100010];
int diff_field[100010];
int main(){
    in_I(n);
    for(int i = 0;i<n;i++)
        in_I(arr[i]);
    int zeroes = 0;
    int ans = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] == 0)
            zeroes++;
        else if(arr[i] < n){
            int end = (i-arr[i]+1)%n;
            if(end < 0) end += n;
            diff_field[(i+1)%n]++;
            diff_field[end]--;
            if((i+1)%n == 0 || ((i+1)%n > end && end > 0))
                ans++;
        }
    }

    int best_ans = ans;
    int x = 0;
    for(int i = 1;i<n;i++){
        ans += diff_field[i];
        if(ans > best_ans)
            ans = best_ans, x = i;
    }
    cout<<x+1<<endl;
}
