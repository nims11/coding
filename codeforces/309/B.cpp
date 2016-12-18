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
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)
int n;long long l;
long long fact[100];
vector<int> res;
long long dp[100];
void getans1(int idx, long long k){
    if(idx == n){
        for(int i = 0;i<res.size();i++)
            cout<<res[i]+1<<" ";
        cout<<endl;
        return;
    }
    long long op1 = dp[n-idx-1];
    if(k < op1){
        res.push_back(idx);
        getans1(idx+1, k);
    }else{
        res.push_back(idx+1);
        res.push_back(idx);
        getans1(idx+2, k-op1);
    }
}
int main()
{
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2;i<100;i++)
        dp[i] = dp[i-1]+dp[i-2];
    fact[0] = 1;
    for(int i = 1;i<100;i++)
        fact[i] = i*fact[i-1];
    cin>>n>>l;
    l--;
    getans1(0, l);
}
