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
class POINT
{
    public:
    int P[2];
};

POINT operator-(const POINT &a,const POINT &b)
{
    POINT foo;
    foo.P[0] = a.P[0] - b.P[0];
    foo.P[1] = a.P[1] - b.P[1];
    return foo;
}

//dot
int operator*(const POINT &a,const POINT &b)
{
    return a.P[0]*b.P[0] + a.P[1]*b.P[1];
}

//cross
int operator^(const POINT &a, const POINT &b)
{
    return a.P[0]*b.P[1] - a.P[1]*b.P[0];
}

double dist(const POINT &a, const POINT &b)
{
    int d1 = a.P[0]-b.P[0];
    int d2 = a.P[1]-b.P[1];
    return sqrt(d1*d1 + d2*d2);
}
double linedist(POINT &a, POINT &b, POINT &c)
{
    double d = ((b-a)^(c-a))/dist(a,b);
    int dot1 = (b-a)*(c-b);
    if(dot1>0)return 1;
    int dot2 = (a-b)*(c-a);
    if(dot2>0)return 1;
    return d;
}
class PointInPolygon
{
    public:
    int getans(POINT a, POINT b, vector<POINT> &points)
    {
        int cnt = 0;
        double mab = double(b.P[1]-a.P[1])/(b.P[0]-a.P[0]);
//        cout<<a.P[0]<<" "<<a.P[1]<<endl;
//        cout<<b.P[0]<<" "<<b.P[1]<<endl;
//        cout<<" "<<mab<<endl;
        for(int i=0;i<points.size();i++)
        {
            int j = (i+1)%points.size();
            if(points[i].P[0] == points[j].P[0])
            {
                double y = mab*(points[i].P[0]-a.P[0]) + a.P[1];
//                cout<<"y = "<<y<<endl;
                if(y>min(points[i].P[1],points[j].P[1]) && y<max(points[i].P[1],points[j].P[1]) && y>min(a.P[1],b.P[1]) && y<max(a.P[1], b.P[1]))
                    cnt++;
            }else
            {
                double x = (points[i].P[1] - a.P[1])/mab + a.P[0];
//                cout<<"x = "<<x<<endl;
                if(x>min(points[i].P[0],points[j].P[0]) && x<max(points[i].P[0],points[j].P[0]) && x>min(a.P[0],b.P[0]) && x<max(a.P[0], b.P[0]))
                    cnt++;
            }
        }
//        cout<<cnt<<endl;
        return cnt;
    }
    string testPoint(vector <string> vertices, int testPointX, int testPointY)
    {
        vector <POINT>points(vertices.size());
        POINT test = {{testPointX, testPointY}};
        for(int i=0;i<vertices.size();i++)
        {
            points[i].P[0] = points[i].P[1] = 0;
            int j=0;
            bool flag = false;
            if(vertices[i][j]=='-')flag=true,j++;
            while(vertices[i][j]!=' ')
            {
                points[i].P[0] = points[i].P[0] * 10 + vertices[i][j] - '0';
                j++;
            }
            if(flag) points[i].P[0] *=-1;
            j++;
            flag = false;
            if(vertices[i][j]=='-')flag=true,j++;
            while(vertices[i][j]!=0)
            {
                points[i].P[1] = points[i].P[1] * 10 + vertices[i][j] - '0';
                j++;
            }
            if(flag) points[i].P[1] *=-1;
        }
        for(int i=0;i<vertices.size();i++)
        {
            if(linedist(points[i], points[(i+1)%vertices.size()], test) == 0)
            {
                return "BOUNDARY";
            }
        }
        POINT candi;
        int ext=0,inte=0;
        for(int i=0;i<5;i++)
        {
            candi.P[0] = rand()%1000+1000;
            candi.P[1] = rand()%1000+1000;
            if(getans(candi, test, points)%2)
                inte++;
            else ext++;
        }
        if(inte>ext)
        return "INTERIOR";
        else
        return "EXTERIOR";
    }
};
int main()
{
    cout<<rand()<<endl;
    string str[45] = {"500 0", "500 100", "400 100", "400 200", "300 200", "300 300", "200 300", "200 400", "100 400", "100 500", "0 500", "0 400", "-100 400", "-100 300", "-200 300", "-200 200", "-300 200", "-300 100", "-400 100", "-400 0", "-500 0", "-500 -100", "-400 -100", "-400 -200", "-300 -200", "-300 -300", "-200 -300", "-200 -400", "-100 -400", "-100 -500", "0 -500", "0 -400", "100 -400", "100 -300", "200 -300", "200 -200", "300 -200", "300 -100", "400 -100", "400 0"};
    vector<string> ss;
    for(int i=0;i<45;i++)
    ss.push_back(str[i]);
    PointInPolygon test;
    cout<<test.testPoint(ss,400,-400);
}
