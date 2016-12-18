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
long long foo[63];
long long unsigned wg(long long n)
{
    long long unsigned ret = 0;
    for(int i=1;i<63;i++)
    {
//        if(n-foo[i-1]<=0)return ret;
        ret += ((n+foo[i-1])/foo[i])*foo[i-1];
//        cout<<ret<<endl;
    }
    return ret;
}
int main()
{
    foo[0] =1;
    for(int i=1;i<63;i++)
    {
        foo[i]=2*foo[i-1];
    }
//    cout<<wg(0)<<endl;
    long long a,b;
    in_L(a);
    in_L(b);
    cout<<wg(b)-wg(a-1)<<endl;
}
