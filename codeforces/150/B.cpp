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
int calc2(int n2, int n1, int len)
{
    int dig1[len], dig2[len];
    for(int i=0;i<len;i++)
    {
        dig1[i] = n1%10;
        dig2[i] = n2%10;
        n1/=10;
        n2/=10;
    }
    int foo[10]={0};
    int diff_dig = 0;
    int cnt = len-1;
    while(cnt>=0 && dig1[cnt]==dig2[cnt])
    {
        if(!foo[dig1[cnt]])
        {
            foo[dig1[cnt]] = 1;
            diff_dig++;
            if(diff_dig>2)return 0;
        }
        cnt--;
    }
//    cout<<"*"<<cnt<<endl;
    if(cnt==-1)return 1;
    int other_a = dig1[cnt], other_b = dig2[cnt];
    int rem = cnt;
    int xy[2], q = 0;
    for(int i=0;i<10;i++)
        if(foo[i])
            xy[q++] = i;
    int ans = 0;
    switch(diff_dig)
    {
        case 2:
        if(xy[0]>=other_a && xy[0]<=other_b)
            ans++;
        if(xy[1]>=other_a && xy[1]<=other_b)
            ans++;
        return ans*pow_2[rem];
        break;

        case 1:
        if(xy[0]>=other_a && xy[0]<=other_b)
        {
            ans = 9*pow_2[rem] - 8;
            ans += (other_b-other_a)*pow_2[rem];
        }else
        {
            ans = (other_b-other_a +1)*pow_2[rem];
        }
        break;

        case 0:
        ans = (other_b - other_a + 1)*(9*pow_2[rem]-8);
        break;

    }
    return ans;
}
int postfix_divide(int n, int len)
{
//    cout<<n<<endl;
    if(n==10)return 10;
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
    int n = 123;
    cin>>n;
    cout<<postfix_divide(n, len_int(n))<<endl;
}
