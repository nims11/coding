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

int GCD(int a,int b)
{
    while(b^=a^=b^=a%=b);
    return a;
}
bool cur(int x, int y){
    int xx[2], yy[2];
    xx[0] = x%10;
    xx[1] = x/10;
    yy[0] = y%10;
    yy[1] = y/10;
    sort(xx, xx+2);
    sort(yy, yy+2);
    if(xx[0] == yy[0] && xx[1] == yy[1])
        return false;
    if(xx[0] == yy[0] && x*yy[1] == y*xx[1])
        return true;
    if(xx[1] == yy[1] && x*yy[0] == y*xx[0])
        return true;
    return false;

}
int main()
{
    int res = 0;
    int num, den;
    num = den = 1;
    for(int i = 11;i<=99;i++){
        for(int j = i+1;j<=99;j++){
            if(i%10 == 0 || j%10 == 0)
                continue;
            if(cur(i, j)){
                res++;
                cout<<i<<" "<<j<<endl;
                num *= i;
                den *= j;
            }
        }
    }
    cout<<num<<" "<<den<<endl;
    cout<<den/GCD(num, den)<<endl;
}
