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
const int mod = 1000000007;
int C[1000][1000];
int main()
{
    for(int i = 0;i<1000;i++)
        C[i][0] = C[i][i] = 1;
    for(int i = 1;i<1000;i++)
        for(int j = 1;j<1000;j++)
            C[i][j] = (C[i-1][j-1]+C[i-1][j])%3;
    in_T{
        long long n;
        in_L(n);
        long long res = 0;
        for(int i = 0;i<=n;i++){
            res = (res + C[n][i])%mod;
            if(C[n][i])
                cout<<i<<" "<<C[n][i]<<endl;
        }
        printf("%lld\n", res);
    }
}
