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
int GCD(int a,int b)
{
    while(b^=a^=b^=a%=b);
    return a;
}
int main()
{
    in_T{
        int N, Q;
        in_I(N);
        in_I(Q);
        vector<int> arr(N), pre(N), post(N);
        for(int &a:arr)
            in_I(a);
        pre[0] = arr[0];
        post[N-1] = arr[N-1];
        for(int i = 1;i<N;i++){
            pre[i] = GCD(pre[i-1], arr[i]);
            post[N-i-1] = GCD(post[N-i], arr[N-i-1]);
        }
        while(Q--){
            int L, R;
            int ans;
            in_I(L);in_I(R);
            L--, R--;
            if(L == 0)
                ans = post[R+1];
            else if(R == N-1)
                ans = pre[L-1];
            else
                ans = GCD(pre[L-1], post[R+1]);
            printf("%d\n", ans);
        }
    }
}
