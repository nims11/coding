/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
vector<int> fib;
int main()
{
    fib.push_back(0);
    int a=0,b=1;
    while(b<=1000000000)
    {
        fib.push_back(b);
        b+=a;
        a=b-a;
    }
    int n;
    in_T
    {
        in_I(n);
        printf("%d\n",fib[n+2]);
    }
}
