#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<utility>
#include<sstream>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>

#define CLASS Satellites
#define METHOD vector <int> detectable(vector <string> rockets, vector <string> satellites)

using namespace std;
template <class T>
class POINT3
{
    public:
    T P[3];
    POINT3(){};
    POINT3(T x, T y, T z){P[0] = x, P[1] = y, P[2] = z;}
    //dot
    T operator*(const POINT3 &a)
    {
        return a.P[0]*this->P[0] + a.P[1]*this->P[1] + a.P[2]*this->P[2];
    }
    POINT3 operator-(const POINT3 &b)
    {
        return POINT3(this->P[0] - b.P[0], this->P[1] - b.P[1], this->P[2] - b.P[2]);
    }
    //cross
    POINT3 operator^(const POINT3 &b)
    {
        return POINT3(this->P[1]*b.P[2] - b.P[1]*this->P[2],
                     b.P[0]*this->P[2] - this->P[0]*b.P[1],
                     this->P[0]*b.P[1] - b.P[0]*this->P[1]);
    }
    T norm()
    {
        return sqrt(P[0]*P[0] + P[1]*P[1] + P[2]*P[2]);
    }
    T norm2()
    {
        return norm()*norm();
    }
};
template <class T>
double dist(const POINT3<T> &a, const POINT3<T> &b)
{
    T d1 = a.P[0]-b.P[0];
    T d2 = a.P[1]-b.P[1];
    T d3 = a.P[2]-b.P[2];
    return sqrt(d1*d1 + d2*d2 + d3*d3);
}
const double PI = acos(-1);
class CLASS
{
    public:
    double earth_rad, r_alti, milli;
    CLASS():earth_rad(6400), r_alti(6800), milli(0.000001){}
    bool foo(POINT3<double> &r, POINT3<double> &s)
    {
        if(r.norm2()+(s-r).norm2()<=s.norm2())return true;
        return false;
    }
    METHOD
    {
        vector<POINT3<double> > r;
        vector<POINT3<double> > s;
        double lati, longi, alti;
        for(int i=0;i<rockets.size();i++)
        {
            stringstream ss(rockets[i]);
            ss>>lati>>longi;
            lati = lati*PI/180;
            longi = longi*PI/180;

            r.push_back(POINT3<double>(6800*cos(lati)*sin(longi),
                              6800*cos(lati)*cos(longi),
                              6800*sin(lati)));
        }
        for(int i=0;i<satellites.size();i++)
        {
            stringstream ss(satellites[i]);
            ss>>lati>>longi>>alti;
            alti += 6400;
            lati = lati*PI/180;
            longi = longi*PI/180;
            s.push_back(POINT3<double>(alti*cos(lati)*sin(longi),
                              alti*cos(lati)*cos(longi),
                              alti*sin(lati)));
        }
        vector <int> ret;
        for(int i=0;i<rockets.size();i++)
        {
            int cnt = 0;
            double R = r[i].norm2();
            for(int j=0;j<satellites.size() && cnt<3;j++)
            {
                if((r[i]-s[j]).norm()<=0){cnt++;continue;}
                double dist = ((r[i]^s[j]).norm())/(r[i]-s[j]).norm();
                if(foo(r[i], s[j])) dist = r[i].norm();
                if(foo(s[j], r[i])) dist = s[j].norm();
                if(dist>=6400+milli)cnt++;

//                double S = s[j].norm2();
//                double R_S = (s[j]-r[i]).norm2();
//                if((r[i]-s[j]).norm()<=0){cnt++;continue;}
//
//                if(R+R_S<=S || S+R_S<=R)
//                    cnt++;
//                else
//                {
//                    double dist = ((r[i])^s[j]).norm()/(s[j]-r[i]).norm();
//                    if(dist>=earth_rad)cnt++;
//                }
            }
            if(cnt==3)
                ret.push_back(i);
        }
        return ret;
    }
};

int main()
{
    string arr1[] = {"-0050.000 +0045.000","+0040.000 -0135.000"};
    string arr2[] = {"+0090.000 +0000.000 +1200.000",
 "-0090.000 +0000.000 +1200.000",
 "+0000.000 +0000.000 +1200.000",
 "+0000.000 -0090.000 +1200.000",
 "+0000.000 +0180.000 +1200.000",
 "-0000.000 -0045.000 +1200.000",
 "-0000.000 -0135.000 +1000.000",
 "-0011.000 -0136.000 +1086.828"};
    vector<string> a,b;
    for(int i=0;i<2;i++)
        {a.push_back(arr1[i]);}

    for(int i=0;i<8;i++)
        {b.push_back(arr2[i]);}
    CLASS test;
    cout<<test.detectable(a,b).size()<<endl;
}
