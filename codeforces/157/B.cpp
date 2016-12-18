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
#include<set>
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
int main()
{
    int tmp;
    int a,b,c,d,e,f;
    cin>>tmp>>a>>b>>c>>tmp>>d>>e>>f>>tmp;
    int A,B,C;
    A = a+b;
    B = c+d;
    C = e+f;
    for(int i=max(A,max(B,C))+1;i<=300000;i++)
    {
        int x = i-A, y = i-B, z = i-C;
        if(x+y+z == i)
        {
            cout<<x<<" "<<a<<" "<<b<<"\n"<<c<<" "<<y<<" "<<d<<"\n"<<e<<" "<<f<<" "<<z<<endl;
            return 0;
        }
    }
}
