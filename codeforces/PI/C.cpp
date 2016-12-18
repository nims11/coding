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
int dp[200010][3];
int main()
{
    int n, k;
    in_I(n);in_I(k);
    vector<int> arr(n);
    for(int i = 0;i<n;i++)
        in_I(arr[i]);
    map<long long, int> left, right;
    for(int i = 0;i<n;i++){
        if(right.find(arr[i]) == right.end())
            right[arr[i]] = 1;
        else
            right[arr[i]]++;
        if(left.find(arr[i]) == left.end())
            left[arr[i]] = 0;
    }
    long long res = 0;
    for(int i = 0;i<n;i++){
        right[arr[i]]--;
        if(arr[i]%k == 0){
            res += left[arr[i]/k]*1LL*right[arr[i]*1LL*k];
        }
        left[arr[i]]++;
    }
    cout<<res<<endl;
}
