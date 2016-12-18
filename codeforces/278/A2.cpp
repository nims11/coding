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
    int ret = (H-Hy)*h + (A-Ay)*a + (D-Dy)*d;
        return ret;
}
int lhs[10001];
int lhsInf = 1e9;
int rhsInf = 0;
int rhs[200];
int main()
{
    cin>>Hy>>Ay>>Dy>>Hm>>Am>>Dm>>h>>a>>d;
    for(int i = 0;i<200;i++)
       rhs[i] = 1e9;
    for(int i = 0;i<10001;i++)
        lhs[i] = 1e9;
    for(int H = 1;H<=10000;H++){
        for(int D = 1;D<=100;D++){
            if(Am <= D)
                lhsInf = min(lhsInf, ans1(H, Ay, D));
            else{
                int idx = H/(Am-D) + (H%(Am-D) != 0);
                int res = ans1(H, Ay, D);
                if(idx > 10000)
                    break;
                lhs[idx] = min(lhs[idx], res);
            }
        }
    }
    if(Ay <= Dm)
        rhsInf = (Dm-Ay+1)*a;
    for(int A = 1;A<=300;A++){
        if(A <= Dm)
            continue;
        int idx = Hm/(A-Dm) + (Hm%(A-Dm) != 0);
        if(idx >= 200)
            break;
        rhs[idx] = min(rhs[idx], ans1(Hy, A, Dy));
    }

    int res = min((int)1e9, lhsInf+rhsInf);
    for(int i = 0;i<=10000;i++)
        for(int j = 0;j<i && j<200;j++)
            res = min(res, lhs[i]+rhs[j]);
    printf("%d\n", res);
}
