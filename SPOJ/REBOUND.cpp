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
#include<cmath>
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
long long D,D2,x,y,z,a,A,B,C;
int main()
{
    in_T
    {
        bool flag = true;
        scanf("%lld%lld%lld", &x, &y, &z);
        D = x*x + y*y + 2*y*z;
        D2 = sqrt(D);
        if(D2*D2 != D)
            flag = false;
        else
        {
            if(y%(z))flag = false;
            else
            {
                A = y/z + 2;
                B = x+D2;
                if(B%A)
                {
                    B = x-D2;
                    if(B>=0 && B%A==0)
                    printf("%lld\n", (x-D2)/A);
                    else
                    flag = false;
                }
                else
                {
                    printf("%lld\n", B/A);
                }
            }
        }
        if(!flag)
            printf("Not this time.\n");
    }
}
