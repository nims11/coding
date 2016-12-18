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
#include<cmath>
#include<stack>
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
int y_1, y2, yw, xb, yb, r;
void getans(double start, double end)
{
    if(end-start<0.000000001)
        {cout<<-1<<endl;return;}
    double y_p = (start+end)/2;
    double xw = xb*(yw-y_p)/(2*yw-y_p-yb);
    double m = 1/(tan(xw/(yw-y_p)));
    double dist = abs(y2-y_p)/sqrt(m*m-1);
    if(dist>r)
    printf("%.10lf\n", xw);
    else
    getans(y_1, y_p);
}
int main()
{
    cin>>y_1>>y2>>yw>>xb>>yb>>r;
    yw -= r;
    y_1+=r;
    if(y_1>=y2-r)
    cout<<-1<<endl;
    else
    getans(y_1, y2);
}
