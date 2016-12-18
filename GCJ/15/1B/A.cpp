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
long long rev(long long n){
    long long n2 = 0;
    while(n){
        n2 = n2*10 + (n%10);
        n /= 10;
    }
    return n2;
}
int intlen(long long n){
    int x = 0;
    while(n){
        n/=10;
        x++;
    }
    return x;
}
long long getans(long long n){
    if(n <= 11)
        return n;
    if(n%10 == 0)
        return getans(n-1)+1;
    long long n2 = n;
    int len = intlen(n);
    len = len/2 + (len%2);
    int idx = 0;
    long long n3=0;
    while(idx < len){
        n3 = n3*10 + (n2%10);
        n2/=10;
        idx++;
    }
    n3 = rev(n3);
    // cout<<n<<" "<<n3<<" "<<len<<endl;
    long long ans = 0;
    n = n-n3+1;
    if(rev(n) != n)
        n = rev(n), ans++;
    else{
        if(n > 11){
            ans = 2;
            n -= 2;
        }
    }
    return n3-1+ans+getans(n);

    int first = -1, last = -1;
    while(n2){
        last = n2%10;
        if(first == -1)
            first = n2%10;
        n2 /= 10;
    }
    if(first == 1 && last == 1){
        long long ans = 0;
        if(n > rev(n) && n%100 < 10)
            n = rev(n), ans++;
        ans += (2+getans(n-2));
        // cout<<n<<" "<<ans<<endl;
        return ans;
    }else if(first == 1){
        long long ans = 1 + getans(rev(n));
        // cout<<n<<" "<<ans<<endl;
        return ans;
    }else{
        long long ans = (n%10)-1+getans(n - (n%10) + 1);
        // cout<<n<<" "<<ans<<endl;
        return ans;
    }
}
int dp[100000001];
int back[100000001];
void backtrack(int x){
    cout<<back[x]<<endl;
    if(x != 1)backtrack(back[x]);
}
int main()
{
    for(int i = 1;i<=100000000;i++)
        dp[i] = 1e9;
    dp[1] = 1;
    for(int i = 1;i<=100000000;i++){
        int c1 = rev(i);
        int c2 = i+1;
        if(i % 10 != 0 && c1 < 100000001 && dp[c1] > dp[i]+1)
            dp[c1] = min(dp[c1], dp[i]+1), back[c1] = i;
        if(c2 < 100000001 && dp[c2] > dp[i]+1)
            dp[c2] = min(dp[c2], dp[i]+1), back[c2] = i;
    }
    cout<<"SD"<<endl;
    int z = 0;
    for(int i = 1;i<=100000000;i++)
        if(dp[i] != getans(i)){
            cout<<i<<endl;
            break;
        }
    return 0;
    in_T{
        z++;
        long long n;
        in_L(n);
        // backtrack(n);
        cout<<"Case #"<<z<<": "<<getans(n)<<endl;
    }
}
