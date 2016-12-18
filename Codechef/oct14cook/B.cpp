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
int xx;
int main()
{
    in_T{
        int N, M;
        in_I(N);in_I(M);
        int maxi = -1, mini = 1e9;
        for(int i = 0;i<M;i++){
            in_I(xx);
            maxi = max(xx, maxi);
            mini = min(xx, mini);
        }
        for(int i = 0;i<N;i++){
            printf("%d ", max(abs(mini-i), abs(maxi-i)));
        }
        newline;
    }
}
