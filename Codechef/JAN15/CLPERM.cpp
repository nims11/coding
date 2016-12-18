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
int missing[100010];
int main()
{
    in_T{
        int N, K;
        in_I(N);
        in_I(K);
        for(int i = 0;i<K;i++)
            in_I(missing[i]);
        sort(missing, missing+K);
        long long sum = 0;
        long long res = -1;
        long long last = 0;
        for(int i = 0;i<K;i++){
            sum += (missing[i]*1LL*(missing[i]-1)/2) - (last*1LL*(last+1)/2);
            if(missing[i] > sum){
                res = missing[i];
                break;
            }
            last = missing[i];
        }
        sum += ((N+1)*1LL*N/2) - (last*1LL*(last+1)/2);
        if(res == -1)
            res = sum + 1;
        printf(res%2?"Chef\n":"Mom\n");
    }
}
