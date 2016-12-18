/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
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
#include<cmath>
using namespace std;
long long n;
int getans(long long n,long long rem)
{
//    cout<<n<<endl;
//    int q;
//    cin>>q;
    if(n==rem || n==0)return 0;
    long long foo = (long long)1<<(int)log2(n);
    int count=0;
    while(rem!=foo)
    rem/=2,count++;
    return count+getans(n-rem, rem);
}
int main()
{
    in_T
    {
        in_L(n);
        int foo = ceil(log2(n));
        int bar;
        bar = getans(n,(long long)1<<foo);
        printf("%lld %d\n",(long long)1<<foo,bar);
    }
}
