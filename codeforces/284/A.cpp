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
template <class T>
class POINT{
    public:
    T P[2];
    POINT(){}
    POINT(T x, T y){P[0] = x, P[1] = y;}
    //dot
    T operator*(const POINT &a){
        return a.P[0]*this->P[0] + a.P[1]*this->P[1];
    }
    POINT operator-(const POINT &b){
        return POINT(this->P[0] - b.P[0], this->P[1] - b.P[1]);
    }
    //cross
    T operator^(const POINT &b){
        return this->P[0]*b.P[1] - this->P[1]*b.P[0];
    }
};
int ccw(POINT<double> a, POINT<double> b, POINT<double> c)
{
    double foo = ((b-a)^(c-a));
    return foo > 0?1:(foo<0?-1:0);
}

int main()
{
    POINT<double> P1, P2;
    int x1, x2, y1, y2;
    in_I(x1);in_I(y1);
    in_I(x2);in_I(y2);
    int n;
    in_I(n);
    P1 = POINT<double>(x1, y1), P2 = POINT<double>(x2, y2);
    int a, b, c;
    int res = 0;
    for(int i = 0;i<n;i++){
        in_I(a);in_I(b);in_I(c);
        POINT<double>L1, L2;
        if(a == 0){
            L1.P[1] = L2.P[1] = -c/double(b);
            L1.P[0] = 1;
            L2.P[0] = 2;
        }
        if(b == 0){
            L1.P[0] = L2.P[0] = -c/double(a);
            L1.P[1] = 1;
            L2.P[1] = 2;
        }
        if(a!=0 && b!=0){
            if(c != 0){
            L1.P[0] = -c/double(a);L1.P[1] = 0;
            L2.P[0] = 0; L2.P[1] = -c/double(b);
            }else{
            L1.P[0] = -c/double(a)-b;L1.P[1] = 1;
            L2.P[0] = 0; L2.P[1] = -c/double(b);
            }
        }
        res += (ccw(L1, L2, P1) != ccw(L1, L2, P2));
    }
    printf("%d\n",res);
}
