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
int main()
{
    int lt = 8;

    int K;
    while(cin>>K)
    for(int n=2;n<=8;n++){
        int k = n+K;
    int a[n];
    int ans = 0;
    for(int i=0;i<n;i++)
        a[i] = i+1;
    do
    {
        bool flag = true;
        for(int i=0;i<n-1;i++)
        {
            if(a[i]+a[i+1]>k)
            {
                flag = false;
                break;
            }
        }
        ans += flag;
    }while(next_permutation(a, a+n));
    cout<<ans<<endl;
    }
}
