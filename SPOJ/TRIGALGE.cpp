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
const double pi = acos(-1);
int main()
{
    in_T
    {
        int A,B,C;
        in_I(A);
        in_I(B);
        in_I(C);
        double xp1, x1 = (double)C/A;
        for(int i=0;i<6;i++)
        {
            xp1 = x1 - (A*x1+B*sin(x1)-C)/(A+B*cos(x1));
            x1 = xp1;
        }
        printf("%.6lf\n", xp1);
    }
}
