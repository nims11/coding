/*
    Nimesh Ghelani (nims11)
    Range Division
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
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
int pow_10[10];
int dp[9][100];
int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int primesz(sizeof(primes)/sizeof(int));
int len_int(int n)
{
    int cnt = 0;
    while(n)
    {
        cnt++;
        n/=10;
    }
    return cnt;
}
int calc2(int a, int b, int len)
{
//    cout<<a<<" "<<b<<endl;
    // a>b
    int A[len], B[len];
    int cnt=0;
    while(a)
    {
        A[cnt] = a%10;
        B[cnt++] = b%10;
        a/=10, b/=10;
    }
    int z_n = 0;
    int i;
    for(i=0;i<len;i++)
    {
        if(A[i] == 9 && B[i] == 0)
            z_n++;
        else
            break;
    }
    int partial_z_n = -1, eq = -1;
    if(A[i]!=B[i])
        partial_z_n = i, eq = i+1;
        else
            eq = i;

    int pre_sum  = 0;
    for(int j=eq;j<len;j++)
        pre_sum += A[j];
    int ret = 0;
    if(partial_z_n!=-1)
    {
        for(int j=B[i];j<=A[i];j++)
        {
            for(int k=0;k<primesz;k++)
            {
                if(primes[k]-(pre_sum+j)>=0 && primes[k]-(pre_sum+j)<100)
                {
                    ret += dp[z_n][primes[k]-(pre_sum+j)];
                }
            }
        }
    }else
    {
        for(int k=0;k<primesz;k++)
        {
            if(primes[k]-(pre_sum)>=0 && primes[k]-(pre_sum)<100)
                ret += dp[z_n][primes[k]-(pre_sum)];
        }
    }
//    cout<<ret<<endl;
    return ret;
}
int postfix_divide(int n, int len)
{
//    cout<<n<<endl;
//    if(n==10)return 5;
    if(n==0)return 0;
    int ans = 0;int foo;
    int lt = pow_10[len-1];
    for(int i=0;i<len-1 && n != lt-1; i++)
    {
//            cout<<n<<" ";
            foo = n;
            n = pow_10[i+1]*(n/pow_10[i+1]);
//            cout<<n<<endl;
            ans+=calc2(foo,n,len);
//            cout<<calc2(foo,n,len)<<" -- "<<ans<<endl;
            n--;
    }
    if(n!=lt-1)
    {
//        cout<<n<<" ";
        foo = n;
        n = pow_10[len-1];
        ans+=calc2(foo,n,len);
//        cout<<n<<endl;
//        cout<<calc2(foo,n,len)<<" -- "<<ans<<endl;
        n--;
    }
    if(n>1)
    ans += postfix_divide(n, len-1);
//    cout<<ans<<endl;
    return ans;
}
int main()
{
    pow_10[0] = 1;
    for(int i=1;i<10;i++)
        pow_10[i] = pow_10[i-1]*10;
    int a,b;
    dp[0][0] = 1;
    for(int i=1;i<9;i++)
    {
        for(int j=1;j<100;j++)
            for(int k=max(0, j-9);k<=j;k++)
            dp[i][j] += dp[i-1][k];
    }
    for(int i=1;i<9;i++)
        for(int j=0;j<100;j++)
        dp[i][j] += dp[i-1][j];
//    cout<<postfix_divide(9,len_int(9))<<endl;
    in_T
    {
        in_I(a);
        in_I(b);
//        cout<<b<<" "<<len_int(b)<<" "<<postfix_divide(b, len_int(b))<<endl;
//        cout<<a-1<<" "<<len_int(a-1)<<" "<<postfix_divide(a-1, len_int(a-1))<<endl;
        printf("%d\n", postfix_divide(b, len_int(b)) - postfix_divide(a-1, len_int(a-1)));
    }
}
