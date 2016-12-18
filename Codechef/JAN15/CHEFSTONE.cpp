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
#define BE(a) a.begin(), a.end()

using namespace std;
int _time[100010], profit[100010];
int main()
{
    in_T{
        int N, K;
        in_I(N); in_I(K);
        long long res = 0, ans = -1;
        for(int i = 0;i<N;i++){
            in_I(_time[i]);
        }
        for(int i = 0;i<N;i++)
            in_I(profit[i]);
        for(int i = 0;i<N;i++){
            long long tmp = K/_time[i]*1LL*profit[i];
            if(tmp > res)
                res = tmp;
        }
        printf("%lld\n", res);
    }
}
