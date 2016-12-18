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
set<long long> fibo;
int main()
{
    fibo.insert(0);
    long long a = 0, b = 1;
    while(b<=10000000000LL){
        fibo.insert(b);
        b += a;
        a = b-a;
    }
    in_T{
        long long N;
        in_L(N);
        printf((fibo.find(N) != fibo.end())?"IsFibo\n":"IsNotFibo\n");
    }
}
