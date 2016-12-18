/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
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
#define point pair<double,double>
#include<cmath>
using namespace std;
double pi = acos(-1);
point getCC(point x,point y,point z)
{
    point mid_pt1 = make_pair((x.first+y.first)/2,(x.second+y.second)/2);
    point mid_pt2 = make_pair((x.first+z.first)/2,(x.second+z.second)/2);
    double m1 = -(y.first-x.first)/(y.second-x.second);
    double m2 = -(z.first-x.first)/(z.second-x.second);

    double foo = (m2*mid_pt2.first + mid_pt1.second - m1*mid_pt1.first - mid_pt2.second)/(m2-m1);
    double bar = (m1*foo - m1*mid_pt1.first + mid_pt2.second);

//    cout<<foo<<" "<<bar<<endl;
//    cout<<mid_pt1.first<<" "<<mid_pt1.second<<endl;
//    cout<<mid_pt2.first<<" "<<mid_pt2.second<<endl;
    return make_pair(foo,bar);
}
int main()
{
    point pt1,pt2,pt3;
    char str[100];
    while(1)
    {
        scanf("%s",str);
        if(str[0]=='E')return 0;
        pt1.first = atof(str);
        scanf("%lf %lf %lf %lf %lf",&pt1.second,&pt2.first,&pt2.second,&pt3.first,&pt3.second);
//        cout<<pt1.first<<" "<<pt1.second<<endl;
//        cout<<pt2.first<<" "<<pt2.second<<endl;
//        cout<<pt3.first<<" "<<pt3.second<<endl;
        point circum_centre = getCC(pt1,pt2,pt3);
        double ang1,ang2,ang3;
        double m1 = (pt1.first==circum_centre.first)?pi/2:atan(((pt1.second-circum_centre.second)/(pt1.first-circum_centre.first)));
        double m2 = (circum_centre.first==pt3.first)?pi/2:atan(((circum_centre.second-pt3.second)/(circum_centre.first-pt3.first)));
        double m3 = (circum_centre.first==pt2.first)?pi/2:atan(((circum_centre.second-pt2.second)/(circum_centre.first-pt2.first)));


        cout<<m1<<" "<<m2<<" "<<m3<<endl;

        ang1 = fabs(m1-m2);
        ang2 = fabs(m2-m3);
        ang3 = fabs(m1-m3);

        cout<<ang1<<" "<<ang2<<" "<<ang3<<endl;
        for(int i=3;i<=1000;i++)
        {
            double x = (2*pi)/i;
            double foo = ang1/x,bar = ang2/x, quz = ang3/x;
            if(ceil(foo)==foo && ceil(bar)==bar && ceil(quz)==quz)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
}
