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
int main()
{
    in_T{
        long long L, R;
        in_L(L);
        in_L(R);
        long long res = 0;
        for(int i = 63;i>=0;i--){
            if((R&(1LL<<i)) && !(L&(1LL<<i))){
                res = res*2+0;
                i--;
                while(i>=0){
                    res = res*2+1;
                    i--;
                }
            }else if((R&(1LL<<i))){
                res = res*2+1;
            }else
                res = res*2;
        }
        printf("%lld\n", __builtin_popcountll(R)>__builtin_popcountll(res)?R:res);
    }
}
