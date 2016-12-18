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
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<stack>
#include<set>
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
int GCD(int a,int b)
{
    while(b^=a^=b^=a%=b);
    return a;
}
int main()
{
    in_T{
        int N;
        in_I(N);
        if(N == 1)
            printf("0/1\n");
        else{
            long long num = N*1LL*(N-1);
            long long den = 8;
            if(num%2 == 0)
                num /=2, den = 4;
            if(num%2 == 0)
                num /= 2, den =2;
            if(num%2 == 0)
                num /=2, den =1;
            printf("%lld/%lld\n", num, den);
        }
    }
}
