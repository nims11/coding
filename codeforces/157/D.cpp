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
int M = 1000000007;
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
int pow_10[11];
int dp1[10] = {0};
void calc2(int a, int b, int len)
{
    int Z[10], X[10];
    int curr = 0;
    while(a)
    {
        int y = a%10, x = b%10;
        a/=10;b/=10;
        X[curr] = y-x+1;
        Z[curr] = (x<=4 && 4<=y) + (x<=7 && 7<=y);
        curr++;
    }
    int base = 0, maiin = 0, side = 0, sidee = -1;
    for(int i=0;i<len;i++)
    {
        if(X[i]!=1 && X[i]!=10)sidee = i;
        if(X[i]==1 && Z[i])
            base++;
        else if(X[i] == 10 && Z[i])
            maiin++;
        else if(X[i]>1 && X[i]<10 && Z[i])
            side++;
    }
    int total = side+maiin+base;
    cout<<"*"<<side<<"*"<<maiin<<"*"<<base<<endl;
    for(int i=0;base<=total;base++,i++)
    {
        if(side)
        {
            if(maiin-i-1>=0)
            dp1[base+i] = (dp1[base]+Z[i]*pow_10[maiin-i-1])%M;
            else
                dp1[base+i] = (dp1[base]+Z[i])%M;
        }
        dp1[base] = (dp1[base]+sidee*pow_10[maiin-i])%M;
    }
    cout<<"!!"<<dp1[1]<<endl;
}
void postfix_divide(int n, int len)
{
    if(n==10)
    {
        dp1[1] +=2;
        dp1[1] %= M;
        return;
    }
    int ans = 0;int foo;
    int lt = pow_10[len-1];
    for(int i=0;i<len-1 && n != lt-1; i++)
    {
            cout<<n<<" ";
            foo = n;
            n = pow_10[i+1]*(n/pow_10[i+1]);
            cout<<n<<endl;
            calc2(foo,n,len);
//            cout<<calc2(foo,n,len)<<" -- "<<ans<<endl;
            n--;
    }
    if(n!=lt-1)
    {
        cout<<n<<" ";
        foo = n;
        n = pow_10[len-1];
        calc2(foo,n,len);
        cout<<n<<endl;
//        cout<<calc2(foo,n,len)<<" -- "<<ans<<endl;
n--;
    }
    if(n>1)
    postfix_divide(n, len-1);
//    cout<<ans<<endl;
}
int main()
{
    pow_10[0] = 1;
    for(int i=1;i<=10;i++)
        pow_10[i] = 10*pow_10[i-1];
    postfix_divide(100, 3);
    cout<<dp1[1]<<" "<<dp1[2]<<endl;
}
