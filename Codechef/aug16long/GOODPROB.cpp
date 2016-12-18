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
int N;
int arr[100001];
long long prefixAns[100002];
long long suffixAns[100002];
int cnt1[1<<7][1<<7];
int cnt2[1<<7][1<<7];
int cnt[1<<14];
int prv[100002], nxt[100002];
int stk[100002];
int top = -1;
int main(){
    in_I(N);
    for(int i = 1;i<=N;i++){
        in_I(arr[i]);
    }
    arr[0] = 1e9;
    stk[++top] = 0;
    for(int i = 1;i<=N;i++){
        while(arr[stk[top]] < arr[i])top--;
        prv[i] = stk[top];
        stk[++top] = i;
    }

    arr[N+1] = 1e9;
    top = -1;
    stk[++top] = N+1;
    for(int i = N;i>0;i--){
        while(arr[stk[top]] < arr[i])top--;
        nxt[i] = stk[top];
        stk[++top] = i;
    }

    // calc prefix
    for(int i = 1;i<=N;i++){
        int hi = arr[i]>>7, lo = arr[i]&((1<<7)-1), x, ans = 0;
        // get ans
        x = lo;
        while(x < (1<<7)){ ans += cnt2[hi][x]; x = (x+1)|lo; }

        x = lo;
        ans += cnt1[hi][0];
        while(x){ ans += cnt1[hi][x]; x = (x-1)&lo; }

        // remove duplicates
        ans -= cnt[arr[i]];
        prefixAns[i] = prefixAns[i-1] + ans;

        // update with super sets
        x = hi;
        while(x < (1<<7)){ cnt1[x][lo]++; x = (x+1)|hi; }

        // update with sub sets
        x = hi;
        cnt2[0][lo]++;
        while(x){ cnt2[x][lo]++; x = (x-1)&hi; }

        cnt[arr[i]]++;
    }

    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    memset(cnt, 0, sizeof(cnt));
    // for(int i = 0;i<=N;i++)
    //     cout<<prefixAns[i]<<" ";
    // cout<<endl;

    // calc suffix
    for(int i = N;i>0;i--){
        int hi = arr[i]>>7, lo = arr[i]&((1<<7)-1), x, ans = 0;
        // get ans
        x = lo;
        while(x < (1<<7)){ ans += cnt2[hi][x]; x = (x+1)|lo; }

        x = lo;
        ans += cnt1[hi][0];
        while(x){ ans += cnt1[hi][x]; x = (x-1)&lo; }

        // remove duplicates
        ans -= cnt[arr[i]];
        suffixAns[i] = suffixAns[i+1] + ans;

        // update with super sets
        x = hi;
        while(x < (1<<7)){ cnt1[x][lo]++; x = (x+1)|hi; }

        // update with sub sets
        x = hi;
        cnt2[0][lo]++;
        while(x){ cnt2[x][lo]++; x = (x-1)&hi; }

        cnt[arr[i]]++;
    }
    // for(int i = 0;i<=N+1;i++)
    //     cout<<suffixAns[i]<<" ";
    // cout<<endl;
    // for(int i = 1;i<=N;i++){
    //     for(int j = i+1;j<=N;j++){
    //         cout<<i<<" "<<j<<" "<<(prefixAns[j]+suffixAns[i]-prefixAns[N])<<endl;
    //     }
    // }
}
