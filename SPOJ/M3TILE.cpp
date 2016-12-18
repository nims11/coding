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
int main()
{
    int ans[31]={0};
    ans[0] = 1;
    ans[1] = 0;
    for(int i=2;i<=30;i+=2)
    {
        ans[i] = ans[i-2];
        for(int j=i-2;j>=0;j-=2)
        {
            ans[i] += 2*ans[j];
        }
    }
    int n;
    while(cin>>n)
    {
        if(n==-1)return 0;
        cout<<ans[n]<<endl;
    }
}
