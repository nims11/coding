/*
    Nimesh Ghelani (nims11)
    Brute force every possible diagnal squares
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
    int t =1;
    long long A[4];
    while(cin>>A[0]>>A[1]>>A[2]>>A[3])
    {
        cout<<"Case "<<t<<": ";
        long long ans = 10000000000LL;
        long long sum = A[0]+A[1]+A[2]+A[3];
        for(int i=0;i<4;i++)
        {
            long long foo = 0;
            for(int j=0;j<4;j++)
            {
                if(j!=i)
                    foo = max(foo, A[j]);
            }
            ans = min(ans, max(A[i] + foo,sum-A[i]));
        }
        for(int i=0;i<4;i++)
        {
            for(int j=i+1;j<4;j++)
            {
                long long foo = 0;
                for(int k=0;k<4;k++)
                {
                    if(k!=i && k!=j)
                        foo = max(foo, A[k]);
                }
                ans=min(ans, max(max(A[i],foo)+max(A[i],sum-foo-A[j]-A[i]), max(A[j],foo)+max(A[j],sum-foo-A[j]-A[i])));
            }
        }
        cout<<ans<<endl;
        t++;
    }
}
