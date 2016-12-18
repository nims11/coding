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
template <class T>
vector<int> convex_hull(POINT<T> points[],int n)
{
    points[0].P[0]=20000;
    points[0].P[1]=20000;
    bool used[n+1];
    for(int i=1;i<=n;i++)   used[i]=false;
    int bot_left=0;
    vector<int> pos;
    for(int i=1;i<=n;i++){
        if(points[bot_left].P[1]>points[i].P[1])
            bot_left = i;
        else if(points[bot_left].P[1]==points[i].P[1] && points[bot_left].P[0]>points[i].P[0])
            bot_left = i;
    }
    pos.push_back(bot_left);
    int start = bot_left;
    do{
        int n2=-1;
        int dis = 0;
        for(int i=1;i<=n;i++){
            if(i==bot_left)continue;
            if(used[i])continue;
            if(n2==-1)n2=i;
            T cross = (points[i]-points[bot_left])^(points[n2]-points[bot_left]);
            T d = (points[i]-points[bot_left])*(points[i]-points[bot_left]);
            if(cross>0)n2=i,dis=d;
            else if(cross==0)
                if(d>dis)dis=d,n2=i;
        }
        bot_left = n2;
        used[n2]=true;
        pos.push_back(n2);
    }while(start!=bot_left);
    return pos;
}
// Distance of line b-c from point a
int linedist(POINT<int> &a, POINT<int> &b, POINT<int> &c)
{
    int dot1 = (b-a)*(c-b);
    if(dot1>0)return 1;
    int dot2 = (a-b)*(c-a);
    if(dot2>0)return 1;
    return (b-a)^(c-a);
}
// sign of ba x ca
int ccw(POINT<int> a, POINT<int> b, POINT<int> c)
{
    long long foo = ((b-a)^(c-a));
    return foo > 0?1:(foo<0?-1:0);
}
// If a-b intersects with c-d
bool intersect(POINT<int> a, POINT<int> b, POINT<int> c, POINT<int> d)
{
    if(ccw(a,b,c) == 0 && ccw(a,b,d) == 0){
        if((((b-a)*(c-b))>0 && ((b-a)*(d-b))>0) || (((a-b)*(c-a))>0 && ((a-b)*(d-a))>0))
            return false;
        else
            return true;
    }
    return ccw(a,c,d) != ccw(b,c,d) && ccw(a,b,c) != ccw(a,b,d);
}
// Number of points from points1[] at which a-points2[b] intersects.
int getans(POINT<int> &a, int b, POINT<int> points1[], POINT<int> points2[], vector<int> &points)
{
    int cnt = 0;
    for(int i=0;i<-1+points.size();i++)
        if(intersect(a, points2[b], points1[points[i]], points1[points[i+1]]))
            cnt++;
    return cnt;
}
// if pt (in points2) is inside the polygon denoted by pts (in points1)
bool is_inside(vector<int> &pts, int pt, POINT<int> points1[], POINT<int> points2[], int xmin, int xmax, int ymin, int ymax)
{
    if(points2[pt].P[0]<xmin || points2[pt].P[0]>xmax || points2[pt].P[1]<ymin || points2[pt].P[1]>ymax)
        return false;
    POINT<int> coord;
    for(int i=0;i<pts.size()-1;i++)
        if(linedist(points1[pts[i]], points1[pts[i+1]], points2[pt]) == 0)
            return true;
    while(1){
        POINT<int> candi;
        candi.P[0] = rand()%200000 + 200000;
        candi.P[1] = rand()%200000 + 200000;
        bool flag = true;
        for(int i=0;i<pts.size()-1;i++){
            if(linedist(candi, points2[pt], points1[pts[i]])==0){
                flag = false;
                break;
            }
        }
        if(!flag)continue;
        return getans(candi, pt, points1, points2, pts)%2;
    }
}
int main()
{

}
