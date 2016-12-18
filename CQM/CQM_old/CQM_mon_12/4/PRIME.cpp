/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<cmath>
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
bool isprime(int n)
{
    if(n==1)return false;
    int lt = sqrt(n);
    for(int i=2;i<=lt;i++)
    if(n%i==0)return false;
    return true;
}
int main()
{
    int n,a;
    for(int i=0;i<10;i++)
    {
        in_I(a);
        if(isprime(a))printf("prime\n");
        else printf("composite\n");
    }
}
