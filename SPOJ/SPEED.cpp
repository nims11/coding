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

using namespace std;
int gcd(int a, int b)
{
    return (b==0)?a:gcd(b,a%b);
}
int main()
{
    in_T
    {
        int a,b;
        cin>>a>>b;
        if(a<0 && b<0)
        a=-a,b=-b;
        int d,c;
        if(a<0 || b<0)
        {
            if(a<0)a=-a;
            else if(b<0)b=-b;
            d = min(a,b);
            c = a+b;
        }else
        {
            d = min(a,b);
            c = max(a,b) - d;
        }
        int e = gcd(c,d);
        d/=e;
        c/=e;
        cout<<c<<endl;
    }
}
