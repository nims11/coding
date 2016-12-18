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
const double pi = acos(-1);
int main()
{
    int a,b,s,m,n;
    while(1)
    {
        cin>>a>>b>>s>>m>>n;
        if(a==0)
            return 0;
        double h_vel = (m*double(a))/s;
        double v_vel = (n*double(b))/s;
        double vel = sqrt(h_vel*h_vel+v_vel*v_vel);
        double angle = asin(v_vel/vel) * 180/pi;
        printf("%.2lf %.2lf\n", angle, vel);
    }
}
