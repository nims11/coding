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
long long n;
int main()
{
    cin>>n;
    long long ans = 0;
    long long curr = 1;
    long long curr_2 = 0;
    if(n%3 == 0)
    {
        long long nn = n;
        while(n%3 == 0)
        {
            n/=3;
            curr *= 3;
        }
        curr*=3;
        cout<<(nn/curr+1)<<endl;
        return 0;
    }
    ans = n/3 + 1;
    cout<<ans<<endl;
}
