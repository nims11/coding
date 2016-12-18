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
long long getans(int a, int b, long long m){
    long long sum = (m*((a*1LL*(a+1)/2)%mod))%mod;
    sum = (sum * b)%mod;
    sum = (sum + m*a)%mod;
    return sum;
}
int main()
{
    int a, b;
    cin>>a>>b;
    long long res = 0;
    for(int i = 1;i<b;i++){
        res = (res + getans(a, b, i))%mod;
    }
    cout<<res<<endl;
}
