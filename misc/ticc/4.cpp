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
long long getans(long long n, int x, int P){
    long long ret = n/P;
    return ret + (n%P >= x);
}
int main()
{
    in_T{
        long long A, B;
        int P;
        in_L(A);
        in_L(B);
        in_I(P);
        long long res = 0;
        for(int i = 1;i<P;i++){
            if((i*1LL*i*i)%P == 1)
            {
                res += getans(B, i, P) - getans(A-1, i, P);
            }
        }
        cout<<res<<endl;
    }
}
