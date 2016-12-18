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
class TVTower
{
    public:
    double dist(pair<double, double> coord1, pair<double, double> coord2)
    {
        double d1 = coord1.first-coord2.first;
        double d2 = coord1.second-coord2.second;
        return sqrt(d1*d1 + d2*d2);
    }
    int sqr(int x){return x*x;}
    double rad(pair<int,int> coord1,pair<int,int> coord2,pair<int,int> coord3, vector<int> &xx, vector<int> &yy)
    {
        double A1 = coord1.first - coord2.first,
            B1 = coord1.second - coord2.second,
            A2 = coord2.first - coord3.first,
            B2 = coord2.second - coord3.second;
        double C1 = A1*(coord1.first+coord2.first)/2.0 + B1*(coord1.second+coord2.second)/2.0,
            C2 = A2*(coord2.first+coord3.first)/2.0 + B2*(coord2.second+coord3.second)/2.0;
        double det = A1*B2 - A2*B1;
        if(det==0)return 1<<29;
        double x = (B2*C1 - B1*C2)/det;
        double y = (A1*C2 - A2*C1)/det;
//        cout<<det<<" "<<x<<" "<<y<<endl;
        double ret = 0;
        for(int i=0;i<xx.size();i++)
        {
            ret = max(ret,dist(make_pair(x,y),make_pair(xx[i],yy[i])));
        }
        return ret;
    }
    double minRadius(vector <int> x, vector <int> y)
    {
        double ans = 1<<29;
        if(x.size()==1)return 0;
        for(int i=0;i<x.size();i++)
        {
            for(int j=i+1;j<x.size();j++)
            {
                double x1 = (x[i]+x[j])/2.0;
                double y1 = (y[i]+y[j])/2.0;
                double foo = 0;
                for(int k=0;k<x.size();k++)
                {
                    foo = max(foo, dist(make_pair(x1,y1), make_pair(x[k],y[k])));
                }
                ans = min(ans, foo);
                for(int k=j+1;k<x.size();k++)
                {
                    ans = min(ans, rad(make_pair(x[i],y[i]), make_pair(x[j],y[j]), make_pair(x[k],y[k]),x,y));
//                    cout<<ans<<" "<<i<<" "<<j<<" "<<k<<endl;
                }
            }
        }
        return ans;
    }
};
int main()
{
    int x[] = {5, -3, -4};
    int y[] = {0, 4, -3};
    vector<int> xx,yy;
    for(int i=0;i<sizeof(x)/sizeof(int);i++)
    xx.push_back(x[i]), yy.push_back(y[i]);
    TVTower test;
    cout<<test.minRadius(xx,yy);
}
