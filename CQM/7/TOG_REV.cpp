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
int pre[1000001];
int main()
{
    in_T{
        int n;
        in_I(n);
        pre[0] = 0;
        int x = 0;
        int res = -1;
        int tmp = 0;
        int tot = 0;
        for(int i = 1;i<=n;i++){
            in_I(x);
            if(x == 0)
                tmp++, res = max(tmp, res);
            else{
                tot++;
                tmp--;
                if(tmp < 0)
                    tmp = 0;
            }
        }
        printf("%d\n", tot+res);
    }
}
