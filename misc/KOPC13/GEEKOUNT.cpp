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
#include<cmath>
#include<stack>
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
long long pow_10[11];
int len_int(long long n)
{
    int cnt = 0;
    while(n)
    {
        cnt++;
        n/=10;
    }
    return cnt;
}
int pow_2[11];
int foo(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 5;
    return 5*pow_10[n-1]+5*foo(n-1);
}
int calc2(int n2, int n1, int len)
{
    int dig1[len], dig2[len], tmp1=n1,tmp2=n2;
//    cout<<n1<<" "<<n2<<endl;
    for(int i=0;i<len;i++)
    {
        dig1[i] = n1%10;
        dig2[i] = n2%10;
        n1/=10;
        n2/=10;
    }
    int ans = 0;
    int i;
    for(i=len-1;i>=0;i--)
    {
        if(dig1[i]==dig2[i] && dig1[i]%2==0)
        {
            ans = tmp2-tmp1+1;
            break;
        }
        if(dig1[i]!=dig2[i])
        {
                ans = ((dig2[i]+2)/2-(dig1[i]+1)/2)*pow_10[i]+(dig2[i]-dig1[i]+1-((dig2[i]+2)/2-(dig1[i]+1)/2))*foo(i);
                break;
        }
    }
//    cout<<" "<<ans<<endl;
    return ans;
}
int postfix_divide(int n, int len)
{
//    cout<<n<<endl;
    if(n==10)return 5;
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
    for(int i=1;i<=10;i++)
        pow_10[i] = 10*pow_10[i-1];
    pow_2[0] = 1;
    for(int i=1;i<=10;i++)
        pow_2[i] = 2*pow_2[i-1];
//    cout<<postfix_divide(20,2)<<endl;
    in_T
    {
        int l,r;
        in_I(l);
        in_I(r);
        printf("%d\n", postfix_divide(r, len_int(r))-postfix_divide(l-1, len_int(l-1)));
    }
}
