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
long long pow_10[19];
int len_int(long long n){
    int cnt = 0;
    while(n){
        cnt++;
        n/=10;
    }
    return cnt;
}
int bhak[11] = {0, 0, 0, 1, 2, 2, 3, 3, 4, 4, 4};
long long calc2(long long a, long long b, int len){
    long long tot = 1;
    long long notPrime = 1;
//cout<<a<<" "<<b<<" ";
    while(a){
        int x = a%10;
        int y = b%10;
        a/=10;
        b/=10;
        tot *= x-y+1;
        notPrime *= (x-y+1)-(bhak[x+1]-bhak[y]);
    }
 //   cout<<tot-notPrime<<endl;
    int x;
    return tot-notPrime;
}
map<long long, long long> dp;
long long postfix_divide(long long n, int len){
    if(dp.find(n) != dp.end())
        return dp[n];
//    cout<<n<<endl;
//    if(n==10)return 5;
    if(n==0)return 0;
    long long ans = 0, foo;
    long long lt = pow_10[len-1];
    for(int i=0;i<len-1 && n != lt-1; i++){
//            cout<<n<<" ";
            foo = n;
            n = pow_10[i+1]*(n/pow_10[i+1]);
//            cout<<n<<endl;
            ans+=calc2(foo,n,len);
//            cout<<calc2(foo,n,len)<<" -- "<<ans<<endl;
            n--;
    }
    if(n!=lt-1){
//        cout<<n<<" ";
        foo = n;
        n = pow_10[len-1];
        ans+=calc2(foo,n,len);
//        cout<<n<<endl;
//        cout<<calc2(foo,n,len)<<" -- "<<ans<<endl;
        n--;
    }
    long long tmp;
    if(n>1){
        tmp = (postfix_divide(n, len-1));
        ans += tmp;
        dp[n] = tmp;
    }

    return ans;
}

int main()
{
    pow_10[0] = 1;
    for(int i = 1;i<19;i++)pow_10[i] = 10*pow_10[i-1];
    in_T{
        long long L;
        in_L(L);
        printf("%lld\n", postfix_divide(L, len_int(L)));
    }
}

