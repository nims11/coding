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
int Hy, Hm, Ay, Am, Dy, Dm, a, h, d;
int ans1(int H, int A, int D){
    if(H < Hy || A < Ay || D < Dy)
        return 1e9;
    if(A <= Dm)
        return 1e9;
    int ret = (H-Hy)*h + (A-Ay)*a + (D-Dy)*d;
    if(Am <= D)
        return ret;
    int l1 = H/(Am-D) + (H%(Am-D) != 0);
    int r1 = Hm/(A-Dm) + (Hm%(A-Dm) != 0);
    if(l1 > r1)
        return ret;
    else
        return 1e9;
}
int main()
{
    cin>>Hy>>Ay>>Dy>>Hm>>Am>>Dm>>h>>a>>d;
    int res = 1e9;
    for(int i = 0;i<=1000;i++)
        for(int j = 0;j<=1000;j++)
            for(int k = 0;k<=1000;k++)
                res = min(res, ans1(i, j, k));
    printf("%d\n", res);
}
