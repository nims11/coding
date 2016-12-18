/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;
#define P_I(a) printf("%d",a)

using namespace std;
struct point
{
    int x,y;
};
point points[2000],pivot;
bool operator<(const point &a,const point &b)
{
    return (pivot.y-a.y)*(pivot.x-b.x) < (pivot.y-b.y)*(pivot.x-a.x);
}
vector <point> convex_hull;
int n;
int getdir(point a,point b,point c)
{
    double m=(double(0)-a.y)*(b.x-a.x) - (double(0)-a.y)*(c.x-a.y);
    double eq=(double(c.y)-a.y)*(b.x-a.x) - (double(b.y)-a.y)*(c.x-a.x);
    //if(m>0)eq=-eq;
    if(eq<0)return 1;
    else return -1;
}
int main()
{
    in_T
    {
        convex_hull.clear();
        in_I(n);
        int max=0,maxi;
        for(int i=0;i<n;i++)
        {
            in_I(points[i].x);
            in_I(points[i].y);
            if(points[i].y>max)
            {
                max=points[i].y;
                maxi=i;
            }
        }
        pivot=points[maxi];
        sort(points,points+n);
        convex_hull.push_back(pivot);
        convex_hull.push_back(points[0]);
        cout<<"pivot: "<<pivot.x<<" "<<pivot.y<<endl;
        for(int i=0;i<n;i++)
        cout<<points[i].x<<" "<<points[i].y<<endl;
        int curr=1;
        while(curr<n)
        {
            if(points[curr].x==pivot.x && points[curr].y==pivot.y){curr++;break;}

            int dir=getdir(convex_hull[convex_hull.size()-1],convex_hull[convex_hull.size()-2],points[curr]);
            if(dir==1)
            {
                convex_hull.push_back(points[curr++]);
            }else
            {
                do
                {
                    convex_hull.pop_back();
                }while(getdir(convex_hull[convex_hull.size()-1],convex_hull[convex_hull.size()-2],points[curr])!=1);
            }
        }
        for(int i=0;i<convex_hull.size();i++)
        cout<<convex_hull[i].x<<" - "<<convex_hull[i].y<<"   ";
        cout<<endl;
    }
}
