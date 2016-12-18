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
double getFl(){
    double X;
    in_F(X);
    return X;
    int x, y;
    scanf("%d.%d", &x, &y);
    double ret = y;
    while(y>0)
        ret/=10, y/=10;
    ret += x;
    return ret;
}
int main()
{
    int z = 0;
    in_T{
        z++;
        double C, F, X;
        C = getFl(); F = getFl(); X = getFl();
        double ans;
        double cur = 0, rate = 2, prev = 0;
        while(1){
            double buy, moon;
            moon = prev + X/rate;
            buy = prev + C/rate + (X/(rate+F));
//            cout<<moon<<" "<<buy<<endl;
            if(buy<moon){
                prev += C/rate;
                rate += F;
            }else{
                ans = moon;
                break;
            }
        }
        cout<<"Case #"<<z<<": ";
        printf("%.7lf\n", ans);
    }
}
