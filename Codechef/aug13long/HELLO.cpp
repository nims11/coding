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
double D, R; int U, N, M, C;
int x1, x2;
int main()
{
    in_T
    {
        scanf("%d.%d %d %d", &x1, &x2, &U, &N);
        D = (x1*100 + x2)/100.0;
        double curr = D*U;
        int maxi = 0;
        for(int i = 1; i<=N; i++)
        {
            scanf("%d %d.%d %d", &M, &x1, &x2, &C);
            R = (x1*100 + x2)/100.0;
            double X = C + M*U*R;
            if(X/M < curr)
                maxi = i, curr = X/M;
        }
        cout<<maxi<<endl;
    }
}
