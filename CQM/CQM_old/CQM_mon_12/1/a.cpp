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
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;
#define P_I(a) printf("%d",a)

using namespace std;
int main()
{
    int n;
    long long k,ans;
    while(cin>>n)
    {
        long long g[1000004];
        for(int i=0;i<n;i++)
        in_L(g[i]);
        int i=0;
        sort(g,g+n);
        for(;i<n;i++)
        {
            if(g[i]==g[i+1])i++;
            else {break;}
        }
        printf("Forever Alone Guy : %lld\n",g[i]);
    }
}
