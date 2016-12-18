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
    int arr[1024] = {0};
    int n;
    long long tmp;
    in_I(n);
    for(int i=0;i<n;i++)
    {
        in_L(tmp);
        long long foo = 0;
        while(tmp)
        {
            foo |= (1<<(tmp%10));
            tmp/=10;
        }
        arr[foo]++;
    }
    long long ans = 0;
    for(int i=0;i<1024;i++)
    {
        ans += ((arr[i]-1)*arr[i])/2;
        for(int j=i+1;j<1024;j++)
        {
            if(i&j)
            {
                ans += (arr[i]*arr[j]);
            }
        }
    }
    printf("%lld\n",ans);
}
