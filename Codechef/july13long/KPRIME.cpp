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
const int MAXN = sqrt(100000);
int sieve[100002];
int ans[5][100001];
void init()
{
    for(int i = 2; i<=100000; i++)
        sieve[i] = 0;

    for(int i = 2; i<= 100000; i++)
    {
        if(sieve[i] == 0)
        {
            sieve[i] = 1;
            for(int j=i+i; j<=100000; j+=i)
                sieve[j]++;
        }
    }
//    for(int i=0;i<=10;i++)
//        cout<<i<<" "<<sieve[i]<<endl;
}
int main()
{
    init();
    for(int i=2; i <= 100000; i++)
    {
        if(sieve[i]<=5)
            ans[sieve[i]-1][i] = 1;
    }
    for(int k=0;k<5;k++)
    for(int i=2;i<=100000;i++)
        ans[k][i] += ans[k][i-1];

    in_T
    {
        int A,B,K;
        scanf("%d%d%d", &A, &B, &K);
        printf("%d\n", ans[K-1][B] - ans[K-1][A-1]);
    }
}
