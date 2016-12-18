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
int n,k;
int g(int n)
{
    if(n==1)return 0;
    return (g(n-1)+k)%n;
}
int main()
{
    in_T
    {
        scanf("%d%d",&n,&k);
//        int ans=0;
//        stack<int> foo,bar;
//        for(int i=1;i<=n;i++)
//            foo.push(i);
//        for(int i=2;i<=n;i++)
//        {
//            ans = (ans+k)%n;
//        }
//        printf("%d\n",ans+1);
printf("%d\n",g(n)+1);
    }
}
