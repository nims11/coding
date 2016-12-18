/*
    Nimesh Ghelani (nims11)
    Euler Totient Function
    Objective is to find the number of numbers <= n which are relatively prime to it, ie gcd(n,i)=1
    Solve this by elimination.
    code self explanatory
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define FOR(i,n) for(int i=0;i<n;i++)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}

using namespace std;
int main()
{
    int n;
    in_T
    {
        in_I(n);
        if(n==1)printf("1\n");
        else
        {
            int ans=n;
            int lt=sqrt(n);
            for(int i=2;i<=lt;i++)
            {
                if(n%i==0)
                {
                    ans-=ans/i;
                    while(n%i==0)n/=i;
                }
            }
            if(n>1)
            ans-=ans/n;
            printf("%d\n",ans);
        }
    }
}
